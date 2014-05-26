#ifndef VIEWMODEL_APPLICATION_HPP
#define VIEWMODEL_APPLICATION_HPP

#include "ui/Observable.hpp"
#include "bridge/Player.hpp"
#include "ui/text/PlayerUI.hpp"
#include "ui/text/Game.hpp"
#include "bridge/Game.hpp"
#include "Bot.hpp"

namespace viewmodel {

class Application : public ui::Observable<Application>
{
public:
	void run() 
	{	
		std::array<std::unique_ptr<bridge::IPlayer>,4> players{ { std::unique_ptr<bridge::IPlayer>(new ui::text::PlayerUI()),std::unique_ptr<bridge::IPlayer>(new Bot()),std::unique_ptr<bridge::IPlayer>(new Bot()),std::unique_ptr<bridge::IPlayer>(new Bot()) } };
		game = new bridge::Game(players);
		game->sigModified.connect([this](bridge::Game const & game) {
					this->gameView.registerDeal(game);
				});
		sigModified(*this);
		game->start();
	}
private:
	bridge::Game* game; 
	ui::text::Game gameView;
};

}
#endif

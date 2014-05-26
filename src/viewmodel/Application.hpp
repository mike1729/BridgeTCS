#ifndef VIEWMODEL_APPLICATION_HPP
#define VIEWMODEL_APPLICATION_HPP

#include "ui/Observable.hpp"
#include "bridge/Player.hpp"
#include "ui/text/PlayerUI.hpp"
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
		game->start();
		sigModified(*this);
	}
private:
	bridge::Game* game; 
};

}
#endif

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
	void runApplication() 
	{	
		std::array<std::unique_ptr<bridge::IPlayer>,4> players{ {
				std::unique_ptr<bridge::IPlayer>(new ui::text::PlayerUI()),
				std::unique_ptr<bridge::IPlayer>(new Bot()),
				std::unique_ptr<bridge::IPlayer>(new Bot()),
				std::unique_ptr<bridge::IPlayer>(new Bot()) }};
        bridge::Game game(players);
		pgame = &game;
		id=0;
		sigModified(*this);
		pgame->start();
		pgame = nullptr;
	}
	const bridge::Game & getGame() const { return *pgame; };
	bridge::PlayerID getId() const { return id; };
private:
	bridge::Game * pgame;
	bridge::PlayerID id;
};

}
#endif

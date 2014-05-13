#ifndef MODEL_GAME_HPP
#define MODEL_GAME_HPP

#include <array>
#include <memory>

#include "Player.hpp"
#include "Arbiter.hpp"

namespace model {

class Game
{
public:
	Game(std::array<std::unique_ptr<IPlayer>,4> & players) : players(players),
		arbiters{{{hands[0], *players[0].get()}, {hands[1], *players[1].get()},
		{hands[2], *players[2].get()}, {hands[3], *players[3].get()}}} {}
	void start();
private:
	std::array<std::unique_ptr<IPlayer>,4> const & players;
	std::array<Hand,4> hands;
	std::array<Arbiter,4> arbiters;
};

}
#endif

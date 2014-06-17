#ifndef BRIDGE_GAME_HPP
#define BRIDGE_GAME_HPP

#include <array>
#include <memory>

#include "Player.hpp"
#include "Arbiter.hpp"
#include "Deal.hpp"
#include "Scorer.hpp"

namespace bridge {

class Game: public ui::Observable<Game>
{
public:
	Game(std::array<std::unique_ptr<IPlayer>,4> & players) : players(players) { }
	
	void start();
	
	const Deal& getDeal() const
	{
		return *deal;
	};
	
	const DealResult& getResult() const
	{
		return result; }
	}
	
	const Scorer& getScorer() const
	{
		return scorer;
	}

private:
	std::array<std::unique_ptr<IPlayer>,4> const & players;
	std::unique_ptr<Deal> deal;
	DealResult result;
	Scorer scorer;
};

} //namespace bridge
#endif

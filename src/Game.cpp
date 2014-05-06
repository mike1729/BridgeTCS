#include "Game.hpp"
#include "Deal.hpp"

void Game::start()
{
	Deal deal(arbiters, hands, 0);
	Contract contract = deal.performBidding();
	deal.performPlay();
	//TODO: Handle scores and repeat deals
}

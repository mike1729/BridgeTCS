#include "Game.hpp"
#include "Deal.hpp"

namespace bridge {

void Game::start()
{
	Deal deal(arbiters, hands, 0);
	Contract contract = deal.performBidding();
	deal.performPlay();
	//TODO: Handle scores and repeat deals
}

}

#include "Game.hpp"
#include "Deal.hpp"

namespace bridge {

void Game::start()
{
	deal = new Deal(arbiters, hands, 0);
	sigModified(*this);
	Contract contract = deal->performBidding();
	deal->performPlay();
	//TODO: Handle scores and repeat deals
}

}

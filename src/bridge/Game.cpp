#include "Game.hpp"
#include "Deal.hpp"

namespace bridge {

void Game::start()
{
	Contract contract;
	do {
		deal.reset( new Deal(players, 0) );
		sigModified(*this);
		deal->dealCards();
		contract = deal->performBidding();
	} while ( contract.redeal ) ;
	deal->performPlay();
	//TODO: Handle scores and repeat deals
}

}

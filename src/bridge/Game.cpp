#include "Game.hpp"
#include "Deal.hpp"
namespace bridge {

void Game::start()
{	
	while (!scorer.gameOver()) {
		Contract contract;
		
		do {
			deal.reset( new Deal(players, 0) );
			sigModified(*this);
			deal->dealCards();
			contract = deal->performBidding();
		} while ( contract.redeal ) ;
		
		result = deal->performPlay();
		scorer.update(result);
		sigModified(*this);
	}
}

}

#include "Deal.hpp"
#include "bridge/Contract.hpp"
#include <iostream>

namespace ui 
{
namespace text 
{

void Deal::notify(const bridge::Deal & deal)
{
	std::cout << "\n\nFrom now on it's not probably your fault :)\n\n";
	bridge::DealEvent event = deal.event;
	switch(event)
	{
		case bridge::DealEvent::BiddingStart:
		
			std::cout << "Player " << deal.getFirstCaller() << "starts bidding.\n";
			const bridge::Bidding & bidding = deal.getBidding();
			bidding.sigModified.connect([this](Bidding const & bidding) {
				this->biddingView.notify(bidding);
			});
			break;
		
		case bridge::DealEvent::BiddingEnd:
		
			Contract contract = deal.getBidding().getContract();
			std::cout << "Bidding finished. The contract is " << contract.level << " " << contact.denomination << " declared by player " << constract.declarer << ".\n";
			break;
			
		case bridge::DealEvent::PlayStart:
		
			const bridge::Play & play = deal.getPlay();
			play.sigModified.connect([this](Play const & play) {
				this->playView.registerTrick(play);
			play.sigModified(play);
			break;

}*/

} // namespace text
} // namespace ui

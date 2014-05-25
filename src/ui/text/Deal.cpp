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
	bridge::DealEvent event = deal.getEvent();
	switch(event)
	{
		case bridge::DealEvent::BiddingStart:
		
			{
				const bridge::Bidding & bidding = deal.getBidding();
				std::cout << "Player " << bidding.getFirstCaller() << "starts bidding.\n";
				bidding.sigModified.connect([this](bridge::Bidding const & bidding) {
					this->biddingView.print(bidding);
				});
			}
			break;
		
		case bridge::DealEvent::BiddingEnd:
		
			{
				bridge::Contract contract = deal.getValidatedContract();
				std::cout << "Bidding finished. The contract is " << contract.level << " ";
				Printer::print(contract.denomination);
				std::cout << " declared by player " << contract.declarer << ".\n";
			}
			break;
			
		case bridge::DealEvent::PlayStart:
		
			{
				const bridge::Play & play = deal.getPlay();
				play.sigModified.connect([this](bridge::Play const & play) {
					this->playView.registerTrick(play);
				});
				play.sigModified(play);
			}
			break;

		default:
			break;
	}

}
} // namespace text
} // namespace ui

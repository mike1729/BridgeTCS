#include "Deal.hpp"
#include "bridge/Contract.hpp"
#include <iostream>

namespace ui 
{
namespace text 
{

void Deal::notify(const bridge::Deal & deal)
{
	bridge::DealEvent event = deal.getEvent();
	switch(event)
	{
		case bridge::DealEvent::CardsDealt:
			{
				bridge::Hands const & hands = deal.getHands();	      
				hands[id].sigModified.connect([this](bridge::Hand const & hand) {
					this->handView.print(hand);
				});
			}
			break;
			
		case bridge::DealEvent::BiddingStart:
		
			{
				const bridge::Bidding & bidding = deal.getBidding();
				std::cout << "Player " << bidding.getFirstCaller() + 1 << " starts bidding.\n";
				bidding.sigModified.connect([this](bridge::Bidding const & bidding) {
					this->biddingView.print(bidding);
				});
			}
			break;
		
		case bridge::DealEvent::BiddingEnd:
		
			{
				bridge::Contract contract = deal.getContract();
				if ( contract.redeal )
				{
					std::cout << "Bidding finished. Since there were four passes the cards shall be redealt." << std::endl;
				} else
				{
					std::cout << "Bidding finished. The contract is " << contract.level << " ";
					Printer::print(contract.denomination);
					std::cout << "  declared by player " << contract.declarer + 1 << ".\n";
					bridge::Hands const & hands = deal.getHands();	      
					hands[(contract.declarer+2)%4].sigModified.connect([this](bridge::Hand const & hand) {
						this->handView.print(hand);
					});
				}
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

		case bridge::DealEvent::PlayEnd:
			bridge::DealResult result = deal.getResult();
			int extra = result.declarerTakenTricks >= result.contract.level + 6;
			if(extra >= 0)
				std::cout << "Contract accomplished. " <<  extra << " overtricks.\n";
			else
				std::cout << "Contract failed. " <<  extra << " undertricks.\n";
				
			break;
	}

}
} // namespace text
} // namespace ui

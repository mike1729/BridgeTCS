#include "Deal.hpp"
#include "Deck.hpp"

namespace bridge 
{

void Deal::dealCards()
{
	Standard52Deck deck;
	deck.shuffle();
	for (int currentPlayer = firstCaller; deck.cardsLeft(); currentPlayer = (currentPlayer+1) % 4)
		hands[currentPlayer].insert(deck.dealCard());
	for (int i = 0; i < 4; i++)
		hands[i].sort();
	event = DealEvent::CardsDealt;
	sigModified(*this);
}

Contract Deal::performBidding() 
{
	bidding.reset(new Bidding(firstCaller));
	event = DealEvent::BiddingStart;
	sigModified(*this);
	for (int currentCaller = firstCaller; !bidding->Done(); currentCaller = (currentCaller+1)%4)
	{
		Call currentCall = arbiters[currentCaller].getCall(*bidding, hands[currentCaller]);
		bidding->makeCall(currentCall);
	}
	contract = bidding->getContract();
	event = DealEvent::BiddingEnd;
	sigModified(*this);
	return contract;
}

DealResult Deal::performPlay()
{
	play.reset(new Play(contract.denomination, contract.declarer));
	result.contract = contract;
	event = DealEvent::PlayStart;
	sigModified(*this);
	int currentPlayer = contract.declarer;
	int dummyPlayer = (contract.declarer + 2) % 4;
	for (int i = 0; i < 4; i++)
		arbiters[i].setRole((i == dummyPlayer) ? Arbiter::Role::DUMMY : Arbiter::Role::NORMAL);
	arbiters[dummyPlayer].setPartnerHand(&hands[contract.declarer]);
	for (int trick = 0; trick < 13; trick++)
	{
		for (int i = 0; i < 4; i++)
		{
			play->add(arbiters[currentPlayer].getCard(*bidding, *play, hands[currentPlayer], hands[dummyPlayer]));
			currentPlayer = (currentPlayer+1)%4;
		}
		currentPlayer = play->getLastTrickWinner();
	}
	result.declarerTakenTricks = play->getTricksTaken();
	event = DealEvent::PlayEnd;
	sigModified(*this);
	return result;
};

} // namespace bridge

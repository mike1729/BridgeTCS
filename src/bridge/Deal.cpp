#include "Deal.hpp"
#include "Deck.hpp"

namespace bridge 
{

void Deal::dealCards()
{
	Standard52Deck deck;
	deck.shuffle();
	// deal cards to players
	for (int currentPlayer = firstCaller; deck.cardsLeft(); currentPlayer = (currentPlayer+1) % 4)
		hands[currentPlayer].insert(deck.dealCard());
	// sort players' hands
	for (int i = 0; i < 4; i++)
		hands[i].sort();
	// set current event status
	event = DealEvent::CardsDealt;
	sigModified(*this);
}

Contract Deal::performBidding() 
{
	bidding.reset(new Bidding(firstCaller));
	// set current event status
	event = DealEvent::BiddingStart;
	sigModified(*this);
	// perform bidding
	for (int currentCaller = firstCaller; !bidding->Done(); currentCaller = (currentCaller+1)%4)
	{
		Call currentCall = arbiters[currentCaller].getCall(*bidding, hands[currentCaller]);
		bidding->makeCall(currentCall);
	}
	// get final contract
	contract = bidding->getContract();
	// set current event state
	event = DealEvent::BiddingEnd;
	sigModified(*this);
	return contract;
}

DealResult Deal::performPlay()
{
	play.reset(new Play(contract.denomination, contract.declarer));
	// set final contract from bidding
	result.contract = contract;
	// set current event state
	event = DealEvent::PlayStart;
	sigModified(*this);
	int currentPlayer = contract.declarer;
	int dummyPlayer = (contract.declarer + 2) % 4;
	// set players roles
	for (int i = 0; i < 4; i++)
		arbiters[i].setRole((i == dummyPlayer) ? Arbiter::Role::DUMMY : Arbiter::Role::NORMAL);
	// associate dummy to her/his partner
	arbiters[dummyPlayer].setPartnerHand(&hands[contract.declarer]);

    // perform play
	for (int trick = 0; trick < 13; trick++)
	{
		for (int i = 0; i < 4; i++)
		{
			play->add(arbiters[currentPlayer].getCard(*bidding, *play, hands[currentPlayer], hands[dummyPlayer]));
			currentPlayer = (currentPlayer+1)%4;
		}
		currentPlayer = play->getLastTrickWinner();
	}
	// set taken tricks
	result.declarerTakenTricks = play->getTricksTaken();
	// set current event state
	event = DealEvent::PlayEnd;
	sigModified(*this);
	return result;
};

} // namespace bridge

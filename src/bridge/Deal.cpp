#include "Deal.hpp"
#include "Deck.hpp"

namespace bridge {

void Deal::dealCards()
{
	Standard52Deck deck;
	for (int currentPlayer = firstCaller; deck.cardsLeft(); currentPlayer = (currentPlayer+1) % 4)
	{
		hands[currentPlayer].insert(deck.dealCard());
		currentPlayer = (currentPlayer+1) % 4;
	}
	sigModified(*this, DealEvent::CardsDealt);
}

Contract Deal::performBidding() 
{
	bidding.reset(new Bidding(firstCaller));
	sigModified(*this, DealEvent::BiddingStart);
	for (int currentCaller = firstCaller; !bidding->Done(); currentCaller = (currentCaller+1)%4)
	{
		Call currentCall = arbiters[currentCaller].getCall(bidding);
		wasSuccessful = bidding->makeCall(currentCall);
	}
	contract = bidding->getContract();
	sigModified(*this, DealEvent::BiddingEnd);
	return contract;
}

DealResult Deal::performPlay()
{
	play.reset(new Play(contract.denomination, contract.declarer));
	result.contract = contract;
	sigModified(*this, DealEvent::PlayStart);
	int currentPlayer = contract.declarer;
	for (int trick = 0; trick < 13; trick++)
	{
	    Card firstCard = arbiters[currentPlayer].getCard();
	    play->add(firstCard);
		for (int i = 0; i < 3; i++)
		{
			currentPlayer = (currentPlayer+1)%4;
			play->add(arbiters[currentPlayer].getCard(firstCard.suit));
		}
		currentPlayer = play->getLastTrickWinner();
	}
	result.declarerTakenTricks = play->getTricksTaken();
	sigModified(*this, DealEvent::PlayEnd);
	return result;
};

}

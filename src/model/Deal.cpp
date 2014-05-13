#include "Deal.hpp"
#include "Deck.hpp"

namespace model {

void Deal::dealCards()
{
	Standard52Deck deck;
	int currentPlayer = firstCaller;
	while (deck.cardsLeft())
	{
		hands[currentPlayer].insert(deck.dealCard());
		currentPlayer = (currentPlayer+1) % 4;
	}
	sigModified(*this);
}

Contract Deal::performBidding() 
{
	bidding.reset(new Bidding(firstCaller));
	sigModified(*this);
	int currentCaller = firstCaller;
	while (!bidding->biddingDone())
	{
		bool wasSuccessful;
		do 
		{
			Call currentCall = arbiters[currentCaller].getCall();
			wasSuccessful = bidding->makeCall(currentCall);
		} 
		while (!wasSuccessful);
		currentCaller = (currentCaller+1)%4;
	}
	contract = bidding->getContract();
	sigModified(*this);
	return contract;
}

DealResult Deal::performPlay()
{
	play.reset(new Play(contract.denomination, contract.declarer));
	result.contract = contract;
	sigModified(*this);
	int currentPlayer = contract.declarer;
	for (int trick = 0; trick < 13; trick++)
	{
		for (int i = 0; i < 4; i++)
		{
			play->add(arbiters[currentPlayer].getCard());
			currentPlayer = (currentPlayer+1)%4;
		}
		currentPlayer = play->getLastTrickWinner();
	}
	result.declarerTakenTricks = play->getTricksTaken();
	sigModified(*this);
	return result;
};

}

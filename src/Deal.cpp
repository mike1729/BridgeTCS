#include "Deal.hpp"
#include "Deck.hpp"

void Deal::dealCards()
{
	Standard52Deck deck;
	for (int currentPlayer = firstCaller; deck.cardsLeft(); currentPlayer = (currentPlayer+1) % 4)
		hands[currentPlayer].insert(deck.dealCard());
	update();
}

Contract Deal::performBidding() 
{
	bidding.reset(new Bidding(firstCaller));
	update();
	while (int currentCaller = firstCaller; !bidding->Done(); currentCaller = (currentCaller+1)%4)
	{
		Call currentCall = arbiters[currentCaller].getCall();
		wasSuccessful = bidding->makeCall(currentCall);
	}
	contract = bidding->getContract();
	update();
	return contract;
}

DealResult Deal::performPlay()
{
	play.reset(new Play(contract.denomination, contract.declarer));
	result.contract = contract;
	update();
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
	update();
	return result;
};

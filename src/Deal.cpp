#include "Deal.hpp"
#include "Deck.hpp"

void Deal::dealCards()
{
	Standard52Deck deck;
	int currentPlayer = firstCaller;
	while (deck.cardsLeft())
	{
		hands[currentPlayer].insert(deck.dealCard());
		currentPlayer = (currentPlayer+1) % 4;
	}
	update();
}

Contract Deal::performBidding() 
{
	bidding.reset(new Bidding(firstCaller));
	update();
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

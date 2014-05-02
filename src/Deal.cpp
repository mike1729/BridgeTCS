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
}

Contract Deal::performBidding() 
{
	while (!bidding.biddingDone())
	{
		bool wasSuccessful;
		do 
		{
			Call currentCall = arbiters[currentCaller].getCall();
			wasSuccessful = bidding.makeCall(currentCall);
		} 
		while (!wasSuccessful);
		currentCaller = (currentCaller+1)%4;
	}
	contract = bidding.getContract();
	return contract;
}

dealResult Deal::performPlay()
{
	//write me tymorl!
	return dealResult();
};

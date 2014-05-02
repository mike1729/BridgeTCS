#include "Deal.hpp"

void dealCards()
{
	//TODO
}

void Deal::performBidding() 
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
}

dealResult Deal::performPlay()
{
	//tymorl napisz mnie, pliz
	return dealResult();
};

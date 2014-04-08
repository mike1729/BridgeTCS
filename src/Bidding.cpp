#include "Bidding.hpp"

Contract Bidding::perform() 
{
	while (!biddingState.biddingDone())
	{
		bool wasSuccessful;
		do 
		{
			Call currentCall = arbiters[currentCaller].getCall();
			wasSuccessful = biddingState.makeCall(currentCall);
		} 
		while (!wasSuccessful);
		currentCaller = (currentCaller+1)%4;
	}
	return biddingState.getContract();
}

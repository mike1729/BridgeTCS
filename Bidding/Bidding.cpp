#include "Bidding.hpp"

Bidding::Bidding() {
	currentContract.level = 0;
	currentContract.redeal = false;
	consectutivePasses = 0;
}

bool Bidding::makeCall(Call call)
{
	//TODO: validation of call.
	if ( call.type == CallType::Pass ) 
	{
		consectutivePasses++;
		if ( currentContract.level != 0 && consectutivePasses >= 3 )
		{
			//TODO: finalize the contract.
		}
		if ( consectutivePasses >= 4 ) {
			currentContract.redeal = true;
		}
	}
	return true;
}

Contract Bidding::getContract()
{
	return currentContract;
}

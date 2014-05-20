#include "Bidding.hpp"

namespace bridge {
/* ------------------------------------------------------------------------------------------------------------------------*
**                                            Bidding::makeCall(Call call)                                            *
** ------------------------------------------------------------------------------------------------------------------------*/
void Bidding::makeCall(Call call)
{
	switch ( call.type )
	{
		case CallType::BID :
			currentContract.level = call.level;
			currentContract.denomination = call.denomination;
			currentContract.pointMultiplier = 1;
			lastBidder = callNumber;
			break;
		case CallType::DOUBLE :
			currentContract.pointMultiplier = 2;
			break;
		case CallType::REDOUBLE :
			currentContract.pointMultiplier = 4;
			break;
		case CallType::PASS :
			if ( currentContract.level != 0 && consecutivePasses >= 3 )
			{
				isFinished = true;
			}
			if ( consecutivePasses >= 4 )
			{
				currentContract.redeal = true;
				isFinished = true;
			}
			break;
	}
	sigModified(*this);
	
	callNumber++;
	history.push_back(call);
	return true;
	
}

/* ------------------------------------------------------------------------------------------------------------------------*
**                                            Bidding::findDeclarer                                                   *
** ------------------------------------------------------------------------------------------------------------------------*/
void Bidding::findDeclarer() 
{
	int declarer;
	for (declarer = lastBidder%2 ; declarer<callNumber ; declarer += 2) 
		if (history[declarer].denomination == currentContract.denomination)
			break;

	currentContract.declarer = (declarer+firstCaller)%4;
}

}

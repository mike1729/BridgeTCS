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
			consecutivePasses = 0;
			currentContract.level = call.level;
			currentContract.denomination = call.denomination;
			currentContract.pointMultiplier = 1;
			lastBidder = history.size();
			break;
		case CallType::DOUBLE :
			consecutivePasses = 0;
			currentContract.pointMultiplier = 2;
			break;
		case CallType::REDOUBLE :
			consecutivePasses = 0;
			currentContract.pointMultiplier = 4;
			break;
		case CallType::PASS :
			consecutivePasses++;
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
	history.push_back(call);
	findDeclarer();
	sigModified(*this);
}

/* ------------------------------------------------------------------------------------------------------------------------*
**                                            Bidding::findDeclarer                                                   *
** ------------------------------------------------------------------------------------------------------------------------*/
void Bidding::findDeclarer()
{
	int declarer;
	for (declarer = lastBidder%2 ; declarer<history.size() ; declarer += 2) 
		if (history[declarer].type == CallType::BID && history[declarer].denomination == currentContract.denomination)
			break;
	}
	currentContract.declarer = (declarer+firstCaller)%4;
}

}

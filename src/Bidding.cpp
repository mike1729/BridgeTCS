#include "Bidding.hpp"

/* ------------------------------------------------------------------------------------------------------------------------*
**                             operator <=( const Denomination &d1, const Denomination &d2 )                               *
** ------------------------------------------------------------------------------------------------------------------------*/
bool operator <=( const Denomination &d1, const Denomination &d2 )
{
	if ( d2 == Denomination::NT )
	{
		return true;
	}
	if ( d2 == Denomination::SPADES )
	{
		if ( d1 == Denomination::NT )
		{
			return false;
		}
		return true;
	}
	if ( d2 == Denomination::HEARTS )
	{
		if ( d1 == Denomination::NT || d1 == Denomination::SPADES )
		{
			return false;
		}
		return true;
	}
	if ( d2 == Denomination::DIAMONDS )
	{
		if ( d1 == Denomination::NT || d1 == Denomination::SPADES || d1 == Denomination::HEARTS )
		{
			return false;
		}
		return true;
	}
	if ( d1 != Denomination::CLUBS )
	{
		return false;
	}
	return true;
}

/* ------------------------------------------------------------------------------------------------------------------------*
**                             operator <=( const Call &call, const Contract &contract)                                    *
** ------------------------------------------------------------------------------------------------------------------------*/

bool operator <=( const Call &call, const Contract &contract )
{
	if ( call.level > contract.level || ( call.level == contract.level && call.denomination >= contract.denomination ) ) 
	{
		return false;
	}
	return true;
}

/* ------------------------------------------------------------------------------------------------------------------------*
**                                            Bidding::makeCall(Call call)                                            *
** ------------------------------------------------------------------------------------------------------------------------*/
bool Bidding::makeCall(Call call)
{
	if ( isFinished )
	{
		return false;
	}
	switch ( call.type )
	{
		case CallType::BID :
			consecutivePasses = 0;
			if ( call <= currentContract ) 
			{
				return false;
			}
			currentContract.level = call.level;
			currentContract.denomination = call.denomination;
			currentContract.pointMultiplier = 1;
			lastBidder = callNumber;
			break;
		case CallType::DOUBLE :
			consecutivePasses = 0;
			if ( currentContract.level == 0 || currentContract.pointMultiplier != 1 || lastBidder%2 == callNumber%2 ) 
			{
				return false; //If there is no contract, it's already (re)doubled or it belongs to the current caller's team.
			} else 
			{
				currentContract.pointMultiplier = 2;
			}
			break;
		case CallType::REDOUBLE :
			consecutivePasses = 0;
			if ( currentContract.level == 0 || currentContract.pointMultiplier != 2 || lastBidder%2 != callNumber%2 ) 
			{
				return false; //If there is no contract, it's not exactly doubled or it belongs to the other team.
			} else 
			{
				currentContract.pointMultiplier = 4;
			}
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
	callNumber++;
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


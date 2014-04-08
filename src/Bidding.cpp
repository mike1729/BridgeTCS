#include "Bidding.hpp"

bool operator <=( const Denomination &d1, const Denomination &d2 )
{
	if ( d2 == Denomination::NT )
	{
		return true;
	}
	if ( d2 == Denomination::SPADE )
	{
		if ( d1 == Denomination::NT )
		{
			return false;
		}
		return true;
	}
	if ( d2 == Denomination::HEART )
	{
		if ( d1 == Denomination::NT || d1 == Denomination::SPADE )
		{
			return false;
		}
		return true;
	}
	if ( d2 == Denomination::DIAMOND )
	{
		if ( d1 == Denomination::NT || d1 == Denomination::SPADE || d1 == Denomination::HEART )
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

bool operator <=( const Call &call, const Contract &contract )
{
	if ( call.level > contract.level || ( call.level == contract.level && call.denomination >= contract.denomination ) ) 
	{
		return false;
	}
	return true;
}

bool Bidding::makeCall(Call call)
{
	if ( biddingDone )
	{
		return false;
	}
	switch ( call.type )
	{
		case CallType::BID :
			consectutivePasses = 0;
			if ( call <= currentContract ) 
			{
				return false;
			}
			currentContract.level = call.level;
			currentContract.denomination = call.denomination;
			currentContract.pointMultiplier = 1;
			currentContract.declarer = callNumber; //TODO: This is wrong, the first person should be a declarer.
		break;
		case CallType::DOUBLE :
			consectutivePasses = 0;
			if ( currentContract.level == 0 || currentContract.pointMultiplier != 1 || currentContract.declarer%2 == callNumber%2 ) 
			{
				return false; //If there is no contract, it's already (re)doubled or it belongs to the current caller's team.
			} else 
			{
				currentContract.pointMultiplier = 2;
			}
		break;
		case CallType::REDOUBLE :
			consectutivePasses = 0;
			if ( currentContract.level == 0 || currentContract.pointMultiplier != 2 || currentContract.declarer%2 != callNumber%2 ) 
			{
				return false; //If there is no contract, it's not exactly doubled or it belongs to the other team.
			} else 
			{
				currentContract.pointMultiplier = 4;
			}
		break;
		case CallType::PASS :
			consectutivePasses++;
			if ( currentContract.level != 0 && consectutivePasses >= 3 )
			{
				biddingDone = true;
			}
			if ( consectutivePasses >= 4 )
			{
				currentContract.redeal = true;
				biddingDone = true;
			}
		break;
	}
	callNumber++;
	return true;
}

Contract Bidding::perform()
{
	return currentContract;
}

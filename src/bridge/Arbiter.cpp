#include "Arbiter.hpp"

namespace bridge {

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

Card Arbiter::getCard(Play const & play, Hand const & myhand, BiddingHistory const & bhistory, PlayHistory const & phistory, Hand const & thand)
{
	// Card card = player.chooseCard(play, myhand, bhistory, phistory, thand);
	// //TODO index validation
	// return hand.remove(card);
	
	return Card(Rank::ACE, Suit::SPADES);
}

Card Arbiter::getCard(Play const & play, Hand const & myhand, BiddingHistory const & bhistory, PlayHistory const & phistory, Hand const & thand, Suit const & suit)
{
	//TODO index validation
	// if ( !hand.hasSuit(suit) ) 
	// {
	// 	Card card = player.chooseCard(play, myhand, bhistory, phistory, thand);
	// 	return hand.remove(card);
	// }
	
	// while (true)
	// {
	// 	Card card = player.chooseCard(play, myhand, bhistory, phistory, thand);
	// 	if ( card.suit == suit ) return hand.remove(card);
	// }

	return Card(Rank::ACE, Suit::SPADES);
}

Call Arbiter::getCall(Bidding & bidding, Hand const & hand) 
{
	Contract contract = bidding.getContract();
	
	while (true) 
	{
		Call call = player.makeCall(bidding, hand);
		if ( CallType::BID == call.type && !( call.level > contract.level || ( call.level  == contract.level && call.denomination >= contract.denomination )) ) continue;
		if ( CallType::DOUBLE == call.type && ( contract.level == 0 || contract.pointMultiplier != 1 || bidding.getLastBidder()%2 != bidding.getCallNumber()%2) ) continue;
		if ( CallType::REDOUBLE == call.type && ( contract.level == 0 || contract.pointMultiplier != 2 || bidding.getLastBidder()%2 != bidding.getCallNumber()%2 ) ) continue;
		return call;
	}
}

}

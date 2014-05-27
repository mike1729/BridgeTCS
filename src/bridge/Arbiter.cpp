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

Card Arbiter::getCard(Play const & play, Hand & hand, Bidding const & bidding, Hand const & dummy)
{
	//TODO handle dummy role
	std::list<Card> cards = play.getTrick().getCards();
	//TODO refactor
	if (cards.size() == 0)
	{
		while(true)
		{
			Card card = player.chooseCard(bidding, play, hand, &dummy);
			if(hand.hasCard(card))
				return hand.remove(card);
		}
	}

	Suit suit = (*cards.begin()).suit;
	if(!hand.hasSuit(suit))
	{
		while(true)
		{
			Card card = player.chooseCard(bidding, play, hand, &dummy);
			if(hand.hasCard(card))
				return hand.remove(card);
		}
	}

	while(true)
	{
		Card card = player.chooseCard(bidding, play, hand, &dummy);
		if(hand.hasCard(card) && card.suit == suit)
			return hand.remove(card);
	}
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

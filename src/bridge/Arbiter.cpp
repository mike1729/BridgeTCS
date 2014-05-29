#include "Arbiter.hpp"

namespace bridge {

Card Arbiter::getCard(Play const & play, Hand & hand, Bidding const & bidding, Hand const & dummy)
{
	//TODO handle dummy role
	std::list<Card> cards = play.getTrick().getCards();
	//TODO refactor
	if (cards.size() == 0)
	{
		while(true)
		{
			Card card = player.chooseCard(bidding, play, hand, dummy);
			if(hand.hasCard(card))
				return hand.remove(card);
		}
	}

	Suit suit = (*cards.begin()).suit;
	if(!hand.hasSuit(suit))
	{
		while(true)
		{
			Card card = player.chooseCard(bidding, play, hand, dummy);
			if(hand.hasCard(card))
				return hand.remove(card);
		}
	}

	while(true)
	{
		Card card = player.chooseCard(bidding, play, hand, dummy);
		if(hand.hasCard(card) && card.suit == suit)
			return hand.remove(card);
	}
}

bool Arbiter::isValid(Call call, Bidding const & bidding)
{
	Contract contract = bidding.getContract();
	switch(call.type) 
	{
	case CallType::BID:
		if ( call.level < contract.level )
			return false;
		if ( call.level == contract.level && call.denomination <= contract.denomination )
			return false;
		return true;
	case CallType::DOUBLE:
		if ( contract.level == 0 )
			return false;
		if ( contract.pointMultiplier != 1 )
			return false;
		if ( bidding.getLastBidder()%2 == bidding.getCallNumber()%2 )
			return false;
		return true;
	case CallType::REDOUBLE:
		if ( contract.level == 0 )
			return false;
		if ( contract.pointMultiplier != 2 )
			return false;
		if ( bidding.getLastBidder()%2 != bidding.getCallNumber()%2 )
			return false;
		return true;
	case CallType::PASS:
		return true;
	}
}

Call Arbiter::getCall(Bidding const & bidding, Hand const & hand) 
{
	while (true) 
	{
		Call call = player.makeCall(bidding, hand);
		if ( isValid(call, bidding) )
			return call;
	}
}

}

#include "Arbiter.hpp"

namespace bridge {

bool Arbiter::validateCard(Card & card, Hand & hand, Play const & play)
{
	if(!hand.hasCard(card))
		return false;

	std::list<Card> const & cards = play.getTrick().getCards();
	if(cards.empty())
		return true;

	Suit suit = cards.front().suit;
	if(hand.hasSuit(suit) && card.suit != suit)
		return false;
	
	return true;
}

Card Arbiter::getCard(Bidding const & bidding, Play const & play, Hand & hand, Hand & dummy)
{
	if(role == Role::DUMMY)
	{
		while(true)
		{
			Card card = partner.chooseCardFromDummy(bidding, play, *partnerHand, dummy);
			if(validateCard(card, dummy, play))
			{
				dummy.remove(card);
				return card;
			}
		}
	}
	else
	{
		Hand const * dummy_ptr;
		if(hand.getCards().size() == 13 && play.getTrick().getCards().empty())
			dummy_ptr = nullptr;
		else
			dummy_ptr = &dummy;
		
		while(true)
		{
			Card card = player.chooseCard(bidding, play, hand, dummy_ptr);
			if(validateCard(card, hand, play))
			{
				hand.remove(card);
				return card;
			}
		}
	}
}

bool Arbiter::isValid(Call call, Bidding const & bidding)
{
	Contract contract = bidding.getContract();
	switch(call.type) 
	{
	case CallType::BID:
		if ( call.level < 1 || call.level > 7 || call.level < contract.level )
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
	return false;
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

} //namespace bridge

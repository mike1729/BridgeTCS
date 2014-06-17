#include "Hand.hpp"

namespace bridge {

void Hand::insert(Card c)
{
	hand.push_back(c);
}

void Hand::remove(Card const & card)
{
	for (auto it = hand.begin(); it != hand.end(); it++)
	{
		if (*it == card)
		{
			hand.erase(it);
			sigModified(*this);
			return;
		}
	}
}

void Hand::removeAll()
{
	hand.clear();
}

std::list<Card> const & Hand::getCards() const
{
	return hand;
}

bool Hand::hasCard( Card card ) const
{
	for(auto it = hand.begin(); it != hand.end(); it++)
	{
		if(it->suit == card.suit && it->rank == card.rank)
		{
			return true;
		}
	}
	return false;
}

bool Hand::hasSuit( Suit suit ) const
{
	for(auto it = hand.begin(); it != hand.end(); it++)
	{
		if(it->suit == suit)
		{
			return true;
		}
	}
	return false;
}

void Hand::sort()
{
	hand.sort([](Card a, Card b){ return std::make_pair(a.suit, a.rank) < std::make_pair(b.suit, b.rank); });
}

} //namespace bridge

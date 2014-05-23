#include "Hand.hpp"

namespace bridge {

void Hand::insert(Card&& c)
{
	hand.push_back(std::move(c));
	sigModified(*this);
}

Card Hand::remove(int index)
{
	auto it = hand.begin();
	while(index--)
		it++;
	Card&& c = std::move(*it);
	hand.erase(it);
	sigModified(*this);
	return std::move(c);
}

Card Hand::remove(Card const & card)
{
	for (auto it = hand.begin(); it != hand.end(); it++)
	{
		if (*it == card)
		{
			Card&& c = std::move(*it);
			hand.erase(it);
			sigModified(*this);
			return std::move(c);
		}
	}

	return Card(Rank::ACE, Suit::CLUBS);
}

void Hand::removeAll()
{
	hand.clear();
}

std::list<Card> const & Hand::getCards() const
{
	return hand;
}

bool Hand::hasCard( Card card )
{
    auto it = hand.begin();
    while( it->suit != card.suit || it->rank != card.rank ) it++;
    if( it != hand.end() ) return true;
    return false;
}

bool Hand::hasSuit( Suit suit ) 
{
	auto it = hand.begin();
	while( it->suit != suit ) it++;
	if( it != hand.end() ) return true;
	return false;
}

}

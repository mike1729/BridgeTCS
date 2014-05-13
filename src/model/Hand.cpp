#include "Hand.hpp"

namespace model {

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

void Hand::removeAll()
{
	hand.clear();
}

std::list<Card> const & Hand::getCards() const
{
	return hand;
}

}

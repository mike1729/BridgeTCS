#include "Hand.hpp"

void Hand::insert(Card&& c)
{
	hand.push_back(std::move(c));
	update();
}

Card Hand::remove(int index)
{
	auto it = hand.begin();
	while(index--)
		it++;
	Card&& c = std::move(*it);
	hand.erase(it);
	update();
	return std::move(c);
}

void Hand::removeAll()
{
    hand.clear();
}

std::list<Card> const & Hand::getHand() const
{
	return hand;
}

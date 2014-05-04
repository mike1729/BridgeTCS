#ifndef HAND_HPP
#define HAND_HPP

#include "Card.hpp"
#include <list>
#include <utility>
#include "ui/Observable.hpp"

class Hand: public ui::Observable
{
	public:
		void insert(Card&& c);
		Card remove(int index);
		std::list<Card> const & getHand() const;
	private:
		std::list<Card> hand;
};

#endif

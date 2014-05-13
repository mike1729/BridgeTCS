#ifndef BRIDGE_HAND_HPP
#define BRIDGE_HAND_HPP

#include "Card.hpp"
#include <list>
#include <utility>
#include "ui/Observable.hpp"

namespace bridge {

class Hand: public ui::Observable<Hand>
{
	public:
		void insert(Card&& c);
		Card remove(int index);
		void removeAll();
		std::list<Card> const & getCards() const;
	private:
		std::list<Card> hand;
};

}
#endif

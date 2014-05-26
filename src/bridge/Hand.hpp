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
		void insert(Card);
		Card remove(int);
		Card remove(Card const &);
		void removeAll();
		std::list<Card> const & getCards() const;
		bool hasSuit( Suit suit );
		bool hasCard( Card card );
	private:
		std::list<Card> hand;
};

}

#endif

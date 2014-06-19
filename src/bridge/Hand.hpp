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
		void remove(Card const &);
		void removeAll();
		std::list<Card> const & getCards() const;
		bool hasSuit( Suit suit ) const;
		bool hasCard( Card card ) const;
		void sort();
		
	private:
		std::list<Card> hand;
};

} //namespace bridge

#endif

#ifndef BRIDGE_CARD_HPP
#define BRIDGE_CARD_HPP

#include <utility>
#include <iostream>

namespace bridge {

enum class Rank 
{
	TWO,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT,
	NINE,
	TEN,
	JACK,
	QUEEN,
	KING,
	ACE
};

enum class Suit 
{
	CLUBS,
	DIAMONDS,
	HEARTS,
	SPADES
};

struct Card
{
	Rank rank;
	Suit suit;

	Card(Rank r, Suit s) : rank(r), suit(s)
	{
	}

	bool operator<(const Card & other) {
		return ( suit == other.suit ) ? ( rank < other.rank ) : ( suit < other.suit );
	}
};

}

#endif

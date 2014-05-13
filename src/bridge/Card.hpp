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

	friend class Deck;

	mutable Rank rank;
	mutable Suit suit;

private:
	Card(Rank r, Suit s) : rank(r), suit(s)
	{
	}

public:
	Card(Card&& c) = default;

	Card(Card const& card) = delete;
};

}

#endif

#ifndef BRIDGE_DECK_HPP
#define BRIDGE_DECK_HPP

#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand

#include "Card.hpp"

namespace bridge {

class IDeck
{
public:
	virtual void shuffle() = 0;
	virtual Card dealCard() = 0;
	virtual int cardsLeft() = 0;
	virtual bool empty() = 0;
};

class Deck : public IDeck
{
protected:
	Card createCard(Rank rank, Suit suit) { return Card(rank, suit); }
};

class Standard52Deck : public Deck
{
private:
	std::vector<Card> deck;
	std::vector<Card> allCards;

public:
	Standard52Deck();

	virtual void shuffle();
	virtual Card dealCard();
	virtual int cardsLeft();
	virtual bool empty();
};

} //namespace bridge
#endif

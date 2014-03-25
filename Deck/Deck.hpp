#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand

#include "Card.hpp"

class IDeck
{
public:
	virtual void shuffle() = 0;
	virtual Card dealCard() = 0;
	virtual int cardsLeft() = 0;
	virtual bool empty() = 0;
};

class Standard52Deck : public IDeck
{
private:
	std::vector<Card *> deck;
	std::vector<Card> allCards;

public:
	Standard52Deck();

	virtual void shuffle();
	virtual Card dealCard();
	virtual int cardsLeft();
	virtual bool empty();
};
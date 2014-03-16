#include "Card.hpp"

class IDeck
{
public:
	virtual void shuffle() = 0;
	virtual Card dealCard() = 0;
	virtual int cardsLeft() = 0;
};
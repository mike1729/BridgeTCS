#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand

#include "IDeck.hpp"

class Standard52Deck : public IDeck
{
private:
	std::vector<Card> deck;

public:
	Standard52Deck()
	{
		for (int s = (int) Suit::CLUBS; s <= (int) Suit::SPADES; ++s)
		for (int r = (int) Rank::TWO; r <= (int) Rank::ACE; ++r)
			deck.push_back(Card((Rank) r, (Suit) s));
	}

	virtual void shuffle()
	{
		std::random_shuffle(deck.begin(), deck.end());
	}
	
	virtual Card dealCard()
	{
		Card card = deck.back();
		deck.pop_back();
		return card;
	}

	virtual int cardsLeft()
	{
		return deck.size();
	}

	virtual bool empty()
	{
		return deck.size() == 0;
	}
};
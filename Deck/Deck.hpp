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
	Standard52Deck()
	{
		for (int s = (int) Suit::CLUBS; s <= (int) Suit::SPADES; ++s)
		for (int r = (int) Rank::TWO; r <= (int) Rank::ACE; ++r)
			allCards.push_back(Card((Rank) r, (Suit) s));
		for (int i = 0; i < allCards.size(); ++i)
			deck.push_back(&allCards[i]);
	}

	virtual void shuffle()
	{
		std::random_shuffle(deck.begin(), deck.end());
	}
	
	virtual Card dealCard()
	{
		Card card = *deck.back();
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
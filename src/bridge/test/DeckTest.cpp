#include <gtest/gtest.h>
#include <vector>
#include <utility>
#include "bridge/Deck.hpp"

namespace bridge {

TEST(DeckTest, cardsLeftAll)
{
	Standard52Deck deck = Standard52Deck();
	EXPECT_EQ(deck.cardsLeft(), 52);
}

bool containsEach(std::vector<std::pair<Suit, Rank> > cards)
{
	bool ok = true;
	for (int s = (int) Suit::CLUBS; s <= (int) Suit::SPADES; ++s)
	for (int r = (int) Rank::TWO; r <= (int) Rank::ACE; ++r)
	{
		bool contained = false;
		for (size_t i = 0; i < cards.size(); ++i)
			if (((int) cards[i].second == r) && ((int) cards[i].first == s)) contained = true;
		if(!contained) ok = false; 
	}
	return ok;
}

TEST(DeckTest, containsEachCard)
{
	Standard52Deck deck = Standard52Deck();
	std::vector<std::pair<Suit, Rank> > cards;
	while(!deck.empty())
	{
		Card card = deck.dealCard();
		cards.push_back(std::make_pair(card.suit, card.rank));
	}

	EXPECT_EQ(containsEach(cards), true);
}

TEST(DeckTest, shuffledContainsEachCard)
{
	Standard52Deck deck = Standard52Deck();
	deck.shuffle();
	std::vector<std::pair<Suit, Rank> > cards;
	while(!deck.empty())
	{
		Card card = deck.dealCard();
		cards.push_back(std::make_pair(card.suit, card.rank));
	}

	EXPECT_EQ(containsEach(cards), true);
}

}

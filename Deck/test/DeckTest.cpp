#include <gtest/gtest.h>
#include <vector>
#include "../Deck.hpp"

TEST(DeckTest, cardsLeftAll)
{
	Standard52Deck deck = Standard52Deck();
	ASSERT_EQ(deck.cardsLeft(), 52);
}

bool containsEach(std::vector<Card> cards)
{
	bool ok = true;
	for (int s = (int) Suit::CLUBS; s <= (int) Suit::SPADES; ++s)
	for (int r = (int) Rank::TWO; r <= (int) Rank::ACE; ++r)
	{
		bool contained = false;
		for (size_t i = 0; i < cards.size(); ++i)
			if (((int) cards[i].rank == r) && ((int) cards[i].suit == s)) contained = true;
		if(!contained) ok = false; 
	}
	return ok;
}

TEST(DeckTest, containsEachCard)
{
	Standard52Deck deck = Standard52Deck();
	std::vector<Card> cards;
	while(!deck.empty())
		cards.push_back(deck.dealCard());

	ASSERT_EQ(containsEach(cards), true);
}

TEST(DeckTest, shuffledContainsEachCard)
{
	Standard52Deck deck = Standard52Deck();
	deck.shuffle();
	std::vector<Card> cards;
	while(!deck.empty())
		cards.push_back(deck.dealCard());

	ASSERT_EQ(containsEach(cards), true);
}
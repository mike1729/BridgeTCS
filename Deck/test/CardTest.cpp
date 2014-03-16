#include <gtest/gtest.h>
#include "../Card.hpp"

TEST(CardTest, QueenOfHearts)
{
	Card queenOfHearts = Card(Rank::QUEEN, Suit::HEARTS);
	ASSERT_EQ(queenOfHearts.rank, Rank::QUEEN);
	ASSERT_EQ(queenOfHearts.suit, Suit::HEARTS);
}

TEST(CardTest, JackOfClubs)
{
	Card jackOfClubs = Card(Rank::JACK, Suit::CLUBS);
	ASSERT_EQ(jackOfClubs.rank, Rank::JACK);
	ASSERT_EQ(jackOfClubs.suit, Suit::CLUBS);
}
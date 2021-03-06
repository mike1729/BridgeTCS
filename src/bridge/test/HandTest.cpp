#include <gtest/gtest.h>
#include "bridge/Hand.hpp"
#include "bridge/Deck.hpp"

namespace bridge {

class HandTest: public ::testing::Test
{
	public:
		Hand hand;
		Card c1 = Card(Rank::TWO, Suit::CLUBS);
		Card c2 = Card(Rank::TWO, Suit::DIAMONDS);
		Card c3 = Card(Rank::TWO, Suit::HEARTS);
		Card c4 = Card(Rank::TWO, Suit::SPADES);
		Card c5 = Card(Rank::THREE, Suit::CLUBS);
		void SetUp()
		{
			hand.removeAll();
		}
		void TearDown()
		{
		}
};

TEST_F(HandTest, SimpleInsertRemove) 
{
	EXPECT_EQ(hand.hasCard(c1), false);
	hand.insert(c1);
	EXPECT_EQ(hand.hasCard(c1), true);
	hand.remove(c2);
	EXPECT_EQ(hand.getCards().size(), 1);
	hand.remove(c1);
	EXPECT_EQ(hand.hasCard(c1), false);
}


TEST_F(HandTest, SimpleInsertRemoveAll)
{
	hand.insert(c1);
	hand.insert(c2);
	hand.insert(c3);
	hand.insert(c4);
	hand.removeAll();
	EXPECT_EQ(0, hand.getCards().size());
}

TEST_F(HandTest, HasSuit)
{
	EXPECT_EQ(hand.hasSuit(c1.suit), false);
	hand.insert(c1);
	EXPECT_EQ(hand.hasSuit(c1.suit), true);
	hand.insert(c5);
	EXPECT_EQ(hand.hasSuit(c2.suit), false);
	hand.remove(c1);
	EXPECT_EQ(hand.hasSuit(c1.suit), true);
	hand.remove(c5);
	EXPECT_EQ(hand.hasSuit(c1.suit), false);
}

} //namespace bridge

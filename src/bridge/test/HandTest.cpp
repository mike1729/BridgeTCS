#include <gtest/gtest.h>
#include "bridge/Hand.hpp"
#include "bridge/Deck.hpp"

namespace bridge {

class HandTest: public ::testing::Test
{
	public:
		Standard52Deck *deck;
		Hand *hand;
		void SetUp()
		{
			deck = new Standard52Deck();
			hand = new Hand();
		}
		void TearDown()
		{
			delete deck;
			delete hand;
		}
};

TEST_F(HandTest, SimpleInsertRemove) 
{
	Card c = deck->dealCard();
	Suit s = c.suit;
	Rank r = c.rank;
	hand->insert(c);
	Card c1 = hand->remove(0);
	EXPECT_EQ(c1.suit, s);
	EXPECT_EQ(c1.rank, r);
}


TEST_F(HandTest, SimpleInsertRemoveAll)
{
	hand->insert(deck->dealCard());
	hand->insert(deck->dealCard());
	hand->insert(deck->dealCard());
	hand->insert(deck->dealCard());
	hand->removeAll();
	EXPECT_EQ(0, hand->getHand().size());
}

}

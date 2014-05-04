#include <gtest/gtest.h>
#include "../Hand.hpp"
#include "../Deck.hpp"

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
    Card&& c = deck->dealCard();
    Suit s = c.suit;
    Rank r = c.rank;
    hand->insert(std::move(c));
    Card&& c1 = hand->remove(0);
	ASSERT_EQ(c1.suit, s);
	ASSERT_EQ(c1.rank, r);
}


TEST_F(HandTest, SimpleInsertRemoveAll)
{
    hand->insert(deck->dealCard());
    hand->insert(deck->dealCard());
    hand->insert(deck->dealCard());
    hand->insert(deck->dealCard());
    hand->removeAll();
	ASSERT_EQ(0, hand->getHand().size());
}

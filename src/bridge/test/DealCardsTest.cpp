#include <gtest/gtest.h>
#include "bridge/Deal.hpp"
#include <set>
#include <utility>

namespace bridge {

inline bool operator<(const Card & a, const Card & b) 
{
	return ( a.suit == b.suit ) ? ( a.rank < b.rank ) : ( a.suit < b.suit );
}

class DealPlayer : public IPlayer
{
public:
	virtual Card chooseCard(Bidding const &, Play const &, Hand const &, Hand const *) { return Card(Rank::TWO, Suit::CLUBS); }
	virtual Card chooseCardFromDummy(Bidding const &, Play const &, Hand const &, Hand const &) { return Card(Rank::TWO, Suit::CLUBS); }
	virtual Call makeCall(Bidding const &, Hand const &) { return Call::PASS(); }
};


class DealCardsTest: public ::testing::Test
{
public:
	std::set<Card> noticed;
	Players players;
	void SetUp()
	{
		for ( int i = 0; i < 4; i++ )
		{
			players[i].reset( new DealPlayer() );
		}
	}
	void TearDown()
	{
	}
};

TEST_F(DealCardsTest, StartFrom0) 
{
	Deal deal(players, 0);
	deal.dealCards();

	Hands const & hands = deal.getHands();

	EXPECT_EQ(13, hands[0].getCards().size());
	EXPECT_EQ(13, hands[1].getCards().size());
	EXPECT_EQ(13, hands[2].getCards().size());
	EXPECT_EQ(13, hands[3].getCards().size());
	
	for (int i = 0; i < 4; ++i) 
	{
		auto playerCards = hands[i].getCards();
		for (auto card : playerCards)
		{
			EXPECT_EQ(0, noticed.count(card) );
			noticed.insert(card);
		}
	}
}

TEST_F(DealCardsTest, StartFrom1) 
{
	Deal deal(players, 1);
	deal.dealCards();

	Hands const & hands = deal.getHands();

	EXPECT_EQ(13, hands[0].getCards().size());
	EXPECT_EQ(13, hands[1].getCards().size());
	EXPECT_EQ(13, hands[2].getCards().size());
	EXPECT_EQ(13, hands[3].getCards().size());
	
	for (int i = 0; i < 4; ++i) 
	{
		auto playerCards = hands[i].getCards();
		for (auto card : playerCards)
		{
			EXPECT_EQ(0, noticed.count(card) );
			noticed.insert(card);
		}
	}
}

TEST_F(DealCardsTest, StartFrom2) 
{
	Deal deal(players, 2);
	deal.dealCards();

	Hands const & hands = deal.getHands();

	EXPECT_EQ(13, hands[0].getCards().size());
	EXPECT_EQ(13, hands[1].getCards().size());
	EXPECT_EQ(13, hands[2].getCards().size());
	EXPECT_EQ(13, hands[3].getCards().size());
	
	for (int i = 0; i < 4; ++i) 
	{
		auto playerCards = hands[i].getCards();
		for (auto card : playerCards)
		{
			EXPECT_EQ(0, noticed.count(card) );
			noticed.insert(card);
		}
	}
}

TEST_F(DealCardsTest, StartFrom3) 
{
	Deal deal(players, 3);
	deal.dealCards();

	Hands const & hands = deal.getHands();

	EXPECT_EQ(13, hands[0].getCards().size());
	EXPECT_EQ(13, hands[1].getCards().size());
	EXPECT_EQ(13, hands[2].getCards().size());
	EXPECT_EQ(13, hands[3].getCards().size());
	
	for (int i = 0; i < 4; ++i) 
	{
		auto playerCards = hands[i].getCards();
		for (auto card : playerCards)
		{
			EXPECT_EQ(0, noticed.count(card) );
			noticed.insert(card);
		}
	}
}

} //namespace bridge

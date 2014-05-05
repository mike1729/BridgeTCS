#include <gtest/gtest.h>
#include "../Deal.hpp"
#include <map>
#include <utility>

class DealPlayer : public IPlayer
{
public:
	virtual int chooseCard() { return 0; }
	virtual Call makeCall() { return Call::PASS(); }
};


class dealCardsTest: public ::testing::Test
{
public:
	Hands hands;
	using mcard = std::pair<Suit, Rank>;
	std::map<mcard, bool> noticed;
	std::array<DealPlayer, 4> players;
	Arbiters arbiters{ { {hands[0], players[0]}, {hands[1], players[1]}, {hands[2], players[2]}, {hands[3], players[3]} } };
	Standard52Deck auxilaryDeck;
	void SetUp()
	{
	}
	void TearDown()
	{
	}
};

TEST_F(dealCardsTest, StartFrom0) 
{
	Deal deal(arbiters, hands, 0);
	deal.dealCards();
	while (auxilaryDeck.cardsLeft())
	{
		Card card(auxilaryDeck.dealCard());
		noticed[mcard(card.suit, card.rank)] = false;
	}

	ASSERT_EQ(hands[0].getHand().size(), 13);
	ASSERT_EQ(hands[1].getHand().size(), 13);
	ASSERT_EQ(hands[2].getHand().size(), 13);
	ASSERT_EQ(hands[3].getHand().size(), 13);
	
	for (int i = 0; i < 4; ++i) 
	{
		std::list<Card> const & playerHand = hands[i].getHand();
		for (Card const & card : playerHand)
		{
			ASSERT_EQ(noticed[mcard(card.suit, card.rank)], false); 	
			noticed[mcard(card.suit, card.rank)] = true;
		}
	}	
}

TEST_F(dealCardsTest, StartFrom1) 
{
	Deal deal(arbiters, hands, 1);
	deal.dealCards();
	while (auxilaryDeck.cardsLeft())
	{
		Card card(auxilaryDeck.dealCard());
		noticed[mcard(card.suit, card.rank)] = false;
	}

	ASSERT_EQ(hands[0].getHand().size(), 13);
	ASSERT_EQ(hands[1].getHand().size(), 13);
	ASSERT_EQ(hands[2].getHand().size(), 13);
	ASSERT_EQ(hands[3].getHand().size(), 13);
	
	for (int i = 0; i < 4; ++i) 
	{
		std::list<Card> const & playerHand = hands[i].getHand();
		for (Card const & card : playerHand)
		{
			ASSERT_EQ(noticed[mcard(card.suit, card.rank)], false); 	
			noticed[mcard(card.suit, card.rank)] = true;
		}
	}	
}

TEST_F(dealCardsTest, StartFrom2) 
{
	Deal deal(arbiters, hands, 2);
	deal.dealCards();
	while (auxilaryDeck.cardsLeft())
	{
		Card card(auxilaryDeck.dealCard());
		noticed[mcard(card.suit, card.rank)] = false;
	}

	ASSERT_EQ(hands[0].getHand().size(), 13);
	ASSERT_EQ(hands[1].getHand().size(), 13);
	ASSERT_EQ(hands[2].getHand().size(), 13);
	ASSERT_EQ(hands[3].getHand().size(), 13);
	
	for (int i = 0; i < 4; ++i) 
	{
		std::list<Card> const & playerHand = hands[i].getHand();
		for (Card const & card : playerHand)
		{
			ASSERT_EQ(noticed[mcard(card.suit, card.rank)], false); 	
			noticed[mcard(card.suit, card.rank)] = true;
		}
	}	
}

TEST_F(dealCardsTest, StartFrom3) 
{
	Deal deal(arbiters, hands, 3);
	deal.dealCards();
	while (auxilaryDeck.cardsLeft())
	{
		Card card(auxilaryDeck.dealCard());
		noticed[mcard(card.suit, card.rank)] = false;
	}

	ASSERT_EQ(hands[0].getHand().size(), 13);
	ASSERT_EQ(hands[1].getHand().size(), 13);
	ASSERT_EQ(hands[2].getHand().size(), 13);
	ASSERT_EQ(hands[3].getHand().size(), 13);
	
	for (int i = 0; i < 4; ++i) 
	{
		std::list<Card> const & playerHand = hands[i].getHand();
		for (Card const & card : playerHand)
		{
			ASSERT_EQ(noticed[mcard(card.suit, card.rank)], false); 	
			noticed[mcard(card.suit, card.rank)] = true;
		}
	}	
}

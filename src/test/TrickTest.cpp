#include <gtest/gtest.h>
#include "../Play.hpp"
#include "../Deck.hpp"

class MyDeck : public Deck
{
	virtual void shuffle(){}
	virtual Card dealCard(){
		return createCard(Rank::ACE, Suit::CLUBS);
	}
	virtual int cardsLeft(){return 0;}
	virtual bool empty(){return 0;}
	
public:
	Card createCard(Rank rank, Suit suit)
	{
		return Deck::createCard(rank, suit);
	}
	
};


class TrickTest : public ::testing::Test{
public:
	int player1 = 0;
	int player2 = 1;
	int player3 = 2;
	int player4 = 3;
	Denomination trump;
	MyDeck deck;
};

TEST_F(TrickTest, Adding){
	trump = Denomination::CLUBS;
	Play::Trick trick(trump);
	trick.add(player1, deck.createCard(Rank::ACE, Suit::CLUBS));
	int winner = trick.getWinner();
	ASSERT_EQ(winner, player1);
}

TEST_F(TrickTest, NoTrump1){
	trump = Denomination::NT;
	Play::Trick trick(trump);

	
	trick.add(player1, deck.createCard(Rank::ACE, Suit::CLUBS));
	trick.add(player2, deck.createCard(Rank::ACE, Suit::DIAMONDS));
	trick.add(player3, deck.createCard(Rank::ACE, Suit::HEARTS));
	trick.add(player4, deck.createCard(Rank::TWO, Suit::CLUBS));
	int winner = trick.getWinner();
	ASSERT_EQ(winner, player1);
}

TEST_F(TrickTest, NoTrump2){
	trump = Denomination::NT;
	Play::Trick trick(trump);

	trick.add(player1, deck.createCard(Rank::TWO, Suit::CLUBS));
	trick.add(player2, deck.createCard(Rank::ACE, Suit::DIAMONDS));
	trick.add(player3, deck.createCard(Rank::ACE, Suit::HEARTS));
	trick.add(player4, deck.createCard(Rank::THREE, Suit::CLUBS));

	int winner = trick.getWinner();
	ASSERT_EQ(winner, player4);
}


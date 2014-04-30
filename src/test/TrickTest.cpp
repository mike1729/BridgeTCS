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


TEST_F(TrickTest, NoTrump1){
	trump = Denomination::NT;
	Play::Trick trick(trump, player1);

	Card card1 = deck.createCard(Rank::ACE, Suit::CLUBS);
	Card card2 = deck.createCard(Rank::ACE, Suit::DIAMONDS);
	Card card3 = deck.createCard(Rank::ACE, Suit::HEARTS);
	Card card4 = deck.createCard(Rank::TWO, Suit::CLUBS);
	
	trick.add(card1);
	trick.add(card2);
	trick.add(card3);
	trick.add(card4);
	int winner = trick.getWinner();
	ASSERT_EQ(winner, player1);
}

TEST_F(TrickTest, NoTrump2){
	trump = Denomination::NT;
	Play::Trick trick(trump, player1);

	Card card1 = deck.createCard(Rank::TWO, Suit::CLUBS);
	Card card2 = deck.createCard(Rank::ACE, Suit::DIAMONDS);
	Card card3 = deck.createCard(Rank::ACE, Suit::HEARTS);
	Card card4 = deck.createCard(Rank::THREE, Suit::CLUBS);
	
	trick.add(card1);
	trick.add(card2);
	trick.add(card3);
	trick.add(card4);
	
	int winner = trick.getWinner();
	ASSERT_EQ(winner, player4);
}

TEST_F(TrickTest, NoTrump3a){
	trump = Denomination::NT;
	Play::Trick trick(trump, player1);

	Card card1 = deck.createCard(Rank::TWO, Suit::CLUBS);
	Card card2 = deck.createCard(Rank::ACE, Suit::CLUBS);
	Card card3 = deck.createCard(Rank::ACE, Suit::HEARTS);
	Card card4 = deck.createCard(Rank::TWO, Suit::CLUBS);
	
	trick.add(card1);
	trick.add(card2);
	trick.add(card3);
	trick.add(card4);

	int winner = trick.getWinner();
	ASSERT_EQ(winner, player2);
}


TEST_F(TrickTest, NoTrump3b_player2starts){
	trump = Denomination::NT;
	Play::Trick trick(trump, player2);

	Card card1 = deck.createCard(Rank::TWO, Suit::CLUBS);
	Card card2 = deck.createCard(Rank::ACE, Suit::CLUBS);
	Card card3 = deck.createCard(Rank::ACE, Suit::HEARTS);
	Card card4 = deck.createCard(Rank::TWO, Suit::CLUBS);
	
	trick.add(card1);
	trick.add(card2);
	trick.add(card3);
	trick.add(card4);

	int winner = trick.getWinner();
	ASSERT_EQ(winner, player3);
}

TEST_F(TrickTest, NoTrump3c_player3starts){
	trump = Denomination::NT;
	Play::Trick trick(trump, player3);

	Card card1 = deck.createCard(Rank::TWO, Suit::CLUBS);
	Card card2 = deck.createCard(Rank::ACE, Suit::CLUBS);
	Card card3 = deck.createCard(Rank::ACE, Suit::HEARTS);
	Card card4 = deck.createCard(Rank::TWO, Suit::CLUBS);
	
	trick.add(card1);
	trick.add(card2);
	trick.add(card3);
	trick.add(card4);

	int winner = trick.getWinner();
	ASSERT_EQ(winner, player4);
}

TEST_F(TrickTest, NoTrump3d_player4starts){
	trump = Denomination::NT;
	Play::Trick trick(trump, player4);

	Card card1 = deck.createCard(Rank::TWO, Suit::CLUBS);
	Card card2 = deck.createCard(Rank::ACE, Suit::CLUBS);
	Card card3 = deck.createCard(Rank::ACE, Suit::HEARTS);
	Card card4 = deck.createCard(Rank::TWO, Suit::CLUBS);
	
	trick.add(card1);
	trick.add(card2);
	trick.add(card3);
	trick.add(card4);

	int winner = trick.getWinner();
	ASSERT_EQ(winner, player1);
}


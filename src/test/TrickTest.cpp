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
};


void trickTestCommon (
		Denomination trump,
		int initiator,
		Rank rank1, Suit suit1,
		Rank rank2, Suit suit2,
		Rank rank3, Suit suit3,
		Rank rank4, Suit suit4,
		int anticipatedWinner)	{

	MyDeck deck;

	Play::Trick trick(trump, initiator);

	Card card1 = deck.createCard(rank1, suit1);
	Card card2 = deck.createCard(rank2, suit2);
	Card card3 = deck.createCard(rank3, suit3);
	Card card4 = deck.createCard(rank4, suit4);
	
	trick.add(std::move(card1));
	trick.add(std::move(card2));
	trick.add(std::move(card3));
	trick.add(std::move(card4));
	
	int winner = trick.getWinner();
	ASSERT_EQ(winner, anticipatedWinner);
	
}


TEST_F(TrickTest, NoTrump1){

	trickTestCommon (
		Denomination::NT,
		player1,
		Rank::ACE, Suit::CLUBS,
		Rank::ACE, Suit::DIAMONDS,
		Rank::ACE, Suit::HEARTS,
		Rank::TWO, Suit::CLUBS,
		player1
	);
}

TEST_F(TrickTest, NoTrump2){
	trickTestCommon (
		Denomination::NT,
		player1,
		Rank::TWO, Suit::CLUBS,
		Rank::ACE, Suit::DIAMONDS,
		Rank::ACE, Suit::HEARTS,
		Rank::THREE, Suit::CLUBS,
		player4);
}

TEST_F(TrickTest, NoTrump3a){
	trickTestCommon (
		Denomination::NT,
		player1,
		Rank::TWO, Suit::CLUBS,
		Rank::ACE, Suit::CLUBS,
		Rank::ACE, Suit::HEARTS,
		Rank::THREE, Suit::CLUBS,
		player2);
}

TEST_F(TrickTest, NoTrump3b_player2starts){
	trickTestCommon (
		Denomination::NT,
		player2,
		Rank::TWO, Suit::CLUBS,
		Rank::ACE, Suit::CLUBS,
		Rank::ACE, Suit::HEARTS,
		Rank::THREE, Suit::CLUBS,
		player3);
}

TEST_F(TrickTest, NoTrump3c_player3starts){
	trickTestCommon (
		Denomination::NT,
		player3,
		Rank::TWO, Suit::CLUBS,
		Rank::ACE, Suit::CLUBS,
		Rank::ACE, Suit::HEARTS,
		Rank::THREE, Suit::CLUBS,
		player4);
}

TEST_F(TrickTest, NoTrump3d_player4starts){
	trickTestCommon (
		Denomination::NT,
		player4,
		Rank::TWO, Suit::CLUBS,
		Rank::ACE, Suit::CLUBS,
		Rank::ACE, Suit::HEARTS,
		Rank::THREE, Suit::CLUBS,
		player1);
}


TEST_F(TrickTest, Trump1_WhistInTrump){
	trickTestCommon (
		Denomination::CLUBS,
		player4,
		Rank::ACE, Suit::CLUBS,
		Rank::THREE, Suit::CLUBS,
		Rank::ACE, Suit::HEARTS,
		Rank::TWO, Suit::CLUBS,
		player4);
}

TEST_F(TrickTest, Trump1a_WhistInTrump){
	trickTestCommon (
		Denomination::CLUBS,
		player4,
		Rank::TWO, Suit::CLUBS,
		Rank::ACE, Suit::CLUBS,
		Rank::ACE, Suit::HEARTS,
		Rank::THREE, Suit::CLUBS,
		player1);
}

TEST_F(TrickTest, Trump2){
	trickTestCommon (
		Denomination::HEARTS,
		player2,
		Rank::ACE, Suit::CLUBS,
		Rank::THREE, Suit::CLUBS,
		Rank::ACE, Suit::HEARTS,
		Rank::TWO, Suit::CLUBS,
		player4);
}

TEST_F(TrickTest, Trump3){
	trickTestCommon (
		Denomination::SPADES,
		player3,
		Rank::ACE, Suit::CLUBS,
		Rank::THREE, Suit::CLUBS,
		Rank::ACE, Suit::HEARTS,
		Rank::TWO, Suit::CLUBS,
		player3);
}

TEST_F(TrickTest, Trump3a){
	trickTestCommon (
		Denomination::SPADES,
		player3,
		Rank::KING, Suit::CLUBS,
		Rank::THREE, Suit::CLUBS,
		Rank::ACE, Suit::HEARTS,
		Rank::ACE, Suit::CLUBS,
		player2);
}


TEST_F(TrickTest, Trump4){
	trickTestCommon (
		Denomination::HEARTS,
		player1,
		Rank::QUEEN, Suit::CLUBS,
		Rank::THREE, Suit::HEARTS,
		Rank::KING, Suit::CLUBS,
		Rank::ACE, Suit::HEARTS,
		player4);
}



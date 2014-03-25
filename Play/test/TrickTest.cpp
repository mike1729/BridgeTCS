#include <gtest/gtest.h>
#include "../Play.hpp"

class TrickTest : public ::testing::Test{
public:
	Player player1 = 1;
	Player player2 = 2;
	Player player3 = 3;
	Player player4 = 4;
	Denomination trump;
};

TEST_F(TrickTest, Adding){
	trump = Denomination::Clubs;
	Play::Trick trick(trump);
	trick.add(player1, Card(Rank::ACE, Suit::CLUBS));
	Player const& winner = trick.getWinner();
	ASSERT_EQ(winner, player1);
}

TEST_F(TrickTest, NoTrump1){
	trump = Denomination::NT;
	Play::Trick trick(trump);

	Card card1(Rank::ACE, Suit::CLUBS);
	Card card2(Rank::ACE, Suit::DIAMONDS);
	Card card3(Rank::ACE, Suit::HEARTS);
	Card card4(Rank::TWO, Suit::CLUBS);

	trick.add(player1, card1);
	trick.add(player2, card2);
	trick.add(player3, card3);
	trick.add(player4, card4);
	Player const& winner = trick.getWinner();
	ASSERT_EQ(winner, player1);
}

TEST_F(TrickTest, NoTrump2){
	trump = Denomination::NT;
	Play::Trick trick(trump);

	Card card1(Rank::TWO, Suit::CLUBS);
	Card card2(Rank::ACE, Suit::DIAMONDS);
	Card card3(Rank::ACE, Suit::HEARTS);
	Card card4(Rank::THREE, Suit::CLUBS);

	trick.add(player1, card1);
	trick.add(player2, card2);
	trick.add(player3, card3);
	trick.add(player4, card4);

	Player const& winner = trick.getWinner();
	ASSERT_EQ(winner, player4);
}


#include <gtest/gtest.h>
#include "bridge/Deal.hpp"
#include <queue>
#include <iostream>


namespace bridge {

class BiddingPlayer : public IPlayer 
{
public:
	std::queue<Call> toCall;

	virtual Card chooseCard(Bidding const &, Play const &, Hand const &, Hand const *) { return Card(Rank::ACE, Suit::SPADES); }

	virtual Card chooseCardFromDummy(Bidding const &, Play const &, Hand const &, Hand const &) { return Card(Rank::ACE, Suit::SPADES); }

	virtual Call makeCall(Bidding const &, Hand const &)
	{ 
		if ( toCall.empty() )
		{
				return Call::PASS();
		}
		Call res = toCall.front();
		toCall.pop();
		return res;
	}

	void addCall(Call c)
	{ 
		toCall.push(c);
	}
};

class PerformBiddingTest: public ::testing::Test
{
public:
	Players players;
	Call pass = Call::PASS();
	Call oneClub = Call::BID(1, Denomination::CLUBS);
	Call oneHeart = Call::BID(1, Denomination::HEARTS);
	Call twoHearts = Call::BID(2, Denomination::HEARTS);
	Call threeDiamonds = Call::BID(3, Denomination::DIAMONDS);
	Call threeSpades = Call::BID(3, Denomination::SPADES);
	Call fiveDiamonds = Call::BID(5, Denomination::DIAMONDS);
	Call doubleCall = Call::DOUBLE();
	void SetUp()
	{
		for ( int i = 0; i < 4; i++ )
		{
			players[i].reset( new BiddingPlayer() );
		}
	}
	void TearDown()
	{
	}

	void addCall(int i, Call call ) {
		reinterpret_cast<BiddingPlayer *>( players[i].get() ) -> addCall(call);
	}

};

TEST_F(PerformBiddingTest, FourPasses) 
{
	Deal deal(players, 0);
	EXPECT_EQ(true, deal.performBidding().redeal);
}

TEST_F(PerformBiddingTest, SimpleFinish) 
{
	addCall(0, oneClub);
	Deal deal(players, 0);
	Contract res = deal.performBidding();
	EXPECT_EQ(false, res.redeal);
	EXPECT_EQ(Denomination::CLUBS, res.denomination);
	EXPECT_EQ(1, res.level);
	EXPECT_EQ(1, res.pointMultiplier);
	EXPECT_EQ(0, res.declarer);
}

TEST_F(PerformBiddingTest, RealFinish)
{
	addCall(0, oneClub);
	addCall(1, pass);
	addCall(2, oneHeart);
	addCall(3, doubleCall);
	addCall(0, twoHearts);
	addCall(1, threeDiamonds);
	addCall(2, threeSpades);
	addCall(3, fiveDiamonds);
	Deal deal(players, 0);
	Contract res = deal.performBidding();
	EXPECT_EQ(false, res.redeal);
	EXPECT_EQ(Denomination::DIAMONDS, res.denomination);
	EXPECT_EQ(5, res.level);
	EXPECT_EQ(1, res.pointMultiplier);
	EXPECT_EQ(1, res.declarer);
}

TEST_F(PerformBiddingTest, ValidDouble)
{
	addCall(0, oneClub);
	addCall(1, doubleCall);
	Deal deal(players, 0);
	Contract res = deal.performBidding();
	EXPECT_EQ(false, res.redeal);
	EXPECT_EQ(Denomination::CLUBS, res.denomination);
	EXPECT_EQ(1, res.level);
	EXPECT_EQ(2, res.pointMultiplier);
	EXPECT_EQ(0, res.declarer);
}

TEST_F(PerformBiddingTest, WrongDouble)
{
	addCall(0, oneClub);
	addCall(1, pass);
	addCall(2, doubleCall);
	Deal deal(players, 0);
	Contract res = deal.performBidding();
	EXPECT_EQ(false, res.redeal);
	EXPECT_EQ(Denomination::CLUBS, res.denomination);
	EXPECT_EQ(1, res.level);
	EXPECT_EQ(1, res.pointMultiplier);
	EXPECT_EQ(0, res.declarer);
}

TEST_F(PerformBiddingTest, RealFinishOtherStart)
{
	addCall(1, oneClub);
	addCall(2, pass);
	addCall(3, oneHeart);
	addCall(0, doubleCall);
	addCall(1, twoHearts);
	addCall(2, threeDiamonds);
	addCall(3, threeSpades);
	addCall(0, fiveDiamonds);
	Deal deal(players, 1);
	Contract res = deal.performBidding();
	EXPECT_EQ(false, res.redeal);
	EXPECT_EQ(Denomination::DIAMONDS, res.denomination);
	EXPECT_EQ(5, res.level);
	EXPECT_EQ(1, res.pointMultiplier);
	EXPECT_EQ(2, res.declarer);
}

} //namespace bridge

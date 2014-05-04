#include <gtest/gtest.h>
#include "../Deal.hpp"
#include <queue>
#include <iostream>

class BiddingPlayer : public IPlayer 
{
public:
	std::queue<Call> toCall;

	virtual int chooseCard() { return 0; }

	virtual Call makeCall()
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

class performBiddingTest: public ::testing::Test
{
public:
	Hands hands;
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
	}
	void TearDown()
	{
	}
};

TEST_F(performBiddingTest, FourPasses) 
{
	std::array<BiddingPlayer, 4> players;
	Arbiters arbiters{ { {hands[0], players[0]}, {hands[1], players[1]}, {hands[2], players[2]}, {hands[3], players[3]} } };
	Deal deal(arbiters, hands, 0);
	ASSERT_EQ(deal.performBidding().redeal, true);
}

TEST_F(performBiddingTest, SimpleFinish) 
{
	std::array<BiddingPlayer, 4> players;
	players[0].addCall(oneClub);
	Arbiters arbiters{ { {hands[0], players[0]}, {hands[1], players[1]}, {hands[2], players[2]}, {hands[3], players[3]} } };
	Deal deal(arbiters, hands, 0);
	Contract res = deal.performBidding();
	ASSERT_EQ(res.redeal, false);
	ASSERT_EQ(res.denomination, Denomination::CLUBS);
	ASSERT_EQ(res.level, 1);
	ASSERT_EQ(res.declarer, 0);
}

TEST_F(performBiddingTest, RealFinish)
{
	std::array<BiddingPlayer, 4> players;
	players[0].addCall(oneClub);
	players[1].addCall(pass);
	players[2].addCall(oneHeart);
	players[3].addCall(doubleCall);
	players[0].addCall(twoHearts);
	players[1].addCall(threeDiamonds);
	players[2].addCall(threeSpades);
	players[3].addCall(fiveDiamonds);
	Arbiters arbiters{ { {hands[0], players[0]}, {hands[1], players[1]}, {hands[2], players[2]}, {hands[3], players[3]} } };
	Deal deal(arbiters, hands, 0);
	Contract res = deal.performBidding();
	ASSERT_EQ(res.redeal, false);
	ASSERT_EQ(res.denomination, Denomination::DIAMONDS);
	ASSERT_EQ(res.level, 5);
	ASSERT_EQ(res.declarer, 1);
}

TEST_F(performBiddingTest, WrongDouble)
{
	std::array<BiddingPlayer, 4> players;
	players[0].addCall(oneClub);
	players[1].addCall(pass);
	players[2].addCall(doubleCall);
	Arbiters arbiters{ { {hands[0], players[0]}, {hands[1], players[1]}, {hands[2], players[2]}, {hands[3], players[3]} } };
	Deal deal(arbiters, hands, 0);
	Contract res = deal.performBidding();
	ASSERT_EQ(res.redeal, false);
	ASSERT_EQ(res.denomination, Denomination::CLUBS);
	ASSERT_EQ(res.level, 1);
	ASSERT_EQ(res.declarer, 0);
}

TEST_F(performBiddingTest, RealFinishOtherStart)
{
	std::array<BiddingPlayer, 4> players;
	players[1].addCall(oneClub);
	players[2].addCall(pass);
	players[3].addCall(oneHeart);
	players[0].addCall(doubleCall);
	players[1].addCall(twoHearts);
	players[2].addCall(threeDiamonds);
	players[3].addCall(threeSpades);
	players[0].addCall(fiveDiamonds);
	Arbiters arbiters{ { {hands[0], players[0]}, {hands[1], players[1]}, {hands[2], players[2]}, {hands[3], players[3]} } };
	Deal deal(arbiters, hands, 1);
	Contract res = deal.performBidding();
	ASSERT_EQ(res.redeal, false);
	ASSERT_EQ(res.denomination, Denomination::DIAMONDS);
	ASSERT_EQ(res.level, 5);
	ASSERT_EQ(res.declarer, 2);
}

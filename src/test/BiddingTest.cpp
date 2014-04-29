#include <gtest/gtest.h>
#include "../Bidding.hpp"
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

class BiddingTest: public ::testing::Test
{
public:
 Hand hand;
	Call pass = Call::PASS();
	Call oneClub = Call::BID(1, Denomination::CLUBS);
	Call oneHeart = Call::BID(1, Denomination::HEART);
	Call twoHearts = Call::BID(2, Denomination::HEART);
	Call threeDiamonds = Call::BID(3, Denomination::DIAMOND);
	Call threeSpades = Call::BID(3, Denomination::SPADE);
	Call fiveDiamonds = Call::BID(5, Denomination::DIAMOND);
	Call doubleCall = Call::DOUBLE();
	void SetUp()
	{
	}
	void TearDown()
	{
	}
};

TEST_F(BiddingTest, FourPasses) 
{
	std::array<BiddingPlayer, 4> players;
	std::array<Arbiter, 4> arbiters{ { {0, hand, players[0]}, {1, hand, players[1]}, {2, hand, players[2]}, {3, hand, players[3]} } };
	Bidding bidding(arbiters, 0);
	ASSERT_EQ(bidding.perform().redeal, true);
	ASSERT_EQ(bidding.getContract().redeal, true);
}

TEST_F(BiddingTest, SimpleFinish) 
{
	std::array<BiddingPlayer, 4> players;
	players[0].addCall(oneClub);
	std::array<Arbiter, 4> arbiters{ { {0, hand, players[0]}, {1, hand, players[1]}, {2, hand, players[2]}, {3, hand, players[3]} } };
	Bidding bidding(arbiters, 0);
	Contract res = bidding.perform();
	ASSERT_EQ(res.redeal, false);
	ASSERT_EQ(res.denomination, Denomination::CLUBS);
	ASSERT_EQ(res.level, 1);
	ASSERT_EQ(res.declarer, 0);
}

TEST_F(BiddingTest, RealFinish)
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
	std::array<Arbiter, 4> arbiters{ { {0, hand, players[0]}, {1, hand, players[1]}, {2, hand, players[2]}, {3, hand, players[3]} } };
	Bidding bidding(arbiters, 0);
	Contract res = bidding.perform();
	ASSERT_EQ(res.redeal, false);
	ASSERT_EQ(res.denomination, Denomination::DIAMOND);
	ASSERT_EQ(res.level, 5);
	ASSERT_EQ(res.declarer, 1);
}

TEST_F(BiddingTest, WrongDouble)
{
	std::array<BiddingPlayer, 4> players;
	players[0].addCall(oneClub);
	players[1].addCall(pass);
	players[2].addCall(doubleCall);
	std::array<Arbiter, 4> arbiters{ { {0, hand, players[0]}, {1, hand, players[1]}, {2, hand, players[2]}, {3, hand, players[3]} } };
	Bidding bidding(arbiters, 0);
	Contract res = bidding.perform();
	ASSERT_EQ(res.redeal, false);
	ASSERT_EQ(res.denomination, Denomination::CLUBS);
	ASSERT_EQ(res.level, 1);
	ASSERT_EQ(res.declarer, 0);
}

TEST_F(BiddingTest, RealFinishOtherStart)
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
	std::array<Arbiter, 4> arbiters{ { {0, hand, players[0]}, {1, hand, players[1]}, {2, hand, players[2]}, {3, hand, players[3]} } };
	Bidding bidding(arbiters, 1);
	Contract res = bidding.perform();
	ASSERT_EQ(res.redeal, false);
	ASSERT_EQ(res.denomination, Denomination::DIAMOND);
	ASSERT_EQ(res.level, 5);
	ASSERT_EQ(res.declarer, 2);
}

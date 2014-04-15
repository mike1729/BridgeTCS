#include <gtest/gtest.h>
#include "../Bidding.hpp"

class BiddingStateTest: public ::testing::Test
{
public:
	BiddingState *bidding;
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
		bidding = new BiddingState(0);
	}
	void TearDown()
	{
		delete bidding;
	}
};

TEST_F(BiddingStateTest, FourPasses) 
{
	ASSERT_EQ(bidding->makeCall(pass), true);
	ASSERT_EQ(bidding->makeCall(pass), true);
	ASSERT_EQ(bidding->makeCall(pass), true);
	ASSERT_EQ(bidding->makeCall(pass), true);
	ASSERT_EQ(bidding->getContract().redeal, true);
	ASSERT_EQ(bidding->makeCall(pass), false);
	ASSERT_EQ(bidding->makeCall(oneClub), false);
}

TEST_F(BiddingStateTest, SimpleFinish) 
{
	ASSERT_EQ(bidding->makeCall(oneClub), true);
	ASSERT_EQ(bidding->makeCall(pass), true);
	ASSERT_EQ(bidding->makeCall(pass), true);
	ASSERT_EQ(bidding->makeCall(pass), true);
	Contract res = bidding->getContract();
	ASSERT_EQ(res.redeal, false);
	ASSERT_EQ(res.denomination, Denomination::CLUBS);
	ASSERT_EQ(res.level, 1);
	//TODO: declarer checking.
	ASSERT_EQ(bidding->makeCall(pass), false);
	ASSERT_EQ(bidding->makeCall(oneClub), false);
}

TEST_F(BiddingStateTest, RealFinish)
{
	ASSERT_EQ(bidding->makeCall(oneClub), true);
	ASSERT_EQ(bidding->makeCall(pass), true);
	ASSERT_EQ(bidding->makeCall(oneHeart), true);
	ASSERT_EQ(bidding->makeCall(doubleCall), true);
	ASSERT_EQ(bidding->makeCall(twoHearts), true);
	ASSERT_EQ(bidding->makeCall(threeDiamonds), true);
	ASSERT_EQ(bidding->makeCall(threeSpades), true);
	ASSERT_EQ(bidding->makeCall(fiveDiamonds), true);
	ASSERT_EQ(bidding->makeCall(pass), true);
	ASSERT_EQ(bidding->makeCall(pass), true);
	ASSERT_EQ(bidding->makeCall(pass), true);
	Contract res = bidding->getContract();
	ASSERT_EQ(res.redeal, false);
	ASSERT_EQ(res.denomination, Denomination::DIAMOND);
	ASSERT_EQ(res.level, 5);
	//TODO: declarer checking.
	ASSERT_EQ(bidding->makeCall(pass), false);
	ASSERT_EQ(bidding->makeCall(oneClub), false);
}

TEST_F(BiddingStateTest, WrongDouble)
{
	ASSERT_EQ(bidding->makeCall(oneClub), true);
	ASSERT_EQ(bidding->makeCall(pass), true);
	ASSERT_EQ(bidding->makeCall(doubleCall), false);
}

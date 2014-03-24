#include <gtest/gtest.h>
#include "../Bidding.hpp"

class BiddingTest: public ::testing::Test
{
public:
	Bidding bidding;
	Call pass;
	Call oneClub;
	Call oneHeart;
	Call twoHearts;
	Call threeDiamonds;
	Call threeClubs;
	Call fiveDiamonds;
	Call doubleCall;
	void SetUp()
	{
		pass.type = CallType::Pass;
		oneClub.type = CallType::Bid;
		oneClub.level = 1;
		oneClub.denomination = Denomination::Clubs;
		oneHeart.type = CallType::Bid;
		oneHeart.level = 1;
		oneHeart.denomination = Denomination::Heart;
		twoHearts.type = CallType::Bid;
		twoHearts.level = 2;
		twoHearts.denomination = Denomination::Heart;
		threeDiamonds.type = CallType::Bid;
		threeDiamonds.level = 3;
		threeDiamonds.denomination = Denomination::Diamond;
		threeClubs.type = CallType::Bid;
		threeClubs.level = 3;
		threeClubs.denomination = Denomination::Clubs;
		fiveDiamonds.type = CallType::Bid;
		fiveDiamonds.level = 5;
		fiveDiamonds.denomination = Denomination::Diamond;
		doubleCall.type = CallType::Double;
	}
	void TearDown()
	{
	}
};

TEST_F(BiddingTest, FourPasses) 
{
	ASSERT_EQ(bidding.makeCall(pass), true);
	ASSERT_EQ(bidding.makeCall(pass), true);
	ASSERT_EQ(bidding.makeCall(pass), true);
	ASSERT_EQ(bidding.makeCall(pass), true);
	ASSERT_EQ(bidding.getContract().redeal, true);
	ASSERT_EQ(bidding.makeCall(pass), false);
	ASSERT_EQ(bidding.makeCall(oneClub), false);
}

TEST_F(BiddingTest, SimpleFinish) 
{
	ASSERT_EQ(bidding.makeCall(oneClub), true);
	ASSERT_EQ(bidding.makeCall(pass), true);
	ASSERT_EQ(bidding.makeCall(pass), true);
	ASSERT_EQ(bidding.makeCall(pass), true);
	Contract res = bidding.getContract();
	ASSERT_EQ(res.redeal, false);
	ASSERT_EQ(res.denomination, Denomination::Clubs);
	ASSERT_EQ(res.level, 1);
	//TODO: declarer checking.
	ASSERT_EQ(bidding.makeCall(pass), false);
	ASSERT_EQ(bidding.makeCall(oneClub), false);
}

TEST_F(BiddingTest, RealFinish)
{
	ASSERT_EQ(bidding.makeCall(oneClub), true);
	ASSERT_EQ(bidding.makeCall(pass), true);
	ASSERT_EQ(bidding.makeCall(oneHeart), true);
	ASSERT_EQ(bidding.makeCall(doubleCall), true);
	ASSERT_EQ(bidding.makeCall(twoHearts), true);
	ASSERT_EQ(bidding.makeCall(threeDiamonds), true);
	ASSERT_EQ(bidding.makeCall(threeClubs), true);
	ASSERT_EQ(bidding.makeCall(fiveDiamonds), true);
	ASSERT_EQ(bidding.makeCall(pass), true);
	ASSERT_EQ(bidding.makeCall(pass), true);
	ASSERT_EQ(bidding.makeCall(pass), true);
	Contract res = bidding.getContract();
	ASSERT_EQ(res.redeal, false);
	ASSERT_EQ(res.denomination, Denomination::Diamond);
	ASSERT_EQ(res.level, 5);
	//TODO: declarer checking.
	ASSERT_EQ(bidding.makeCall(pass), false);
	ASSERT_EQ(bidding.makeCall(oneClub), false);
}

TEST_F(BiddingTest, WrongDouble)
{
	ASSERT_EQ(bidding.makeCall(oneClub), true);
	ASSERT_EQ(bidding.makeCall(pass), true);
	ASSERT_EQ(bidding.makeCall(doubleCall), false);
}

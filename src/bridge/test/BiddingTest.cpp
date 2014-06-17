#include <gtest/gtest.h>
#include "bridge/Bidding.hpp"

namespace bridge {

class BiddingTest: public ::testing::Test
{
public:
	Bidding *bidding;
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
		bidding = new Bidding(0);
	}
	void TearDown()
	{
		delete bidding;
	}
};

TEST_F(BiddingTest, FourPasses) 
{
	bidding->makeCall(pass);
	bidding->makeCall(pass);
	bidding->makeCall(pass);
	bidding->makeCall(pass);
	EXPECT_EQ(bidding->getContract().redeal, true);
}

TEST_F(BiddingTest, SimpleFinish) 
{
	bidding->makeCall(oneClub);
	bidding->makeCall(pass);
	bidding->makeCall(pass);
	bidding->makeCall(pass);
	Contract res = bidding->getContract();
	EXPECT_EQ(res.redeal, false);
	EXPECT_EQ(res.denomination, Denomination::CLUBS);
	EXPECT_EQ(res.level, 1);
}

TEST_F(BiddingTest, RealFinish)
{
	bidding->makeCall(oneClub);
	bidding->makeCall(pass);
	bidding->makeCall(oneHeart);
	bidding->makeCall(doubleCall);
	bidding->makeCall(twoHearts);
	bidding->makeCall(threeDiamonds);
	bidding->makeCall(threeSpades);
	bidding->makeCall(fiveDiamonds);
	bidding->makeCall(pass);
	bidding->makeCall(pass);
	bidding->makeCall(pass);
	Contract res = bidding->getContract();
	EXPECT_EQ(res.redeal, false);
	EXPECT_EQ(res.denomination, Denomination::DIAMONDS);
	EXPECT_EQ(res.level, 5);
}

} //namespace bridge

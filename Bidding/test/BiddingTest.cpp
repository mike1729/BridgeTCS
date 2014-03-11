#include <gtest/gtest.h>
#include "../Bidding.hpp"

class BiddingTest: public ::testing::Test
{
public:
	Bidding bidding;
	Call pass;
	void SetUp()
	{
		pass.type = CallType::Pass;
	}
	void TearDown()
	{
	}
};

TEST_F(BiddingTest, FourPasses) {
	bidding.makeCall(pass);
	bidding.makeCall(pass);
	bidding.makeCall(pass);
	bidding.makeCall(pass);
	ASSERT_EQ(bidding.getContract().redeal, true);
}

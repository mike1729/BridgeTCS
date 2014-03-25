#ifndef BIDDING_HPP
#define BIDDING_HPP
#include "Call.hpp"
#include "Contract.hpp"

class Bidding 
{
public:

	Bidding()
	{
	}

	Contract getContract()
	{
		return currentContract;
	}

	bool makeCall(Call call);

private:
	int callNumber = 0;
	Contract currentContract;
	int consectutivePasses = 0;
	bool biddingDone = false;
};
#endif

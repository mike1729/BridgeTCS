#ifndef BIDDING_HPP
#define BIDDING_HPP
#include <array>
#include "Contract.hpp"
#include "Call.hpp"
#include "../Rubber/Arbiter/Arbiter.hpp"

using ArbiterArray = std::array<Arbiter, 4>;

class Bidding 
{
public:

	Bidding(ArbiterArray arbiters, int firstCaller) : arbiters(arbiters), firstCaller(firstCaller)
	{
	}

	Contract getContract()
	{
		return currentContract;
	}

	Contract perform();

	bool makeCall(Call call);

private:
	int callNumber = 0;
	Contract currentContract;
	int consectutivePasses = 0;
	bool biddingDone = false;
	ArbiterArray const & arbiters;
	int firstCaller;
};
#endif

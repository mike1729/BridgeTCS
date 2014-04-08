#ifndef BIDDING_HPP
#define BIDDING_HPP
#include <array>
#include "Contract.hpp"
#include "Call.hpp"
#include "Arbiter.hpp"
#include "BiddingState.hpp"

using ArbiterArray = std::array<Arbiter, 4>;

class Bidding 
{
public:

	Bidding(ArbiterArray arbiters, int firstCaller) : arbiters(arbiters), biddingState(firstCaller), currentCaller(firstCaller)
	{
	}

	Contract getContract()
	{
		return biddingState.getContract();
	}

	Contract perform();

private:
	BiddingState biddingState;
	ArbiterArray const & arbiters;
	int currentCaller;
};
#endif

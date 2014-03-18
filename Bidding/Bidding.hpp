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
	Contract currentContract;
	int consectutivePasses;
};
#endif

#ifndef BIDDING_HPP
#define BIDDING_HPP
#include "Call.hpp"
#include "Contract.hpp"

class Bidding 
{
public:
	Bidding();
	bool makeCall(Call call);
	Contract getContract();
private:
	Contract currentContract;
	int consectutivePasses;
};
#endif

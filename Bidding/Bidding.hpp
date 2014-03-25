#ifndef BIDDING_HPP
#define BIDDING_HPP
#include "Contract.hpp"

enum class CallType
{
	BID, DOUBLE, REDOUBLE, PASS
};

class Call 
{
	Call(CallType type, int level = 0, Denomination denomination = Denomination::NT ) : type(type), level(level), denomination(denomination) 
	{
	}
public:
	CallType const type;
	int const level;
	Denomination const denomination;
	static Call PASS()
	{
		return Call(CallType::PASS);
	}
	static Call DOUBLE()
	{
		return Call(CallType::DOUBLE);
	}
	static Call REDOUBLE()
	{
		return Call(CallType::REDOUBLE);
	}
	static Call BID(int level, Denomination denomination)
	{
		return Call(CallType::BID, level, denomination);
	}
};


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

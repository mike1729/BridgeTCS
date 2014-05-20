#ifndef BRIDGE_BIDDING_HPP
#define BRIDGE_BIDDING_HPP

#include <vector>

#include "Call.hpp"
#include "Contract.hpp"
#include "ui/Observable.hpp"

namespace bridge {

class Bidding : public ui::Observable<Bidding>
{
public:
	using History = std::vector<Call>;

	Bidding(int firstCaller) : firstCaller(firstCaller) {}

	bool makeCall(Call call);
	bool Done()
	{
		return isFinished;
	}
	Contract getContract()
	{
		findDeclarer();
		return currentContract;
	}
	Call getCall()
	{
		return history[ history.size() - 1];
	}
	int returnCurrentCaller()
	{
		return (firstCaller + callNumber)%4;
	}
	int getLastBidder()
	{
        return lastBidder;
	}
	History getHistory()
	{
	    return history;
	}
	int getCallNumber()
	{
	    return callNumber;
	}
	int getConsecutivePassesNumber()
    {
        return consecutivePasses;
    }
private:
	Contract currentContract;
	int consecutivePasses = 0;
	bool isFinished = false;
	int lastBidder = 0;
	int firstCaller;
	History history;
	int callNumber = 0;
	//Call currentCall;
	
	void findDeclarer();
};

}
#endif

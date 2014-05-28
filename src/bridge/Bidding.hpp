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
	
	void makeCall(Call call);
	bool Done() const
	{
		return isFinished;
	}
	Contract const & getContract() const
	{
		return currentContract;
	}
	Call getLastCall() const
	{
		if(history.empty())
			return Call::PASS();
		return history[ history.size() - 1];
	}
	int getCurrentCaller() const
	{
		return (firstCaller + history.size())%4;
	}
	int getLastBidder() const
	{
		return lastBidder;
	}
	History const & getHistory() const
	{
		return history;
	}
	int getCallNumber() const
	{
		return history.size();
	}
	int getConsecutivePassesNumber() const
	{
		return consecutivePasses;
	}
	int getFirstCaller() const
	{
		return firstCaller;
	}
private:
	Contract currentContract;
	int consecutivePasses = 0;
	bool isFinished = false;
	int lastBidder = 0;
	int firstCaller;
	History history;
	//Call currentCall;
	
	void findDeclarer();
};

}
#endif

#ifndef MODEL_BIDDING_HPP
#define MODEL_BIDDING_HPP

#include <vector>

#include "Call.hpp"
#include "Contract.hpp"
#include "ui/Observable.hpp"

class Bidding: public ui::Observable
{
	public:
		using History = std::vector<Call>;

		Bidding(int firstCaller) : firstCaller(firstCaller) {}

		bool makeCall(Call call);
		bool biddingDone()
		{
			return isFinished;
		}
		Contract getContract()
		{
			findDeclarer();
			return currentContract;
		}
	private:
		Contract currentContract;
		int consecutivePasses = 0;
		bool isFinished = false;
		int lastBidder = 0;
		int firstCaller;
		History history;
		int callNumber = 0;

		void findDeclarer();
};
#endif

#ifndef BRIDGE_DEAL_HPP
#define BRIDGE_DEAL_HPP
#include <array>
#include <memory>

#include "Hand.hpp"
#include "Contract.hpp"
#include "Arbiter.hpp"
#include "Bidding.hpp"
#include "Play.hpp"
#include "ui/Observable.hpp"

namespace bridge {

using Arbiters = std::array<Arbiter, 4>;
using Hands = std::array<Hand, 4>;

struct DealResult
{
	Contract contract;
	int declarerTakenTricks;
};


class Deal: public ui::Observable<Deal>
{
public:

	Deal(Arbiters & arbiters, Hands & hands, int firstCaller) : arbiters(arbiters), hands(hands), firstCaller(firstCaller)
	{
	}

	void dealCards();
	Contract performBidding();
	DealResult performPlay();
	
	/*const Play & getPlay() const
	{
		return *play;
	}
	const Bidding & getBidding() const
	{
		return *bidding;
	}
	int getFirstCaller() const
	{
		return firstCaller;
	}
	
	bool biddingDone()
	{
        return bidding->isFinished;
	}

    int getLastBidder()
    {
        return bidding->lastBidder;
    }

    History getHistory()
    {
        return bidding->history;
    }

    int getCallNumber()
    {
        return bidding->callNumber;
    }

    int getConsecutivePassesNumber()
    {
        return bidding->consecutivePasses;
    }*/

private:
	Contract contract;
	Arbiters & arbiters;
	Hands & hands;
	int firstCaller;
	std::unique_ptr<Bidding> bidding;
	std::unique_ptr<Play> play;
	DealResult result;
};

enum class DealEvent
{	
	CardsDealt, BiddingStart, BiddingEnd, PlayStart, PlayEnd
};

}
#endif

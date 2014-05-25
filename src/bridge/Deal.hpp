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


enum class DealEvent
{	
	CardsDealt, BiddingStart, BiddingEnd, PlayStart, PlayEnd
};

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
	
	const Bidding & getBidding() const
	{
		return *bidding;
	}
	const Play & getPlay() const
	{
		return *play;
	}
	const DealEvent & getEvent() const
	{
		return event;
	}

/* This function got provided because bidding.getContract had been written is const-discarding way. If one wants to delete it, they must ensure that bidding.getContract and all its calls are revalidated. */
	const Contract & getValidatedContract() const 
	{
		return contract;
	}

	const Hands & getHands() const
	{
		return hands;
	} 
private:
	Contract contract;
	Arbiters & arbiters;
	Hands & hands;
	int firstCaller;
	std::unique_ptr<Bidding> bidding;
	std::unique_ptr<Play> play;
	DealResult result;
	DealEvent event;
};

}
#endif

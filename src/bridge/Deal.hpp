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
using Players = std::array<std::unique_ptr<IPlayer>, 4>;


enum class DealEvent
{	
	InitState, CardsDealt, BiddingStart, BiddingEnd, PlayStart, PlayEnd
};

struct DealResult
{
	Contract contract;
	int declarerTakenTricks;
};

/*
 *  Performs deal cards, bidding and play.
 */
class Deal: public ui::Observable<Deal>
{
public:

	Deal(const Players & players, int firstCaller) : arbiters{{
		{*players[0], *players[2]},
		{*players[1], *players[3]},
		{*players[2], *players[0]},
		{*players[3], *players[1]}}},
		firstCaller(firstCaller),
		event(DealEvent::InitState)
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

	const Contract & getContract() const 
	{
		return contract;
	}

	const Hands & getHands() const
	{
		return hands;
	} 
private:
	Contract contract;
	Arbiters arbiters;
	Hands hands;
	int firstCaller; // index of player which is the first to make a call
	std::unique_ptr<Bidding> bidding;
	std::unique_ptr<Play> play;
	DealResult result;
	DealEvent event;
};

}
#endif

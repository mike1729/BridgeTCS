#ifndef DEAL_HPP
#define DEAL_HPP
#include <array>

#include "Hand.hpp"
#include "Contract.hpp"
#include "Arbiter.hpp"
#include "Bidding.hpp"
#include "ui/Observable.hpp"

using Arbiters = std::array<Arbiter, 4>;
using Hands = std::array<Hand, 4>;

class dealResult
{
	//TODO
};


class Deal: public ui::Observable
{
public:

	Deal(Arbiters & arbiters, Hands & hands, int firstCaller) : arbiters(arbiters), hands(hands), firstCaller(firstCaller), currentCaller(firstCaller), bidding(firstCaller)
	{
	}

	void dealCards();
	void performBidding();
	dealResult performPlay();

private:
	Contract contract;
	Arbiters & arbiters;
	Hands & hands;
	int firstCaller;
	int currentCaller;
	Bidding bidding;
};
#endif

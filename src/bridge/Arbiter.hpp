#ifndef BRIDGE_ARBITER_HPP
#define BRIDGE_ARBITER_HPP

#include <memory>

#include "Deck.hpp"
#include "Call.hpp"
#include "Player.hpp"
#include "Hand.hpp"

namespace bridge {

class Arbiter 
{
public:
    using BiddingHistory = std::vector<Call>;
    using PlayHistory = std::list< std::unique_ptr<Play::Trick> >;
	Arbiter(Hand &hand, IPlayer &player): hand(hand), player(player) {}
	Card getCard(Play const &, Hand const &, BiddingHistory const &, PlayHistory const &, Hand const &);
	Card getCard(Play const &, Hand const &, BiddingHistory const &, PlayHistory const &, Hand const &, Suit const &);
	Call getCall(Bidding &, Hand const &);
private:
	Hand &hand;
	IPlayer &player;
};

}
#endif

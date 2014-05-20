#ifndef BRIDGE_ARBITER_HPP
#define BRIDGE_ARBITER_HPP

#include "Deck.hpp"
#include "Call.hpp"
#include "Player.hpp"
#include "Hand.hpp"

namespace bridge {

class Arbiter 
{
public:
	Arbiter(Hand &hand, IPlayer &player): hand(hand), player(player) {}
	Card getCard();
	Call getCall();
private:
	Hand &hand;
	IPlayer &player;
};

}
#endif

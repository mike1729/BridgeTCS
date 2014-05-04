#ifndef ARBITER_HPP
#define ARBITER_HPP

#include "Deck.hpp"
#include "Call.hpp"
#include "Player.hpp"
#include "Hand.hpp"

class Arbiter {
	public:
		Arbiter(int id, Hand &hand, IPlayer &player): id(id), hand(hand), player(player) {}
		Card getCard();
		Call getCall();
	private:
		int id;
		Hand &hand;
		IPlayer &player;
};
#endif

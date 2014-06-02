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
	enum class Role { NORMAL, DUMMY };
	Arbiter(IPlayer &player): player(player) {}
	Card getCard(Bidding const &, Play const &, Hand &, Hand const &);
	Call getCall(Bidding const &, Hand const &);
	void setRole(Role role)
	{
		this->role = role;
	}
	Role getRole() const
	{
		return role;
	}
private:
	IPlayer &player;
	Role role;
	bool isValid(Call, Bidding const &);
	bool validateCard(Card &, Hand &, Play const &);
};

}
#endif

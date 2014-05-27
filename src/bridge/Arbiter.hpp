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
	Card getCard(Play const &, Hand &, Bidding const &, Hand const &);
	Call getCall(Bidding &, Hand const &);
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
};

}
#endif

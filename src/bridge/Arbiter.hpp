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
    using BiddingHistory = std::vector<Call>;
    using PlayHistory = std::list< std::unique_ptr<Play::Trick> >;
	Arbiter(IPlayer &player): player(player) {}
	Card getCard(Play const &, Hand const &, BiddingHistory const &, PlayHistory const &, Hand const &);
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

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
	
	Arbiter(IPlayer &player, IPlayer &partner): player(player), partner(partner)
	{
	}
	
	Card getCard(Bidding const &, Play const &, Hand &, Hand &);
	Call getCall(Bidding const &, Hand const &);
	void setRole(Role role) { this->role = role; }
	Role getRole() const { return role; }
	void setPartnerHand(Hand *partnerHand) { this->partnerHand = partnerHand; }

private:
	IPlayer &player;
	IPlayer &partner;
	Role role;
	Hand *partnerHand;	//used only if this->role == Role::DUMMY
	
	bool isValid(Call, Bidding const &);	
	bool validateCard(Card &, Hand &, Play const &);
};

} //namespace bridge
#endif

#include "Player.hpp"

namespace bridge {

Card Player::chooseCard(Play const & p, Hand const & h)
{
	return h.getHand()[0];
}

Call Player::makeCall(Bidding const & b)
{
	//random values
	return Call::BID(1,Denomination::CLUBS);
}

}

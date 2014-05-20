#include "Player.hpp"

namespace bridge {

Card Player::chooseCard(Play const &, Hand const & h, BiddingHistory const &, PlayHistory const &, Hand const &)
{
	return h.getCards().front();
}

Call Player::makeCall(Bidding const &, Hand const &)
{
	//random values
	return Call::BID(1,Denomination::CLUBS);
}

}

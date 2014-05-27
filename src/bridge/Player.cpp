#include "Player.hpp"

namespace bridge {

Card Player::chooseCard(Bidding const &, Play const &, Hand const & hand, Hand const *)
{
	return hand.getCards().front();
}

Card Player::chooseCardFromDummy(Bidding const &, Play const &, Hand const &, Hand const & dummyHand)
{
	return dummyHand.getCards().front();
}

Call Player::makeCall(Bidding const &, Hand const &)
{
	//random values
	return Call::BID(1,Denomination::CLUBS);
}

}

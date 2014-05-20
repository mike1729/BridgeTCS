#include "Player.hpp"

namespace bridge {

Card Player::chooseCard(Play const & p, Hand const & h, BiddingHistory const & bhist, PlayHistory const & plhist, Hand const & dummyHand)
{
	int resultInd;
	sigModified(h, resultInd);
	return h.getHand()[0];
}

Call Player::makeCall(Bidding const & b, Hand const & h)
{
	Call resultCall;
	sigModified(resultCall);
	//random values
	return Call::BID(1,Denomination::CLUBS);
}

}

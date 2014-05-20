#include "Arbiter.hpp"

namespace bridge {

Card Arbiter::getCard(Play const & play, Hand const & myhand, BiddingHistory const & bhistory, PlayHistory const & phistory, Hand const & thand)
{
	Card card = player.chooseCard(play, myhand, bhistory, phistory, thand);
	//TODO index validation
	return hand.remove(card);
}

Card Arbiter::getCard(Play const & play, Hand const & myhand, BiddingHistory const & bhistory, PlayHistory const & phistory, Hand const & thand, Suit const &)
{
	Card card = player.chooseCard(play, myhand, bhistory, phistory, thand);
	//TODO index validation
	return hand.remove(card);
}

Call Arbiter::getCall(Bidding const & bidding, Hand const & hand) 
{
	Call call = player.makeCall(bidding, hand);
	return call;
}

}

#ifndef BRIDGE_PLAYER_HPP
#define BRIDGE_PLAYER_HPP

#include "Call.hpp"
#include "Card.hpp"
#include "Play.hpp"
#include "Hand.hpp"
#include "Bidding.hpp"

namespace bridge {

class IPlayer : public ui::Observable<IPlayer>
{
public:
    using BiddingHistory = std::vector<Call>;
    using PlayHistory = std::list< std::unique_ptr<Play::Trick> >;
	virtual Card chooseCard(Bidding const &, Play const &, Hand const &, Hand const *) = 0;
	virtual Card chooseCardFromDummy(Bidding const &, Play const &, Hand const &, Hand const &) = 0;
	virtual Call makeCall(Bidding const &, Hand const &) = 0;
};

class Player : public IPlayer
{
public:
	virtual Card chooseCard(Bidding const &, Play const &, Hand const &, Hand const *);
	virtual Card chooseCardFromDummy(Bidding const &, Play const &, Hand const &, Hand const &);
	virtual Call makeCall(Bidding const &, Hand const &);
};

}
#endif

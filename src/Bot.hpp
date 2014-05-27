#ifndef BOT_HPP
#define BOT_HPP

#include "bridge/Player.hpp"
#include "bridge/Contract.hpp"

class Bot : public bridge::IPlayer
{
public:
	bridge::Card chooseCard(bridge::Play const &, bridge::Hand const &, BiddingHistory const &, PlayHistory const &, bridge::Hand const &);
	bridge::Call makeCall(bridge::Bidding const &, bridge::Hand const &);
private:
	bool madeCall;
	int highCardPoints(bridge::Hand const &) const;
	int cardsInSuit(bridge::Hand const &, bridge::Suit const &) const;
	bool isOpening(bridge::Bidding const &) const;
	bool isBalanced(bridge::Hand const &) const;
	bool hasCardToSuit(bridge::Hand const &, bridge::Suit) const;
	bridge::Call getPartnerCall(bridge::Bidding const &) const;
	bridge::Call proposeCall(bridge::Bidding const &, bridge::Hand const &);
	bridge::Card minCardToSuit(bridge::Hand const &, bridge::Suit) const;
	bridge::Card maxCardToSuit(bridge::Hand const &, bridge::Suit) const;
	bridge::Card minCard(bridge::Hand const &) const;
	bridge::Card maxCard(bridge::Hand const &) const;
	std::pair<bridge::Denomination, int> getLonger(bridge::Hand const &) const;
};

#endif

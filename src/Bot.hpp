#ifndef BOT_HPP
#define BOT_HPP

#include "bridge/Player.hpp"
#include "bridge/Contract.hpp"

class Bot : public bridge::IPlayer
{
public:
    bridge::Card chooseCard(bridge::Play const &, bridge::Hand const &);
    bridge::Call makeCall(bridge::Bidding const &, bridge::Hand const &);
private:
	bool madeCall;
	int highCardPoints(bridge::Hand const &);
	int cardsInSuit(bridge::Hand const &, bridge::Suit const &);
	bool isOpening(bridge::Bidding const &);
	bool isBalanced(bridge::Hand const &);
    bool hasCardToSuit(bridge::Hand const &, bridge::Suit);
    bridge::Call getPartnerCall(bridge::Bidding const &);
    bridge::Card minCardToSuit(bridge::Hand const &, bridge::Suit);
    bridge::Card maxCardToSuit(bridge::Hand const &, bridge::Suit);
    bridge::Card minCard(bridge::Hand const &);
    bridge::Card maxCard(bridge::Hand const &);
    std::pair<bridge::Denomination, int> getLonger(bridge::Hand const &);
};

#endif

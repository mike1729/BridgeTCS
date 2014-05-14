#ifndef BOT_HPP
#define BOT_HPP

#include "bridge/Player.hpp"

class Bot : public bridge::IPlayer
{
public:
    bridge::Card chooseCard(bridge::Play const &,bridge::Hand const &);
    bridge::Call makeCall(bridge::Bidding const &) = 0;
private:
    bool hasCardToSuit(bridge::Hand const &,bridge::Suit);
    bridge::Card minCardToSuit(bridge::Hand const &, bridge::Suit);
    bridge::Card maxCardToSuit(bridge::Hand const &, bridge::Suit);
    bridge::Card minCard(bridge::Hand const &);
    bridge::Card maxCard(bridge::Hand const &);
};

#endif

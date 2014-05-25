#ifndef UI_TEXT_PLAYERUI_HPP
#define UI_TEXT_PLAYERUI_HPP

#include "bridge/Hand.hpp"
#include "bridge/Player.hpp"
#include "bridge/Card.hpp"
#include "bridge/Call.hpp"
#include <iostream>
#include <string>

namespace ui
{
namespace text
{
class PlayerUI : bridge::IPlayer
{
public:
	bridge::Card chooseCard(bridge::Play const &, bridge::Hand const &, BiddingHistory const &, PlayHistory const &, bridge::Hand const &);
	bridge::Call makeCall(bridge::Bidding const &, bridge::Hand const &);
};
}
}


#endif

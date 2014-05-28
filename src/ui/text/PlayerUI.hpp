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

class PlayerUI : public bridge::IPlayer
{
public:
	virtual bridge::Card chooseCard(bridge::Bidding const &, bridge::Play const &, bridge::Hand const &, bridge::Hand const &);
	virtual bridge::Card chooseCardFromDummy(bridge::Bidding const &, bridge::Play const &, bridge::Hand const &, bridge::Hand const &);
	virtual bridge::Call makeCall(bridge::Bidding const &, bridge::Hand const &);
};

} // namespace text
} // namespace ui

#endif

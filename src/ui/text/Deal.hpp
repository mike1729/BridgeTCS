#ifndef UI_TEXT_DEAL_HPP
#define UI_TEXT_DEAL_HPP

#include <iostream>
#include "bridge/Deal.hpp"
#include "Play.hpp"
#include "Bidding.hpp"
#include "Hand.hpp"

namespace ui
{
namespace text
{

class Deal
{
public:
	void notify(const bridge::Deal & deal);
	Deal(bridge::PlayerID id): id(id) {}
private:
	ui::text::Play playView;
	ui::text::Bidding biddingView;
	ui::text::Hand handView;
    bridge::PlayerID id;
};


} // namespace text
} // namespace ui

#endif

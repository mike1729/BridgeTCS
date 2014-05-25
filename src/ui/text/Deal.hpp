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
private:
	ui::text::Play playView;
	ui::text::Bidding biddingView;
	ui::text::Hand handView;
};


} // namespace text
} // namespace ui

#endif

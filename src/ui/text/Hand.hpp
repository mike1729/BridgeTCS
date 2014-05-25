#ifndef UI_TEXT_HAND_HPP
#define UI_TEXT_HAND_HPP

#include "bridge/Hand.cpp"

namespace ui
{
namespace text
{

class Hand
{
public:
	void print(const bridge::Hand & hand)
	{
		Printer::print(hand);
	}
};


} // namespace text
} // namespace ui

#endif

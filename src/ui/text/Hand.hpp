#ifndef UI_TEXT_HAND_HPP
#define UI_TEXT_HAND_HPP

#include "../Observer.hpp"

namespace ui
{
namespace text
{
		
class Hand : public Observer
{
	::Hand hand;
public:
	Hand(const ::Hand & hand) : hand(hand) {}
};

} // namespace text
} // namespace ui

#endif

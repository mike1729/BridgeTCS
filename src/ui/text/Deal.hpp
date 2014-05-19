#ifndef UI_TEXT_HAND_HPP
#define UI_TEXT_HAND_HPP

#include <iostream>
#include "bridge/Deal.cpp"

namespace ui
{
namespace text
{

class Hand
{
public:
	void print(const bridge::Deal & deal);
};


} // namespace text
} // namespace ui

#endif

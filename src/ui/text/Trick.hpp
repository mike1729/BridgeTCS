#ifndef UI_TEXT_TRICK_HPP
#define UI_TEXT_TRICK_HPP

#include <iostream>
#include "bridge/Contract.hpp"
#include "bridge/Play.hpp"

namespace ui
{
namespace text
{

class Trick
{
public:
	void print(const bridge::Play::Trick & trick);
};

} // namespace text
} // namespace ui

#endif

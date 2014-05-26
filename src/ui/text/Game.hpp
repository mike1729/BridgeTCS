#ifndef UI_TEXT_GAME_HPP
#define UI_TEXT_GAME_HPP

#include <iostream>
#include "bridge/Game.hpp"

namespace ui
{
namespace text
{

class Game
{
public:
	void notify(const bridge::Game & game);
};


} // namespace text
} // namespace ui

#endif

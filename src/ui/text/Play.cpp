#include "Play.hpp"
#include <iostream>

namespace ui 
{
namespace text 
{

void Play::notify(const ::Play & play)
{
	const Trick & trick = play.getTrick();
	ui::text::Trick trickView;

	trick.subscribe(trickView);
	
}

} // namespace text
} // namespace ui

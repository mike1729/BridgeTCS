#ifndef UI_PLAY_DEAL_HPP
#define UI_PLAY_DEAL_HPP

#include "Trick.hpp"

namespace ui
{
namespace text
{
class Play
{
public:
	ui::text::Trick trickView;
	
	void registerTrick(const bridge::Play & play)
	{
		auto & trick = play.getTrick();
		trick.sigModified.connect([this](bridge::Play::Trick const & trick) {
			this->trickView.print(trick);
		});
	}
	
};
}
}


#endif

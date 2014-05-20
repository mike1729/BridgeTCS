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
	void registerTrick(const bridge::Play & play)
	{
		/*play.getTrick().sigModified.connect([& trickView](Trick const & trick) {
			trickView.print(trick);
		});*/
	}
private:
	ui::text::Trick trickView;
	
};
}
}


#endif

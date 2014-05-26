#ifndef UI_TEXT_APPLICATIONVIEW_HPP
#define UI_TEXT_APPLICATIONVIEW_HPP

#include "viewmodel/Application.hpp"
#include "ui/text/Game.hpp"
#include "bridge/Game.hpp"

namespace ui
{
namespace text 
{

class ApplicationView
{
public:
	virtual void notify(const viewmodel::Application & application) {
		std::cout << "Let's play a game!\n";
		/*application.getGame().sigModified.connect([this](bridge::Game const & game) {
					this->gameView.registerDeal(game);
				});
		*/
	}
private:
		ui::text::Game gameView;
};

} // namespace text
} // namespace ui

#endif

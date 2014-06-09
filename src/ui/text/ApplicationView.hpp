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
	void notify(const viewmodel::Application & application) {
		std::cout << "Let's play a game!\n";
		gameView = new ui::text::Game(application.getId());
		application.getGame().sigModified.connect([this](const bridge::Game & game) {
			this->gameView->registerDeal(game);
		});
		
	}
	
private:
		ui::text::Game* gameView;
};

} // namespace text
} // namespace ui

#endif

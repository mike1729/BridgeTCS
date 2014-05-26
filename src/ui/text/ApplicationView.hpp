#ifndef UI_TEXT_APPLICATIONVIEW_HPP
#define UI_TEXT_APPLICATIONVIEW_HPP

#include "viewmodel/Application.hpp"

namespace ui
{
namespace text 
{

class ApplicationView
{
public:
	virtual void notify(const viewmodel::Application & application) {
		std::cout << "Hello World!\n";
		application.getGame().sigModified.connect([this](bridge::Game const & game) {
					this->gameView.registerDeal(game);
				});
		
	}
private:
		ui::text::Game gameView;
};

} // namespace text
} // namespace ui

#endif

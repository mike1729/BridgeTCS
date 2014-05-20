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
	virtual void notify(viewmodel::Application const &) {
		std::cout << "Hello World!\n";
	}
};

} // namespace text
} // namespace ui

#endif

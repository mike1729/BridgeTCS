#ifndef UI_TEXT_APPLICATIONVIEW_HPP
#define UI_TEXT_APPLICATIONVIEW_HPP

#include "ui/Observer.hpp"
#include "bridge/model/Application.hpp"

namespace ui
{
namespace text 
{

class ApplicationView : public Observer<Application>
{
public:
	virtual void notify(Application const &) {
		std::cout << "Hello World!\n";
	}
};

} // namespace text
} // namespace ui

#endif

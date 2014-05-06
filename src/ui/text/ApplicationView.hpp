#ifndef _APPLICATION_VIEW_HPP
#define _APPLICATION_VIEW_HPP

#include "../Observer.hpp"
#include "../../Application.hpp"

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
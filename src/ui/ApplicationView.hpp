#ifndef _APPLICATION_VIEW_HPP
#define _APPLICATION_VIEW_HPP

#include "Observer.hpp"

namespace ui {

class ApplicationView : public Observer {
public:
	void notify() const;
};

}

#endif
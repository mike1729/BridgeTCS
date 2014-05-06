#ifndef UI_OBSERVER_HPP
#define UI_OBSERVER_HPP

#include <boost/signals2.hpp>

namespace ui
{

template <typename T>
class Observer {
public:
	virtual void notify(T const &) = 0;
};

}

#endif

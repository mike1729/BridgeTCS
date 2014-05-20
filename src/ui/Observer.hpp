#ifndef UI_OBSERVER_HPP
#define UI_OBSERVER_HPP

namespace ui
{

template <typename T>
class Observer {
public:
	virtual void notify(T const &) = 0;
};

}

#endif

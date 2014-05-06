#ifndef UI_OBSERVABLE_HPP
#define UI_OBSERVABLE_HPP

#include <boost/signals2.hpp>
#include <functional>

namespace ui 
{

template <typename Derived>
class Observable 
{
public:
	boost::signals2::signal<void (Derived const &)> sigModified;

	template <class Notifyable>
	void subscribe(Notifyable& n) 
	{
		sigModified.connect(std::bind(&Notifyable::notify, &n, std::placeholders::_1));
	}
};

}

#endif

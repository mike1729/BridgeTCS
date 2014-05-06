#ifndef UI_OBSERVABLE_HPP
#define UI_OBSERVABLE_HPP

#include <boost/signals2.hpp>

namespace ui {

template <typename Derived>
class Observable {
public:
	boost::signals2::signal<void (Derived const &)> sigModified;
};

}

#endif

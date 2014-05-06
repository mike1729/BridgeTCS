#ifndef Observer_hpp
#define Observer_hpp

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

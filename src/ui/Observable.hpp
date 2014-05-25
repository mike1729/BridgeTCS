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
	mutable boost::signals2::signal<void (Derived const &)> sigModified;
	
	/*Observable<Derived> & operator=(Observable<Derived> && other)
	{
		
	}

	template <class Notifyable>
	void subscribe(Notifyable& n) 
	{
		sigModified.connect(std::bind(&Notifyable::notify, &n, std::placeholders::_1));
	}*/
};

}

#endif

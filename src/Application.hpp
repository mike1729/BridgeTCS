#ifndef _APPLICATION_HPP
#define _APPLICATION_HPP

#include "ui/Observable.hpp"

class Application : public ui::Observable<Application>
{
public:
	void run() 
	{
		sigModified(*this);
	}
};

#endif
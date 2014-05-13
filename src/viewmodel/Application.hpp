#ifndef VIEWMODEL_APPLICATION_HPP
#define VIEWMODEL_APPLICATION_HPP

#include "../ui/Observable.hpp"

namespace viewmodel {

class Application : public ui::Observable<Application>
{
public:
	void run() 
	{
		sigModified(*this);
	}
};

}
#endif

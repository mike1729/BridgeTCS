#ifndef MODEL_APPLICATION_HPP
#define MODEL_APPLICATION_HPP

#include "../ui/Observable.hpp"

namespace model {

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

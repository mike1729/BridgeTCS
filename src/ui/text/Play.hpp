#ifndef Hand_hpp
#define Hand_hpp

#include "bridge/Contract.hpp"

namespace ui
{
namespace text
{
class Play : public Observer<::Play>
{
public:
	void Play::registerTrick(const ::Play & play)
	{
	}
};
}
}


#endif

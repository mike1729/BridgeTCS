#ifndef Hand_hpp
#define Hand_hpp

#include <iostream>
#include "bridge/Contract.hpp"
#include "bridge/Play.hpp"

namespace ui
{
namespace text
{

class Trick
{
public:
	void print(const bridge::Play::Trick & trick);
};

} // namespace text
} // namespace ui

#endif

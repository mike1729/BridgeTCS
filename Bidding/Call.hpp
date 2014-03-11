#ifndef CALL_HPP
#define CALL_HPP
#include "Denomination.hpp"

enum class CallType
{
	Bid, Double, Redouble, Pass
};

struct Call 
{
	CallType type;
	int level;
	Denomination denomination;
};
#endif

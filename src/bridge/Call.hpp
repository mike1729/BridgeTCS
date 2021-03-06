#ifndef BRIDGE_CALL_HPP
#define BRIDGE_CALL_HPP
#include "Contract.hpp"

namespace bridge {

enum class CallType
{
	BID, DOUBLE, REDOUBLE, PASS
};

class Call 
{
	Call(CallType type, int level = 0, Denomination denomination = Denomination::NT ) : type(type), level(level), denomination(denomination) 
	{
	}

public:
	CallType type;
	int level;
	Denomination denomination;
	
	static Call PASS()	{ return Call(CallType::PASS); }
	static Call DOUBLE() {	return Call(CallType::DOUBLE); }
	static Call REDOUBLE() { return Call(CallType::REDOUBLE); }
	static Call BID(int level, Denomination denomination) { return Call(CallType::BID, level, denomination); }
};

} //namespace bridge
#endif

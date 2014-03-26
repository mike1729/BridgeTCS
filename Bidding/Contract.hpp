#ifndef CONTRACT_HPP
#define CONTRACT_HPP
#include "Denomination.hpp"


struct Contract
{
	int level;
	Denomination denomination;
	int pointMultiplier = 1;
	int declarer;
	bool redeal;
};
#endif

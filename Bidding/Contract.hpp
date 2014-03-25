#ifndef CONTRACT_HPP
#define CONTRACT_HPP
#include "Denomination.hpp"

using Player = int;

struct Contract
{
	int level;
	Denomination denomination;
	int pointMultiplier = 1;
	Player declarer;
	bool redeal;
};
#endif

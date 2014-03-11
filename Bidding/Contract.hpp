#ifndef CONTRACT_HPP
#define CONTRACT_HPP
#include "Denomination.hpp"

using Player = int;

struct Contract
{
	int level;
	Denomination denomination;
	Player declarer;
	bool redeal;
};
#endif

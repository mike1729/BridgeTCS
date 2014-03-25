#ifndef CONTRACT_HPP
#define CONTRACT_HPP

using Player = int;

enum class Denomination {
	CLUBS, DIAMOND, HEART, SPADE, NT
};

struct Contract
{
	int level;
	Denomination denomination;
	int pointMultiplier = 1;
	Player declarer;
	bool redeal;
};
#endif

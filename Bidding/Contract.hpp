#ifndef CONTRACT_HPP
#define CONTRACT_HPP

enum class Denomination {
	CLUBS, DIAMOND, HEART, SPADE, NT
};

struct Contract
{
	int level;
	Denomination denomination;
	int pointMultiplier = 1;
	int declarer;
	bool redeal;
};
#endif

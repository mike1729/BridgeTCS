#ifndef CONTRACT_HPP
#define CONTRACT_HPP

enum class Denomination {
	CLUBS, DIAMONDS, HEARTS, SPADES, NT
};

struct Contract
{
	int level = 0;
	Denomination denomination;
	int pointMultiplier = 1;
	int declarer;
	bool redeal = false;
};
#endif

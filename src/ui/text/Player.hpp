#ifndef UI_PLAYER_DEAL_HPP
#define UI_PLAYER_DEAL_HPP

#include "bridge/Hand"
#include <iostream>

namespace ui
{
namespace text
{
class Player
{
public:
	void getCard(const bridge::Hand & hand, int & resultInd)
	{
		std::cout << "Throw a card.\n";
		hand.sigModified(hand);
		std::cin >> resultInd;
	}

	void makeCall(Call & callInd)
	{
		std::cout << "Make a call.\n";
		//std::cin >> resultind;
	}
	
};
}
}


#endif

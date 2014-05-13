#include "Player.hpp"

namespace bridge {

int Player::chooseCard()
{
	return 0;
}

Call Player::makeCall()
{
	//random values
	return Call::BID(1,Denomination::CLUBS);
}

}

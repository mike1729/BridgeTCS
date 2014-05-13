#include "Player.hpp"

namespace model {

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

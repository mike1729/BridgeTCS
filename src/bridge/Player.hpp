#ifndef BRIDGE_PLAYER_HPP
#define BRIDGE_PLAYER_HPP

#include "Call.hpp"

namespace bridge {

class IPlayer
{
public:
	virtual int chooseCard() = 0;
	virtual Call makeCall() = 0;
};

class Player : public IPlayer
{
	virtual int chooseCard();
	virtual Call makeCall();
};

}
#endif

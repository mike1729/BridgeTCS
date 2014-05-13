#ifndef MODEL_PLAYER_HPP
#define MODEL_PLAYER_HPP

#include "Call.hpp"

namespace model {

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

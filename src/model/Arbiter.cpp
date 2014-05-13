#include "Arbiter.hpp"

namespace model {

Card Arbiter::getCard()
{
	int index = player.chooseCard();
	//TODO index validation
	return hand.remove(index);
}

Call Arbiter::getCall() 
{
	Call call = player.makeCall();
	return call;
}

}

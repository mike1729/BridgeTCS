#include "Arbiter.hpp"

Card Arbiter::getCard()
{
    int index = player.chooseCard();
    //TODO index validation
    return hand.remove(index);
}

Call Arbiter::getCall() const
{
    Call call = player.makeCall();
    return call;
}

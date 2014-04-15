#include "Arbiter.hpp"

void Arbiter::addCard(Card&& c)
{
    //if(hand.size() >= 13) throw 0;
    hand.insert(std::move(c));
}

Card&& Arbiter::getCard()
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

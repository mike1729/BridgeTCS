#include "Player.hpp"

int Player::chooseCard() const
{
    return 0;
}

Call Player::makeCall() const
{
    //random values
    return Call::BID(1,Denomination::CLUBS);
}

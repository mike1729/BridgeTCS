#include "Player.hpp"

int Player::chooseCard()
{
    return 0;
}

Call Player::makeCall()
{
    //random values
    Call call;
    call.type = CallType::Bid;
    call.level = 1;
    call.denomination = Denomination::Clubs;
    return call;
}

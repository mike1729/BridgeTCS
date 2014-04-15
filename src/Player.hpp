#ifndef  _PLAYER_HPP
#define _PLAYER_HPP

#include "Call.hpp"

class IPlayer
{
public:
    virtual int chooseCard() = 0;
    virtual Call makeCall() = 0;
};

class Player : public IPlayer
{
    virtual int chooseCard() const;
    virtual Call makeCall() const;
};

#endif


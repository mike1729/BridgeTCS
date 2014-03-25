#include "Player.hpp"

int Player::getId()
{
    return id;
}

void Player::addCard(Card c)
{
    //if ( (int) hand.size() >= 13) throw 0;
    hand.push_back(c);
}

Card Player::getCard(int index)
{ 
    
    if( index >= (int) hand.size() ) 
	throw 0;
    return hand[index];
    
}

#ifndef  _PLAYER_HPP
#define _PLAYER_HPP
#include "../../Deck/Card.hpp"
#include <iostream>
#include <vector>
class Player
{
private:
    int id;
    std::vector<Card> hand;
public:
    Player(int _id): id(_id) {}
    int getId();
    void addCard(Card c);
//    Card getCard(Card *c);
    Card getCard(int index);
};

#endif


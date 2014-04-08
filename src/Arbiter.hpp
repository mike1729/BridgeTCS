#ifndef ARBITER_HPP
#define ARBITER_HPP

#include <vector>
#include "Deck.hpp"
#include "Call.hpp"
#include "Player.hpp"

class Arbiter {
public:
    Arbiter(int _id, IPlayer &_player): id_arbiter(_id),player(_player) {}
    Card getCard();
    void addCard(Card c);
    Call getCall();
private:
    int id_arbiter;
    std::vector<Card> hand;
    IPlayer &player;
};
#endif

#ifndef HAND_HPP
#define HAND_HPP

#include "Card.hpp"
#include <list>
#include <utility>

class Hand {
public:
    void insert(Card&& c);
    Card&& remove(int index);
    std::list<Card> const & getHand();
private:
    std::list<Card> hand;
};

#endif

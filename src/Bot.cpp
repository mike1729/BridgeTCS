#include "Bot.hpp"

bridge::Card Bot::chooseCard(bridge::Play const & play, bridge::Hand const & hand)
{
    /*std::list<bridge::Card> cards = play.getTrick().getCards();
    if (cards.size() > 0)
    {
        if (hasCardToSuit(hand,(*cards.begin()).suit))
        {
            bridge::Card minCard = minCardToSuit(hand,(*cards.begin()).suit);
            bridge::Card maxCard = maxCardToSuit(hand,(*cards.begin()).suit);
            for (auto c : cards)
                if (maxCard.suit==c.suit and maxCard < c)
                    return minCard;
            return maxCard;
        }
        else
            return minCard(hand);
    }
    else
        return maxCard(hand);*/
    return *hand.getCards().begin();
}

bool Bot::hasCardToSuit(bridge::Hand const & hand, bridge::Suit suit)
{
    for (auto c : hand.getCards())
        if (c.suit == suit)
            return true;
    return false;
}

bridge::Card Bot::minCardToSuit(bridge::Hand const & hand, bridge::Suit suit)
{
    bridge::Card card(bridge::Rank::ACE, suit);
    for (auto c : hand.getCards())
        if (c.suit == suit && c<card)
            card=c;
    return card;
}

bridge::Card Bot::maxCardToSuit(bridge::Hand const & hand, bridge::Suit suit)
{
    bridge::Card card(bridge::Rank::TWO, suit);
    for (auto c : hand.getCards())
        if (c.suit == suit && card<c)
            card = c;
    return card;
}

bridge::Card Bot::minCard(bridge::Hand const & hand)
{
    bridge::Card card(bridge::Rank::ACE, bridge::Suit::SPADES);
    for (auto c : hand.getCards())
        if (c<card)
            card = c;
    return card;
}

bridge::Card Bot::maxCard(bridge::Hand const & hand)
{
    bridge::Card card(bridge::Rank::TWO, bridge::Suit::CLUBS);
    for (auto c : hand.getCards())
        if (card<c)
            card = c;
    return card;
}

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

int Bot::highCardPoints(bridge::Hand const & hand)
{
    int value = 0;

    for (auto card : hand.getCards())
    {
        value += std::max(0, (int) card.rank - (int) bridge::Rank::TEN);
    }

    return value;
}

int Bot::cardsInSuit(bridge::Hand const & hand, bridge::Suit const & suit)
{
    int result = 0;

    for (auto card : hand.getCards())
    {
        if (card.suit == suit) result++;
    }

    return result;
}

bool Bot::isOpening(bridge::Bidding const & bidding) 
{
    return true;
}

bool Bot::isBalanced(bridge::Hand const & hand)
{
    int length[4];
    length[0] = length[1] = length[2] = length[3] = 0;

    for (auto card : hand.getCards()) 
    {
        length[(int) card.suit]++;
    }

    int missing = 0;

    for (int i = 0; i < 4; i++)
    {
        if (length[i] == 0) 
        {
            missing++;
            if (missing > 1) return false;
            continue;
        }

        for (int j = 0; j < 4; j++)
        {
            if (length[j] == 0) continue;

            if (std::abs(length[i] - length[j]) > 2) return false;
        }
    }

    return true;
}

bridge::Call Bot::getPartnerCall(bridge::Bidding const & bidding)
{
    return bridge::Call::PASS();
}

std::pair<bridge::Denomination, int> Bot::getLonger(bridge::Hand const & hand)
{
    int length[4];
    length[0] = length[1] = length[2] = length[3] = 0;

    for (auto card : hand.getCards()) 
    {
        length[(int) card.suit]++;
    }

    int suit = 0;
    for (int i = 1; i < 4; i++)
    {
        if (length[suit] < length[i])
        {
            suit = i;
        }
    }

    return std::make_pair((bridge::Denomination) suit, length[suit]);
}

bridge::Call Bot::makeCall(bridge::Bidding const & bidding, bridge::Hand const & hand)
{
    if (madeCall) return bridge::Call::PASS();

    madeCall = true;

    if (isOpening(bidding)) 
    {
        int points = highCardPoints(hand);
        auto longer = getLonger(hand);

        if (points < 6) return bridge::Call::PASS();
        else if (points < 12 && longer.second < 7) return bridge::Call::PASS();
        else if (points < 12) return bridge::Call::BID(3, longer.first);
        else if (points > 14 && points < 18 && isBalanced(hand)) return bridge::Call::BID(1, bridge::Denomination::NT);
        else if (points < 18) return bridge::Call::BID(1, longer.first);
        else if (points > 20 && points < 24 && isBalanced(hand)) return bridge::Call::BID(2, bridge::Denomination::NT);
        else if (points < 25) return bridge::Call::BID(2, longer.first);
        else return bridge::Call::BID(3, bridge::Denomination::NT);
    }
    
    auto partnerCall = getPartnerCall(bidding);

    auto denomination = partnerCall.denomination;

    if (denomination == bridge::Denomination::NT)
    {
        int points = highCardPoints(hand);

        if (partnerCall.level == 1) points += 15;
        else if (partnerCall.level == 2) points += 21;
        else points += 25;

        if (points/3 <= partnerCall.level) return bridge::Call::PASS();
        return bridge::Call::BID(points/3, denomination);
    }

    int length = cardsInSuit(hand, (bridge::Suit)(int)denomination);

    if (length > 3) return bridge::Call::BID(partnerCall.level + length - 3, denomination);
    
    return bridge::Call::PASS();
}
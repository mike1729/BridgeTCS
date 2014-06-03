#include "Bot.hpp"

inline bool operator<(const bridge::Card & a, const bridge::Card & b)
{
	return ( a.suit == b.suit ) ? ( a.rank < b.rank ) : ( a.suit < b.suit );
}
inline bool operator<=(const bridge::Card & a, const bridge::Card & b)
{
	return ( a.suit == b.suit ) ? ( a.rank <= b.rank ) : ( a.suit <= b.suit );
}



/* Simple startegy: if bot can beat cards from trick (has card higher than every card in trick)
 * or is first-turn player, then throw maximal possesed card.
 * In other case bot returns the lowest possessed card. */
bridge::Card Bot::chooseCard(bridge::Bidding const &, bridge::Play const & play, bridge::Hand const & hand, bridge::Hand const &)
{
	auto cards = play.getTrick().getCards();
	if (cards.size() > 0)
	{
		if (hasCardToSuit(hand,(*cards.begin()).suit))
		{
			auto minCard = minCardToSuit(hand,(*cards.begin()).suit);
			auto maxCard = maxCardToSuit(hand,(*cards.begin()).suit);
			for (auto c : cards)
				if (maxCard.suit == c.suit and maxCard < c)
					return minCard;

			if (cards.size() > 1)
			{
				auto cardIt = cards.end();
				cardIt--; cardIt--;

				auto rank = (*cardIt).rank;
				auto suit = (*cardIt).suit;

				bool highest = true;
				for (auto card : cards)
				{
					if (suit == card.suit and rank < card.rank)
					{
						highest = false;
						break;
					}
				}

				if (highest) return minCard;
			}

			return maxCard;
		}
		else return minCard(hand);
	}
	else return maxCard(	hand);
}


bridge::Card Bot::chooseCardFromDummy(bridge::Bidding const &, bridge::Play const & play, bridge::Hand const &, bridge::Hand const & dummyHand)
{
	auto cards = play.getTrick().getCards();
	if (cards.size() > 0)
	{
		if (hasCardToSuit(dummyHand,(*cards.begin()).suit))
		{
			auto minCard = minCardToSuit(dummyHand,(*cards.begin()).suit);
			auto maxCard = maxCardToSuit(dummyHand,(*cards.begin()).suit);
			for (auto c : cards)
				if (maxCard.suit == c.suit and maxCard < c)
					return minCard;

			if (cards.size() > 1)
			{
				auto cardIt = cards.end();
				cardIt--; cardIt--;

				auto rank = (*cardIt).rank;
				auto suit = (*cardIt).suit;

				bool highest = true;
				for (auto card : cards)
				{
					if (suit == card.suit and rank < card.rank)
					{
						highest = false;
						break;
					}
				}

				if (highest) return minCard;
			}

			return maxCard;
		}
		else return minCard(dummyHand);
	}
	else return maxCard(dummyHand);
}

bool Bot::hasCardToSuit(bridge::Hand const & hand, bridge::Suit suit) const
{
	for (auto c : hand.getCards())
		if (c.suit == suit)
			return true;
	return false;
}

/* Returns minimal possessed range of particular suit. */
bridge::Card Bot::minCardToSuit(bridge::Hand const & hand, bridge::Suit suit) const
{
	bridge::Card card(bridge::Rank::ACE, suit);
	for (auto c : hand.getCards())
		if (c.suit == suit && c <= card)
			card=c;
	return card;
}

/* Returns maximal possessed range of particular suit. */
bridge::Card Bot::maxCardToSuit(bridge::Hand const & hand, bridge::Suit suit) const
{
	bridge::Card card(bridge::Rank::TWO, suit);
	for (auto c : hand.getCards())
		if (c.suit == suit && card <= c)
			card = c;
	return card;
}

/* Returns minimal possessed card. */
bridge::Card Bot::minCard(bridge::Hand const & hand) const
{
	bridge::Card card(bridge::Rank::ACE, bridge::Suit::SPADES);
	for (auto c : hand.getCards())
		if (c.rank <= card.rank)
			card = c;
	return card;
}

/* Returns maximal possessed card. */
bridge::Card Bot::maxCard(bridge::Hand const & hand) const
{
	bridge::Card card(bridge::Rank::TWO, bridge::Suit::CLUBS);
	for (auto c : hand.getCards())
		if (card.rank <= c.rank)
			card = c;
	return card;
}

/*
 *	Counts card points using rules:
 *	J = 1p
 *	Q = 2p
 *	K = 3p
 *	A = 4p 
 */
int Bot::highCardPoints(bridge::Hand const & hand) const
{
	int value = 0;

	for (auto card : hand.getCards())
	{
		value += std::max(0, (int) card.rank - (int) bridge::Rank::TEN);
	}

	return value;
}

/*
 *	Counts number of cards in a given suit
 */
int Bot::cardsInSuit(bridge::Hand const & hand, bridge::Suit const & suit) const
{
	int result = 0;

	for (auto card : hand.getCards())
	{
		if (card.suit == suit) result++;
	}

	return result;
}

/*
 *	Checks if you are the opening person from your pair
 */
bool Bot::isOpening(bridge::Bidding const & bidding) const
{
	auto history = bidding.getHistory();
	if (history.size() < 2 || history[history.size() - 2].type == bridge::CallType::PASS)
	{
		return true;
	}
	return false;
}

/*
 *	Checks if your hand is balanced
 */
bool Bot::isBalanced(bridge::Hand const & hand) const
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

/*
 *	Retrieve your partner's last call from Bidding
 */
bridge::Call Bot::getPartnerCall(bridge::Bidding const & bidding) const
{
	auto history = bidding.getHistory();
	if (history.size() >= 2)
	{
		return history[history.size() - 2];
	}

	return bridge::Call::PASS();
}

/*
 *	Get longer from your hand - suit with most cards in it
 */
std::pair<bridge::Denomination, int> Bot::getLonger(bridge::Hand const & hand) const
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

/*
 *	Check if you have already made a call in this bidding
 */
bool Bot::madeCall(bridge::Bidding const & bidding) const
{
	bool ret = false;

	auto history = bidding.getHistory();
	for (int i = history.size() - 4; i >= 0; i--)
	{
		if (history[i].type == bridge::CallType::BID)
		{
			ret = true;
			break;
		}
	}

	return ret;
}

/*
 *	Determine call based ONLY on your cards and your partner's call
 */
bridge::Call Bot::proposeCall(bridge::Bidding const & bidding, bridge::Hand const & hand)
{	
	if (madeCall(bidding)) return bridge::Call::PASS(); // it is a simple bidding - pass if you already said something

	if (isOpening(bidding)) // check if you are opening the bidding
	{
		int points = highCardPoints(hand); // counting hand-points (J = 1, Q = 2, K = 3, A = 4)
		auto longer = getLonger(hand); // longer = longest suit and its size

		if (points < 6) return bridge::Call::PASS(); // nearly no points - PASS
		else if (points < 12 && longer.second < 7) return bridge::Call::PASS(); // few points and no really long color - PASS
		else if (points < 12) return bridge::Call::BID(3, longer.first); // very long suit - call 3 with that suit
		else if (points > 14 && points < 18 && isBalanced(hand)) return bridge::Call::BID(1, bridge::Denomination::NT); // balanced hand and quite a few points - 1 NT
		else if (points < 18) return bridge::Call::BID(1, longer.first); // not balanced hand and/or not enough points - 1 with longer color
		else if (points > 20 && points < 24 && isBalanced(hand)) return bridge::Call::BID(2, bridge::Denomination::NT); // pretty many points and balanced hand - 2 NT
		else if (points < 25 && longer.second > 4) return bridge::Call::BID(2, longer.first); // not balanced hand/not so many points - 2 with longer color
		else return bridge::Call::BID(3, bridge::Denomination::NT); // lots of points - 3 NT
	}

	auto partnerCall = getPartnerCall(bidding);

	auto denomination = partnerCall.denomination;

	if (denomination == bridge::Denomination::NT)
	{
		int points = highCardPoints(hand);

		if (partnerCall.level == 1) points += 15;
		else if (partnerCall.level == 2) points += 21;
		else points += 25;

		if (points / 3 - 6 <= partnerCall.level) return bridge::Call::PASS();
		return bridge::Call::BID(points / 3 - 6, denomination);
	}

	int length = cardsInSuit(hand, (bridge::Suit)(int)denomination);

	if (length > 3) return bridge::Call::BID(partnerCall.level + length - 3, denomination);

	return bridge::Call::PASS();
}

/*
 *	Make a call in bidding
 */
bridge::Call Bot::makeCall(bridge::Bidding const & bidding, bridge::Hand const & hand)
{
	auto call = proposeCall(bidding, hand);
	call.level = std::min(call.level, 7);

	if (call.type == bridge::CallType::PASS)
	{
		return call;
	}

	auto history = bidding.getHistory();

	int it = history.size() - 1;
	while(it >= 0 && history[it].type != bridge::CallType::BID) it--;

	if (it >= 0)
	{
		auto lastCall = history[it];

		if (lastCall.level > call.level ||
			(lastCall.level == call.level && (int) lastCall.denomination > (int) lastCall.denomination))
		{
			return bridge::Call::PASS();
		}
	}

	return call;
}

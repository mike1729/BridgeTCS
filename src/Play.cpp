#include "Play.hpp"

bool operator==(Suit suit, Denomination denomination)
{
	return static_cast<int> (denomination)==static_cast<int> (suit);
}

/* true if attempterCard beats the winningCard */
bool Play::Trick::defeat(const Card& winningCard, const Card& attempterCard)
{
	if(winningCard.suit == attempterCard.suit  &&  winningCard.rank < attempterCard.rank)
		return true;
	if(attempterCard.suit == trump  &&  !(winningCard.suit == trump) )
		return true;
	return false;
}

bool arePartners(int player1, int player2)
{
	return player1%2 == player2%2;
}

void Play::Trick::add(Card && presentCard)
{
	cards.push_back(std::move(presentCard));
	/* check whether this card wins the trick so far i.e. whether it beats the presently winnig one */
	if(cards.size() == 1 || defeat( *presentWinningCard, presentCard))
	{
		presentWinner = presentPlayer;
		presentWinningCard = &(cards.back());
	}
	presentPlayer = (presentPlayer + 1)%4;
	sigModified(*this);
}

void Play::add(Card && card)
{
	currentTrick.add(std::move(card));
	if (currentTrick.full())
	{
		if(arePartners(currentTrick.getWinner(), declarer))
			tricksTaken++;
		history.push_back(std::move(currentTrick));
		currentTrick = std::move(Trick(trump, getLastTrickWinner()));
	}
	sigModified(*this);
}

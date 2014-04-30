#include "Play.hpp"

/***************************************************************/

/* true if attempterCard beats the winningCard */
bool Play::Trick::defeat(const Card& winningCard, const Card& attempterCard)
{
    if(winningCard.suit == attempterCard.suit  &&  winningCard.rank < attempterCard.rank)
        return true;
    if(attempterCard.suit == trump  &&  !(winningCard.suit == trump) )
        return true;
    return false;
}


void Play::Trick::add(const Card & presentCard)
{
	
	cards[ presentPlayer ] = &presentCard;
	
	/* check whether this card wins the trick so far i.e. whether it beats the presently winnig one */
	if(presentPlayer == initiator || defeat( *cards[presentWinner], presentCard))
		presentWinner = presentPlayer;
	
	presentPlayer = (presentPlayer + 1)%4;	
	 
}
/***************************************************************/


/* Returns the number of tricks taken. It's up to the caller to convert it into points result. */
int Play::performPlay (std::array <Arbiter, 4> & arbiters, Contract contract)
{
	int tricksTaken = 0;
	Denomination trump = contract.denomination;
    int declarer = contract.declarer;
    int lastRoundWinner = declarer;

	for (int trickNr = 0; trickNr < 13; trickNr++)
	{
        Trick trick(trump, lastRoundWinner);

		for (int i=0, playerInd = lastRoundWinner; i < 4; i++, playerInd = (playerInd + 1)%4 )
			trick.add( arbiters[playerInd].getCard() );

		lastRoundWinner = trick.getWinner();
        if(arePartners(lastRoundWinner, declarer))
            tricksTaken++;
	}
	return tricksTaken;
}


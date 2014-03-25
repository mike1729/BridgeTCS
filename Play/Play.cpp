#include "Play.hpp"

//TODO These two are temporary
bool operator ==(Card card,Denomination trump){
    return static_cast<int> (trump)==static_cast<int> (card.suit);
}
bool operator ==(Card card1,Card card2){
    return card1.suit==card2.suit;
}


inline bool arePartners(int player1, int player2)
{
    return player1%2 == player2%2;
}


/***************************************************************/
inline bool Play::Trick::defeat(const Card& winnerCard, const Card& attempterCard)
{
    if(winnerCard == attempterCard  &&  winnerCard.rank < attempterCard.rank)
        return true;
    if(attempterCard == trump  &&  !(winnerCard == trump) )
        return true;
    return false;
}


int Play::Trick::getWinner(){

    std::vector<PlayerAndCard>::iterator actualWinner = cards.begin(); //iterator tu to rozwiązanie tymczasowe z braku lepszego na ten moment

    for(std::vector<PlayerAndCard>::iterator it = cards.begin()+1; it != cards.end(); it++)
        if( defeat( actualWinner->card, it->card ))
            actualWinner = it;

    return actualWinner->player;
}
/***************************************************************/


/* Returns the number of tricks taken. It's up to the caller to convert it into points result. */
int Play::doPlay (Arbiter arbiters[], Contract contract)
{
	int tricksTaken = 0;
	Denomination trump = contract.trump;
    int declarer = contract.declarer;
    int lastRoundWinner = declarer;

	for (int trickNr = 0; trickNr < 13; trickNr++)
	{
        Trick trick(trump);

		for (int i=0, playerInd = lastRoundWinner; i < 4; i++, playerInd = (playerInd + 1)%4 )
		{
			Card actCard = arbiters[playerInd].getCard();
			trick.add(playerInd, actCard);
		}

		lastRoundWinner = trick.getWinner();
        if(arePartners(lastRoundWinner, declarer))
            tricksTaken++;
	}
	return tricksTaken;
}

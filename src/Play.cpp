#include "Play.hpp"
#include<iostream>




/***************************************************************/
bool Play::Trick::defeat(const Card & winnerCard, const Card & attempterCard)
{
	if(winnerCard.suit == attempterCard.suit  &&  winnerCard.rank < attempterCard.rank)
    {
        return true;
    }
    if(!(winnerCard.suit == trump) && attempterCard.suit == trump)
    {
    
    	return true;
    }
    return false;
}


int Play::Trick::getWinner()
{
	auto it = std::max_element(cards, defeat);
    /*std::vector<Card>::iterator actualWinner = cards.begin();

    for(std::vector<PlayerAndCard>::iterator it = cards.begin()+1; it != cards.end(); it++)
    {
    std::cout << static_cast<int>(it->card.suit) << " " << static_cast<int>(it->card.rank) <<"\n";
    
        if( defeat( actualWinner->card, it->card ))
            actualWinner = it;
	}
    return actualWinner->player;
    */
}
/***************************************************************/


/* Returns the number of tricks taken. It's up to the caller to convert it into points result. */
int Play::doPlay (std::array <Arbiter, 4> & arbiters, Contract contract)
{
	int tricksTaken = 0;
	Denomination trump = contract.denomination;
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


#ifndef Play_hpp
#define Play_hpp

#include <vector>
#include <array>

#include "Card.hpp"
#include "Contract.hpp"
#include "Arbiter.hpp"
#include<iostream>
#include<algorithm>

class Play
{

	//pair<int, Card>
 	#if 0
 	struct PlayerAndCard
    {
        int player;
        const Card & card;
        PlayerAndCard(int player, const Card & card) : player(player), card(card) {
        std::cout << "aaabbb" << static_cast<int>(card.rank) << " " << static_cast<int>(card.suit) <<"\n";	
    
	}
    };
    #endif

/***************************************************************/
public:
	/* Returns the number of tricks taken. It's up to the caller to convert it into points result. */
	int doPlay (std::array <Arbiter, 4> & arbiters, Contract contract);

    class Trick
    {
    public:

        Trick(Denomination trump, int initiator) : trump(trump), initiator(initiator) {}

        void add(const Card & card)
        {
            cards.emplace_back(card);
        }

        int getWinner();
    private:
        std::vector<Card> cards;
        Denomination trump;
	    int initiator;
	    inline bool defeat(const Card &, const Card &);

	    
	
    };
/***************************************************************/

private:

   
	bool arePartners(int player1, int player2)
	{
		return player1%2 == player2%2;
	}
	
	
	/*friend class TrickTest;
    FRIEND_TEST(TrickTest, Adding);
    FRIEND_TEST(TrickTest, NoTrump1);
    FRIEND_TEST(TrickTest, NoTrump2);
*/
};


inline bool operator ==(Suit suit, Denomination trump)
{
	return static_cast<int> (trump)==static_cast<int> (suit);
}

#endif

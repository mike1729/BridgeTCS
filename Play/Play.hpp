#ifndef Play_hpp
#define Play_hpp

#include <vector>

#include "../Deck/Card.hpp"
#include "../Bidding/Contract.hpp"
#include "../Rubber/Arbiter.hpp"



class Play
{

	//pair<int, Card>
 	struct PlayerAndCard
    {
        int player;
        const Card & card;
        PlayerAndCard(int player, const Card & card) : player(player), card(card) {}
    };

/***************************************************************/
public:
	/* Returns the number of tricks taken. It's up to the caller to convert it into points result. */
	int doPlay (Arbiter arbiters[], Contract contract);

    class Trick
    {
    public:

        Trick(Denomination trump) : trump(trump) {}

        void add(int player, const Card & card)
        {
            cards.push_back(PlayerAndCard(player, card));
        }

        int getWinner();
    private:
        std::vector<PlayerAndCard> cards;
	    Denomination trump;
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

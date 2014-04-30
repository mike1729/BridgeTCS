#ifndef Play_hpp
#define Play_hpp

#include <vector>
#include <array>
#include <functional>

#include "Card.hpp"
#include "Contract.hpp"
#include "Arbiter.hpp"

class Play
{

/***************************************************************/
public:
	/* Returns the number of tricks taken. It's up to the caller to convert it into points result. */
	int performPlay (std::array <Arbiter, 4> & arbiters, Contract contract);

    class Trick
    {
    public:

        Trick(Denomination trump, int initiator) : trump(trump), initiator(initiator) {
        	presentPlayer = initiator;
        }

        void add(const Card & card);
        
        int getWinner() {
		
       		return presentWinner;
        }
    private:
        std::array<const Card *, 4> cards;
        Denomination trump;
	    int initiator, presentPlayer, presentWinner;
	    inline bool defeat(const Card &, const Card &);

    };

/***************************************************************/

private:

	bool arePartners(int player1, int player2) {
		return player1%2 == player2%2;
	}
	
};


inline bool operator ==(Suit suit, Denomination trump) {
	return static_cast<int> (trump)==static_cast<int> (suit);
}

#endif

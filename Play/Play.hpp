#ifndef Play_hpp
#define Play_hpp

#include <vector>
//#include <gtest/gtest.h>

#include "../Deck/Card.hpp"
#include "../Bidding/Contract.hpp"
#include "../Rubber/Arbiter.hpp"




class Play
{
/***************************************************************/
    struct PlayerAndCard
    {
        int player;
        const Card & card;
        PlayerAndCard(int player, const Card & card) : player(player), card(card) {}
    };

    class Trick {
        std::vector<PlayerAndCard> cards;
        Denomination trump;
        inline bool defeat(const Card &, const Card &);

        public:

            Trick(Denomination trump) : trump(trump) {}

            void add(int player, const Card & card)
            {
                cards.push_back(PlayerAndCard(player, card));
            }

            int getWinner();
    };
/***************************************************************/

public:
	/* Returns the number of tricks taken. It's up to the caller to convert it into points result. */
	int doPlay (Arbiter arbiters[], Contract contract);

	/*friend class TrickTest;
    FRIEND_TEST(TrickTest, Adding);
    FRIEND_TEST(TrickTest, NoTrump1);
    FRIEND_TEST(TrickTest, NoTrump2);
*/
};

#endif

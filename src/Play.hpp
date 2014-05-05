#ifndef Play_hpp
#define Play_hpp

#include <array>
#include <list>
#include <utility>

#include "Card.hpp"
#include "Contract.hpp"
#include "ui/Observable.hpp"

class Play: public ui::Observable
{
	public:
		Play(Denomination trump, int declarer) : trump(trump), declarer(declarer), currentTrick(trump, declarer)
		{
		}

		class Trick: public ui::Observable
		{
			public:
				Trick(Denomination trump, int initiator) : trump(trump), presentPlayer(initiator) 
				{
				}

				Trick(Trick && t) = default;

				Trick(Trick const & trick) = delete;

				Trick & operator=(Trick && other) = default;

				void add(Card && card);

				bool full()
				{
					return (cards.size() == 4);
				}

				int getWinner()
				{
					return presentWinner;
				}
			private:
				std::list<Card> cards;
				Denomination trump;
				int presentPlayer, presentWinner;
				Card * presentWinningCard;

				bool defeat(const Card& winningCard, const Card& attempterCard);
		};

		using History = std::list<Trick>;

		int getLastTrickWinner()
		{
			return history.back().getWinner();
		}

		int getTricksTaken()
		{
			return tricksTaken;
		}

		// The card given gets played. No validation -- validating is almost
		// impossible with non-copyable cards.
		void add(Card && card);

	private:
		Denomination trump;
		int declarer;
		Trick currentTrick;
		int tricksTaken = 0;
		History history;
};
#endif

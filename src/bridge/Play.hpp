#ifndef BRIDGE_PLAY_HPP
#define BRIDGE_PLAY_HPP

#include <array>
#include <list>
#include <utility>

#include "Card.hpp"
#include "Contract.hpp"
#include "ui/Observable.hpp"

namespace bridge {

class Play: public ui::Observable<Play>
{
	public:
		Play(Denomination trump, int declarer) : trump(trump), declarer(declarer), currentTrick(trump, declarer)
		{
		}

		class Trick: public ui::Observable<Trick>
		{
			public:
				Trick(Denomination trump, int initiator) : presentPlayer(initiator), trump(trump) , initiator(initiator)
				{
				}

				Trick(Trick && t) = default;

				Trick(Trick const & trick) = delete;

				Trick & operator=(Trick && other) = default;

				void add(Card && card);

				bool full() const
				{
					return (cards.size() == 4);
				}

				int getWinner() const
				{
					return presentWinner;
				}
				
				std::list<Card> const & getCards() const
				{
					return cards;
				}
				
				Denomination getTrump() const
				{
					return trump;
				}
				
				int getInitiator() const
				{
					return initiator;
				}

				
			private:
				std::list<Card> cards;
				int presentPlayer, presentWinner;
				Card * presentWinningCard;
				Denomination trump;
				int initiator;
				
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
		
		const Trick & getTrick()
		{
			return currentTrick;
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

}
#endif

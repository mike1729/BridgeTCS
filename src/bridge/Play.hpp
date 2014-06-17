#ifndef BRIDGE_PLAY_HPP
#define BRIDGE_PLAY_HPP

#include <array>
#include <list>
#include <memory>
#include <utility>

#include "Card.hpp"
#include "Contract.hpp"
#include "ui/Observable.hpp"

namespace bridge {

class Play: public ui::Observable<Play>
{
	public:
		Play(Denomination trump, int declarer) : trump(trump), declarer(declarer), currentTrick( new Trick(trump, (declarer+1) % 4) )
		{
		}

		class Trick: public ui::Observable<Trick>
		{
			public:
				Trick(Denomination trump, int initiator) : presentPlayer(initiator), trump(trump) , initiator(initiator)
				{
				}

				void add(Card card);

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

		using History = std::list< std::unique_ptr<Trick> >;

		int getLastTrickWinner()
		{
			return history.back()->getWinner();
		}

		int getTricksTaken()
		{
			return tricksTaken;
		}
		
		const Trick & getTrick() const
		{
			return *currentTrick;
		}

		const History & recentHistory() const
		{
			return history; //TODO return up to last 8 tricks
		}

		void add(Card card);

	private:
		Denomination trump;
		int declarer;
		std::unique_ptr<Trick> currentTrick;
		int tricksTaken = 0;
		History history;
};

} //namespace bridge
#endif

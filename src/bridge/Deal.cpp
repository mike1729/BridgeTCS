#include "Deal.hpp"
#include "Deck.hpp"

namespace bridge 
{

void Deal::dealCards()
{
	Standard52Deck deck;
	for (int currentPlayer = firstCaller; deck.cardsLeft(); currentPlayer = (currentPlayer+1) % 4)
	{
		hands[currentPlayer].insert(deck.dealCard());
	}
	event = DealEvent::CardsDealt;
	sigModified(*this);
}

Contract Deal::performBidding() 
{
	bidding.reset(new Bidding(firstCaller));
	event = DealEvent::BiddingStart;
	sigModified(*this);
	for (int currentCaller = firstCaller; !bidding->Done(); currentCaller = (currentCaller+1)%4)
	{
		Call currentCall = arbiters[currentCaller].getCall(*bidding, hands[currentCaller]);
		bidding->makeCall(currentCall);
	}
	contract = bidding->getContract();
	event = DealEvent::BiddingEnd;
	sigModified(*this);
	return contract;
}

DealResult Deal::performPlay()
{
	play.reset(new Play(contract.denomination, contract.declarer));
	result.contract = contract;
	event = DealEvent::PlayStart;
	sigModified(*this);
	int currentPlayer = contract.declarer;
	for (int trick = 0; trick < 13; trick++)
	{
		Card firstCard = arbiters[currentPlayer].getCard(*play.get(), hands[currentPlayer], bidding->getHistory(), play->recentHistory(), hands[(contract.declarer + 2) % 4]);
		Suit firstCardSuit = firstCard.suit;
		play->add(std::move(firstCard));
		for (int i = 0; i < 3; i++)
		{
			currentPlayer = (currentPlayer+1)%4;
			play->add(arbiters[currentPlayer].getCard(*play.get(), hands[currentPlayer], bidding->getHistory(), play->recentHistory(), hands[(contract.declarer + 2) % 4], firstCardSuit));
		}
		currentPlayer = play->getLastTrickWinner();
	}
	result.declarerTakenTricks = play->getTricksTaken();
	event = DealEvent::PlayEnd;
	sigModified(*this);
	return result;
};

} // namespace bridge

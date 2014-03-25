#include "Deck.hpp"

Standard52Deck::Standard52Deck()
{
	for (int s = (int) Suit::CLUBS; s <= (int) Suit::SPADES; ++s)
	for (int r = (int) Rank::TWO; r <= (int) Rank::ACE; ++r)
		allCards.push_back(Card((Rank) r, (Suit) s));
	for (size_t i = 0; i < allCards.size(); ++i)
		deck.push_back(&allCards[i]);
}

void Standard52Deck::shuffle()
{
	std::random_shuffle(deck.begin(), deck.end());
}

Card Standard52Deck::dealCard()
{
	Card card = *deck.back();
	deck.pop_back();
	return card;
}

int Standard52Deck::cardsLeft()
{
	return deck.size();
}

bool Standard52Deck::empty()
{
	return deck.size() == 0;
}
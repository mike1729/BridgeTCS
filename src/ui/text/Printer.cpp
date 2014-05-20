#include "Printer.hpp"
#include <iostream>

namespace ui
{
namespace text
{

std::string Printer::suitSymbols[] = {"\u2663", "\u2666", "\u2665", "\u2660"};
char Printer::rankSymbols[] = {'2','3','4','5','6','7','8','9','T','J','Q','K','A'};

inline void Printer::print(bridge::Rank const & rank)
{
	std::cout << rankSymbols[(int) rank];
}

inline void Printer::print(bridge::Suit const & suit)
{
	std::cout << suitSymbols[(int) suit];
}

inline void Printer::print(bridge::Hand const & hand)
{
	std::cout << "Your cards:\n";
	
	for(auto & card : hand.getCards())
	{
		Printer::print(card.rank);
		Printer::print(card.suit);
		std::cout << "\n";
	}

	std::cout << std::endl;
}

inline void Printer::print(bridge::Play::Trick const & trick)
{
	std::cout << "Current Trick:\n";
	int currentPlayer = trick.getInitiator();
	for(auto & card : trick.getCards())
	{
		std::cout << "\tPlayer " << currentPlayer + 1 << ":";

		Printer::print(card.rank);
		Printer::print(card.suit);
		
		std::cout << std::endl;
		
		currentPlayer = (currentPlayer + 1)%4;
	}
	if(trick.full())
		std::cout << "Player " << trick.getWinner() + 1 << "won this trick.\n";
	else
		std::cout << "Player " << trick.getWinner() + 1 << "leading.\n";
	
	std::cout << std::endl;
}

}
}
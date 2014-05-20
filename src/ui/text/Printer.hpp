#ifndef UI_TEXT_PRINTER_HPP
#define UI_TEXT_PRINTER_HPP

#include "bridge/Card.hpp"
#include "bridge/Hand.hpp"
#include "bridge/Play.hpp"

namespace ui
{
namespace text
{

class Printer
{
	static std::string suitSymbols[];
	static char rankSymbols[];
public:
	inline static void print(bridge::Rank const & rank)
	{
		std::cout << rankSymbols[(int) rank];
	}
	inline static void print(bridge::Suit const & suit)
	{
		std::cout << suitSymbols[(int) suit];
	}

	inline static void print(bridge::Hand const & hand)
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

	inline static void print(bridge::Play::Trick const & trick)
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
};

} // namespace text
} // namespace ui

#endif

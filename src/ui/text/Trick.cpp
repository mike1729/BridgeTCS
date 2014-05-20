#include "Trick.hpp"
#include "Printer.hpp"

namespace ui 
{
namespace text 
{

void Trick::print(const bridge::Play::Trick & trick)
{
	std::cout << "Current Trick:\n";
	int currentPlayer = trick.getInitiator();
	for(auto & card : trick.getCards())
	{
		std::cout << "\tPlayer " << currentPlayer + 1 << ":" << Printer::print(card.rank) << " " << Printer::print(card.suit) << "\n";
		currentPlayer = (currentPlayer + 1)%4;
	}
	if(trick.full())
		std::cout << "Player " << trick.getWinner() + 1 << "won this trick.\n";
	else
		std::cout << "Player " << trick.getWinner() + 1 << "leading.\n";
	std::cout << "\n";
}

} // namespace text
} // namespace ui

#include <iostream>
#include "Hand.hpp"
#include "Printer.hpp"

namespace ui 
{
namespace text 
{

void Hand::print(const bridge::Hand & hand)
{
	std::cout << "Your cards:\n";
	for(auto & card : hand.getCards())
		std::cout << Printer::print(card.rank) << " " << Printer::print(card.suit) << "\n";
	std::cout << "\n";
}

} // namespace text
} // namespace ui

#include <iostream>
#include "Hand.hpp"

namespace ui 
{
namespace text 
{

void Hand::print(const bridge::Hand & hand)
{
	std::cout << "Your cards:\n";
	for(auto & card : hand.getCards())
		std::cout << static_cast<int>(card.rank) << " " 
		          << static_cast<int>(card.suit) << "\n";
	std::cout << "\n";
}

} // namespace text
} // namespace ui

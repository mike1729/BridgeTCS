#include "Hand.hpp"

namespace ui 
{
namespace text 
{

void Hand::print(const bridge::Hand & hand)
{
	std::cout << "Your cards:\n";
	for(auto & card : hand.getList())
		std::cout << card.rank << " " << card.suit << "\n";
	std::cout << "\n";
}

} // namespace text
} // namespace ui

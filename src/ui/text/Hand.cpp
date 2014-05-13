#include "ui/Observer.hpp"
#include "Hand.hpp"
#include <iostream>

namespace ui 
{
namespace text 
{

void Hand::notify(const ::Hand & hand)
{
	std::cout << "Your cards:\n";
	for(auto & card : hand.getList())
		std::cout << card.rank << " " << card.suit << "\n";
	std::cout << "\n";
}

} // namespace text
} // namespace ui

#include <iostream>
#include "Hand.hpp"
#include "Printer.hpp"

namespace ui 
{
namespace text 
{

void Hand::print(const bridge::Hand & hand)
{
	Printer::print(hand);
}

} // namespace text
} // namespace ui

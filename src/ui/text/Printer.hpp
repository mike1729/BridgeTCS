#ifndef UI_TEXT_PRINTER_HPP
#define UI_TEXT_PRINTER_HPP

#include <iostream>
#include "bridge/Card.hpp"

namespace ui
{
namespace text
{

class Printer
{
	static std::string suitSymbols[];
	static char rankSymbols[];
public:
	static std::ostream& print(bridge::Rank const & rank)
	{
		return std::cout << rankSymbols[(int) rank];
	}

	static std::ostream& print(bridge::Suit const & suit)
	{
		return std::cout << suitSymbols[(int) suit];
	}
};

} // namespace text
} // namespace ui

#endif

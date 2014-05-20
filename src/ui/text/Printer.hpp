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
	inline static void print(bridge::Rank const &);
	inline static void print(bridge::Suit const &);
	inline static void print(bridge::Hand const &);
	inline static void print(bridge::Play::Trick const &);
};

} // namespace text
} // namespace ui

#endif

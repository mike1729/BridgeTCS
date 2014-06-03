#ifndef UI_TEXT_PRINTER_HPP
#define UI_TEXT_PRINTER_HPP

#include "bridge/Card.hpp"
#include "bridge/Hand.hpp"
#include "bridge/Play.hpp"
#include "bridge/Call.hpp"
#include "bridge/Bidding.hpp"

namespace ui
{
namespace text
{

class Printer
{
	static std::string suitSymbols[];
	static std::string rankSymbols[];

public:
	inline static void print(bridge::Rank const & rank)
	{
		std::cout << rankSymbols[(int) rank];
	}
	inline static void print(bridge::Suit const & suit)
	{
		std::cout << suitSymbols[(int) suit];
	}
	inline static void print(bridge::Denomination const & denomination)
	{
		int nr = static_cast<int>(denomination);
		if(nr == 4) std::cout << "NT";
		else std::cout << suitSymbols[nr];
	}

	static void print(bridge::Call const & call);
	static void print(bridge::Hand const & hand);
	static void print(bridge::Play::Trick const & trick);
	static void print(bridge::Bidding const & bidding);
    static void print(bridge::Card const & card);
};

} // namespace text
} // namespace ui

#endif

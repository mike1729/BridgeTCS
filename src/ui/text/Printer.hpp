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
	inline static void print(bridge::Denomination const & denomination)
	{
		int nr = static_cast<int>(denomination);
		if(nr == 5) std::cout << "NT";
		else std::cout << suitSymbols[nr];
	}

	inline static void print(bridge::Call const & call)
	{
		bridge::CallType callType = call.type;
		if(callType == bridge::CallType::BID)
		{
			std::cout << call.level << " ";
			Printer::print(call.denomination);
			std::cout << "\n";
		}
		else if(callType == bridge::CallType::DOUBLE)
			std::cout << "Double\n";
		else if(callType == bridge::CallType::REDOUBLE)
			std::cout << "Redouble\n";
		else if(callType == bridge::CallType::PASS)
			std::cout << "PASS\n";
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
	
	inline static void print(bridge::Bidding const & bidding)
	{
		std::cout << "Player " << bidding.getCurrentCaller() << ": ";
		bridge::Call call = bidding.getLastCall();
		Printer::print(call); 
	}
};

} // namespace text
} // namespace ui

#endif

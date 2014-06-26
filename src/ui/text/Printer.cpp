#include "Printer.hpp"
#include <iostream>
#include <vector>

namespace ui
{
namespace text
{

#ifdef BRIDGE_UNICODE
std::string Printer::suitSymbols[] = {"\u2663", "\u2666", "\u2665", "\u2660"};
#else
char Printer::suitSymbols[] = {'C', 'D', 'H', 'S'};
#endif

char Printer::rankSymbols[] = {'2','3','4','5','6','7','8','9','T','J','Q','K','A'};


/*static*/ void Printer::print(bridge::Call const & call)
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

/*static*/ void Printer::print(bridge::Hand const & hand)
{
	bridge::Suit suits[] = {
		bridge::Suit::SPADES,
		bridge::Suit::HEARTS,
		bridge::Suit::DIAMONDS,
		bridge::Suit::CLUBS
	};

	auto cardsIt = hand.getCards().rbegin();
	auto endIt = hand.getCards().rend();

	for (auto & suit : suits)
	{
		if (suit == bridge::Suit::HEARTS or 
			suit == bridge::Suit::DIAMONDS)
	    	std::cout<< "\e[1;31m"; // red
	    else
			std::cout<<"\e[1;30m"; // black 
		Printer::print(suit);
		std::cout << ": ";
		while (cardsIt != endIt && cardsIt->suit == suit)
		{
			Printer::print(cardsIt->rank);
			std::cout << " ";
			cardsIt++;
		}
		std::cout << "\n";
	}
	std::cout<<"\e[0m";
	std::cout << "\n";
}

/*static*/ void Printer::print(bridge::Play::Trick const & trick)
{
	std::cout << "Current Trick:\n";
	int currentPlayer = trick.getInitiator();
	
	for(auto & card : trick.getCards())
	{
		std::cout << "\tPlayer " << currentPlayer + 1 << ":";
        Printer::print(card);

		std::cout << std::endl;
		
		currentPlayer = (currentPlayer + 1)%4;
	}
	
	if(trick.full())
		std::cout << "Player " << trick.getWinner() + 1 << " won this trick.\n";
	else
		std::cout << "Player " << trick.getWinner() + 1 << " leading.\n";
		
	std::cout << std::endl;
}
	
/*static*/ void Printer::print(bridge::Bidding const & bidding)
{
	std::cout << "Player " << (bidding.getCurrentCaller() + 3)%4 + 1 << ": ";
	bridge::Call call = bidding.getLastCall();
	Printer::print(call); 
}

/*static*/ void Printer::print(bridge::Card const & card)
{
    if (card.suit == bridge::Suit::HEARTS or card.suit == bridge::Suit::DIAMONDS)
        std::cout<< "\e[1;31m"; // red
    else
        std::cout<<"\e[1;30m"; // black 
    
    Printer::print(card.rank);
    Printer::print(card.suit);
    std::cout<<"\e[0m";
}

} //namespace text
} //namespace ui

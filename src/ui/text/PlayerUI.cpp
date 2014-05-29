#include "PlayerUI.hpp"
#include "Printer.hpp"

namespace ui 
{
namespace text 
{

//using BiddingHistory, PlayHistory
bridge::Card PlayerUI::chooseCard(bridge::Bidding const & bidding, bridge::Play const & play, bridge::Hand const & hand, bridge::Hand const & dummyHand)
{
	hand.sigModified(hand);
	while(true)
	{
		std::cout << "Throw a card.\nFormat: [2-10|j|q|k|a] [1-4]\n";
		std::string rankStr, delimiter = " ";
		std::cin >> rankStr;
		bridge::Rank rank;
		if(rankStr == "j") rank = bridge::Rank::JACK;
		else if(rankStr == "q") rank = bridge::Rank::QUEEN;
		else if(rankStr == "k") rank = bridge::Rank::KING;
		else if(rankStr == "a") rank = bridge::Rank::ACE;
		else
		{
			int rankInt;
			try {
				rankInt = std::stoi(rankStr);
			} catch (...)
			{
				std::cout << "Wrong format\n";
				continue;
			}
			if(rankInt<= 10 && rankInt >= 2)
				rank = static_cast<bridge::Rank>(std::stoi(rankStr));
			else 
			{
				std::cout << "Wrong rank format.\n";
				continue;
			}
		}
		
		bridge::Suit suit;
		std::string suitStr;
		std::cin >> suitStr;
		int suitInt;
		try {
			suitInt = std::stoi(suitStr);
		} catch (...)
		{
			std::cout << "Wrong format\n";
			continue;
		}
		if(suitInt >=1 && suitInt<=4)
			suit = static_cast<bridge::Suit>(suitInt);
		else
		{
			std::cout << "Wrong suit format.\n";
			continue;
		}
		
		return bridge::Card(rank, suit);
	}
}

bridge::Card PlayerUI::chooseCardFromDummy(bridge::Bidding const &, bridge::Play const &, bridge::Hand const &, bridge::Hand const &)
{
	return bridge::Card(bridge::Rank::ACE, bridge::Suit::SPADES);
}

bridge::Call PlayerUI::makeCall(bridge::Bidding const & bidding, bridge::Hand const & hand)
{
	while(true)
	{
		hand.sigModified(hand);
		std::cout << "Make a bid\nFormat: [1-7] [1-5] | p[ass] | d[ouble] | r[edouble]\n";
		
		std::string in;
		std::cin >> in;
		if(in[0] == 'p') return bridge::Call::PASS();
		if(in[0] == 'd') return bridge::Call::DOUBLE();
		if(in[0] == 'r') return bridge::Call::REDOUBLE();
		int level;
		try {
			level = std::stoi(in);
		} catch (...)
		{
			std::cout << "Wrong format\n";
			continue;
		}
		if(level > 7 || level < 1)
		{
			std::cout << "Wrong level\n";
			continue;
		}
		
		
		int denominationInt;
		std::string denominationStr;
		std::cin >> denominationStr;
		bridge::Denomination denomination;
		try {
			denominationInt = std::stoi(denominationStr);
		} catch (...)
		{
			std::cout << "Wrong format\n";
			continue;
		}
		if(denominationInt <= 5 && denominationInt >= 1)
			denomination = static_cast<bridge::Denomination>(denominationInt - 1);
		else
		{
			std::cout << "Wrong denomination\n";
			continue;
		}
		
		std::cout << level << " ";
		Printer::print(denomination);
		std::cout << std::endl;
		return bridge::Call::BID(level, denomination);
	}
}

} // namespace text
} // namespace ui

#include "PlayerUI.hpp"
#include "Printer.hpp"

namespace ui 
{
namespace text 
{

bridge::Card chooseAndParseCard(bool fromDummy=false)
{
	while(true)
	{
		if(!fromDummy)
			std::cout << "Throw a card.\nFormat: [2-9|t|j|q|k|a] [c|d|h|s]\n";
		else
			std::cout << "Throw a card from Dummy.\nFormat: [2-9|t|j|q|k|a] [c|d|h|s]\n";
		
		char rankStr;
		std::cin >> rankStr;
		bridge::Rank rank;
		
		if(rankStr == 't')
			rank = bridge::Rank::TEN;
		else if(rankStr == 'j')
			rank = bridge::Rank::JACK;
		else if(rankStr == 'q')
			rank = bridge::Rank::QUEEN;
		else if(rankStr == 'k')
			rank = bridge::Rank::KING;
		else if(rankStr == 'a')
			rank = bridge::Rank::ACE;
		else
		{
			int rankInt = rankStr-'0';
			if(rankInt<= 9 && rankInt >= 2)
				rank = static_cast<bridge::Rank>(rankInt - 2);
			else
			{
				std::cout << "Wrong rank format.\n";
				continue;
			}
		}
		
		bridge::Suit suit;
		char suitStr;
		std::cin >> suitStr;
		
		if(suitStr == 'c')
			suit = bridge::Suit::CLUBS;
		else if(suitStr == 'd')
			suit = bridge::Suit::DIAMONDS;
		else if(suitStr == 'h')
			suit = bridge::Suit::HEARTS;
		else if(suitStr == 's')
			suit = bridge::Suit::SPADES;
		else
		{
			std::cout << "Wrong suit format.\n";
			continue;
		}

		return bridge::Card(rank, suit);
	}
}

//using BiddingHistory, PlayHistory
bridge::Card PlayerUI::chooseCard(bridge::Bidding const &, bridge::Play const &, bridge::Hand const & hand, bridge::Hand const * dummyHand)
{
	
	if (dummyHand!=nullptr)
	{
		std::cout << "Dummy Hand:\n";
		Printer::print(*dummyHand);
	}

	Printer::print(hand);

	return chooseAndParseCard();
}

bridge::Card PlayerUI::chooseCardFromDummy(bridge::Bidding const &, bridge::Play const &, bridge::Hand const & hand, bridge::Hand const & dummyHand)
{
	Printer::print(hand);

	std::cout << "Dummy Hand:\n";
	Printer::print(dummyHand);

	return chooseAndParseCard(true);
}

bridge::Call PlayerUI::makeCall(bridge::Bidding const &, bridge::Hand const & hand)
{
	while(true)
	{
		Printer::print(hand);
		std::cout << "Make a bid\nFormat: [1-7] [1-5] | p[ass] | d[ouble] | r[edouble]\n";
		
		std::string in;
		std::cin >> in;
		
		if(in[0] == 'p')
			return bridge::Call::PASS();
		
		if(in[0] == 'd')
			return bridge::Call::DOUBLE();
		
		if(in[0] == 'r')
			return bridge::Call::REDOUBLE();
		
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

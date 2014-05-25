#include "PlayerUI.hpp"

namespace ui 
{
namespace text 
{


//using BiddingHistory, PlayHistory
bridge::Card PlayerUI::chooseCard(bridge::Play const & play, bridge::Hand const & hand, BiddingHistory const & biddignHistory, PlayHistory const & playHistory, bridge::Hand const & partnerHand)
{
	hand.sigModified(hand);
	while(true)
	{
		std::cout << "Throw a card.\nFormat: [2-10|j|q|k|a] [1-4]\n";
		std::string in, delimiter = " ";
		std::cin >> in;
		std::string rankStr = in.substr(0, in.find(delimiter));
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
		std::string suitStr = in.substr(in.find(delimiter)+1);
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

bridge::Call PlayerUI::makeCall(bridge::Bidding const & bidding, bridge::Hand const & hand)
{
	while(true)
	{
		std::cout << "Make a bid\nFormat: [1-7] [1-5] | p[ass] | d[ouble] | r[edouble]\n";
		std::string in, delimiter = " ";
		std::cin >> in;
		if(in[0] == 'p') return bridge::Call::PASS();
		if(in[0] == 'd') return bridge::Call::DOUBLE();
		if(in[0] == 'r') return bridge::Call::REDOUBLE();
		int level;
		try {
			level = std::stoi(in.substr(0, in.find(delimiter)));
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
		bridge::Denomination denomination;
		try {
			denominationInt = std::stoi(in.substr(in.find(delimiter)+1));
		} catch (...)
		{
			std::cout << "Wrong format\n";
			continue;
		}
		if(denominationInt <= 5 && denominationInt >= 1)
			denomination = static_cast<bridge::Denomination>(denominationInt);
		else
		{
			std::cout << "Wrong denomination\n";
			continue;
		}
		
		return bridge::Call::BID(level, denomination);
	}
}

} //text
} //ui

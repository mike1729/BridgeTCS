#ifndef UI_PLAYERUI_DEAL_HPP
#define UI_PLAYERUI_DEAL_HPP

#include "bridge/Hand"
#include "bridge/Player"
#include "bridge/Card"
#include "bridge/Call"
#include <iostream>
#include <string>

namespace ui
{
namespace text
{
class PlayerUI : bridge::IPlayer
{
public:
//    using BiddingHistory = std::vector<Call>;
//    using PlayHistory = std::list<Play::Trick>;
	Card chooseCard(Play const &, Hand const &, BiddingHistory const &, PlayHistory const &, Hand const &)
	{
		hand.sigModified(hand);
		while(true)
		{
			std::cout << "Throw a card.\nFormat: [2-10|j|q|k|a] [1-4]\n";
			std::string in, delimiter = " ";
			std::cin >> in;
			std::string rankStr = in.substr(0, s.find(delimiter));
			Rank rank;
			if(rankStr == "j") rank = Rank::JACK;
			else if(rankStr == "q") rank = Rank::QUEEN;
			else if(rankStr == "k") rank = Rank::KING;
			else if(rankStr == "a") rank = Rank::ACE;
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
					rank = static_cast<Rank>(std::stoi(rankStr));
				else 
				{
					std::cout << "Wrong rank format.\n";
					continue;
				}
			}
			
			Suit suit;
			std::string suitStr = in.substr(s.find(delimiter)+1);
			int suitInt;
			try {
				suitInt = std::stoi(suitStr);
			} catch (...)
			{
				std::cout << "Wrong format\n";
				continue;
			}
			if(suitInt >=1 && suitInt<=4)
				suit = static_cast<Suit>(suitInt);
			else
			{
				std::cout << "Wrong suit format.\n";
				continue;
			}
			
			return Card(rank, suit);
		}
	}
	
	Call makeCall(Bidding const &, Hand const &)
	{
		while(true)
		{
			std::cout << "Make a bid\nFormat: [1-7] [1-5] | p[ass] | d[ouble] | r[edouble]\n";
			std::string in, delimiter = " ";
			std::cin >> in;
			if(in[0] == 'p') return Call.PASS();
			if(in[0] == 'd') return Call.DOUBLE();
			if(in[0] == 'r') return Call.REDOUBLE();
			int level;
			try {
				level = std::stoi(in.substr(0, s.find(delimiter)));
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
			Denomination denomination;
			try {
				denominationInt = std::stoi(in.substr(s.find(delimiter)+1));
			} catch (...)
			{
				std::cout << "Wrong format\n";
				continue;
			}
			if(denominationInt <= 5 && denominationInt >= 1)
				denomination = static_cast<Denomination>(denominationInt);
			else
			{
				std::cout << "Wrong denomination\n";
				continue;
			}
			
			return Call.BID(level, denomination);
		}
	}

	
};
}
}


#endif

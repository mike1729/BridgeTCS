#ifndef UI_TEXT_BIDDING_HPP
#define UI_TEXT_BIDDING_HPP

#include "bridge/Bidding.hpp"
#include "bridge/Contract.hpp"
#include "Printer.hpp"


namespace ui
{
namespace text
{
class Bidding
{
public:
	void print(const bridge::Bidding & bidding)
	{
		Printer::print(bidding);
	}
private:
	
};
} //namespace text
} //namespace ui


#endif

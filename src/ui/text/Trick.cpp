#include "Trick.hpp"
#include "Printer.hpp"

namespace ui 
{
namespace text 
{

void Trick::print(const bridge::Play::Trick & trick)
{
	Printer::print(trick);
}

} // namespace text
} // namespace ui

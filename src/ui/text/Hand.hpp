#ifndef UI_TEXT_HAND_HPP
#define UI_TEXT_HAND_HPP

#include "ui/Observer.hpp"

namespace ui
{
namespace text
{

class Hand : public Observer<::Hand>
{
private:
    const std::list<Card> & cards;

};


} // namespace text
} // namespace ui

#endif

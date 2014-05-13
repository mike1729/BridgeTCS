#ifndef Hand_hpp
#define Hand_hpp

#include "ui/Observer.hpp"
#include "bridge/model/Contract.hpp"

namespace ui
{
namespace text
{

class Trick : public Observer<::Trick>
{
};

} // namespace text
} // namespace ui

#endif

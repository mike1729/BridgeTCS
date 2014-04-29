#ifndef Hand_hpp
#define Hand_hpp

#include "../Observer.hpp"

namespace ui
{
    namespace text
    {
        class Hand : public Observer
        {
            const ::Hand & hand;
        public:
            Hand(const ::Hand & hand) : hand(hand) {}    
        };
    }
}


#endif

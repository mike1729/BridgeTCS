#include "../Observer.hpp"
#include "Hand.hpp"
#include <iostream>

namespace ui {
    namespace text {

        void Hand::notify()
        {
            printHand();
        }
        void Hand::printHand()
        {
            std::cout << "Your cards:\n";
            for(auto & card : hand.getList())
                std::cout << card.rank << " " << card.suit << "\n";
            std::cout << "\n";
        }
    }
}

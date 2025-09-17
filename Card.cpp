#include "Header.h"

#ifdef FOO
//Overload the operate<< so std::cout would print the full rank & suit of a card when passed a "Card"-type object
friend std::ostream& operator<<(std::ostream& out, const Card& card)
    {
        static constexpr std::array ranks{ 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K' };
        static constexpr std::array suits{ 'C', 'D', 'H', 'S' };

        out << ranks[card.rank] << suits[card.suit];
        return out;
    }
#endif

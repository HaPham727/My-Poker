#include "Header.h"

class Deck
{
private: //The "Deck"-type object has 2 variables stuck to it: a "Card"-type array of all cards it (can) hold, and an index for the next card to be taken out
    std::array<Card, 52> m_cards{};
    std::size_t m_nextCardIndex{ 0 };

public:
    Deck() //Contructore function to create the m_cards array
    {
        std::size_t count{ 0 };
        for (auto suit : Card::allSuits)
            for (auto rank : Card::allRanks)
                m_cards[count++] = Card{ rank, suit };
    }

    void shuffle() //Shuffle the deck by randomizing the elements of array m_cards
    {
        std::shuffle(m_cards.begin(), m_cards.end(), Random::mt);
        m_nextCardIndex = 0;
    }

    Card dealCard() //Function returns a "Card"-type object (dealing cards)
    {
        assert(m_nextCardIndex != 52); //Make sure that the entire deck has not been dealt already
        return m_cards[m_nextCardIndex++];
    }
};
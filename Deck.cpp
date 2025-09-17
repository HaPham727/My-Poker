#include "Header.h"


Deck::Deck() //Contructore function to create the m_cards array
    {
        std::size_t count{ 0 };
        for (auto suit : Card::allSuits)
            for (auto rank : Card::allRanks)
                m_cards[count++] = Card{ rank, suit };
    }

void Deck::shuffle() //Shuffle the deck by randomizing the elements of array m_cards
{
    std::shuffle(m_cards.begin(), m_cards.end(), Random::mt);
    m_nextCardIndex = 0;
}

Card Deck::dealCard() //Function returns a "Card"-type object (dealing cards)
{
    assert(m_nextCardIndex != 52); //Make sure that the entire deck has not been dealt already
    return m_cards[m_nextCardIndex++]; 
}

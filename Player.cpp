#pragma once

//C++ libraries
#include <iostream>
#include <algorithm> 
#include <cassert>
#include <array>
#include <vector>
#include <stack>

//Random
#include "Random.h"

//Raylib
#include <raylib.h>

struct Card
{
    enum Rank
    {
        rank_ace,
        rank_2,
        rank_3,
        rank_4,
        rank_5,
        rank_6,
        rank_7,
        rank_8,
        rank_9,
        rank_10,
        rank_jack,
        rank_queen,
        rank_king,

        max_ranks
    };

    enum Suit
    {
        suit_club,
        suit_diamond,
        suit_heart,
        suit_spade,

        max_suits
    };


    //These two arrays are used in the "Deck()" constructor function, which iterates through both to create all 52 cards
    static constexpr std::array allRanks{ rank_ace, rank_2, rank_3, rank_4, rank_5, rank_6, rank_7, rank_8, rank_9, rank_10, rank_jack, rank_queen, rank_king };
    static constexpr std::array allSuits{ suit_club, suit_diamond, suit_heart, suit_spade };

    //All "Card"-type objects have these 2 variables 
    Rank rank{};
    Suit suit{};

    //Overload the operate<< so std::cout would print the full rank & suit of a card when passed a "Card"-type object
    friend std::ostream& operator<<(std::ostream& out, const Card& card)
    {
        static constexpr std::array ranks{ 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K' };
        static constexpr std::array suits{ 'C', 'D', 'H', 'S' };

        out << ranks[card.rank] << suits[card.suit];
        return out;
    }
};

class Deck
{
private: //The "Deck"-type object has 2 variables stuck to it: a "Card"-type array of all cards it (can) hold, and an index for the next card to be taken out
	std::array<Card, 52> m_cards{};
	std::size_t m_nextCardIndex{ 0 };

public:
	Deck();

	void shuffle();

	Card dealCard();

};

class Player
{
private: //Each player has an array of cards in their hand and their money count
    std::vector<Card> m_hand(2ULL);
	int m_money;

public:
	Player();

	void getCard(Card card1, Card card2);

	void printHand();
};

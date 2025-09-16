#include "Header.h"

class Player
{
private: //Each player has an array of cards in their hand and their money count
	std::vector<Card> m_hand;
	int m_money;

public:
	Player()
	{
		m_money = 5000; //Change default money amount here
	}

	void getCard(Card card) //Probably dont even need to use stack behavior since all 2 of a player's cards are dealt at once
	{
		m_hand.push_back(card);
	}

	void printHand()
	{
		std::cout << "You have " << m_hand[0] << " and " << m_hand[1] << " in your hand!";
	}


};
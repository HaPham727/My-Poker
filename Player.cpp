#include "Header.h"


Player::Player()
	{
		m_money = 5000; //Change default money amount here
		m_hand.resize(2);
	}

void Player::getCard(Card card1, Card card2) //Function to
	{
		this->m_hand[0] = card1;
		this->m_hand[1] = card2;
	}

void Player::printHand()
	{
		std::cout << "You have " << m_hand[0] << " and " << m_hand[1] << " in your hand!";
	}


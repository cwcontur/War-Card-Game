#include "Hand.h"
#include <ctime>
#include <cstdlib>

Hand::Hand()
{

}

Hand::~Hand()
{

}

Hand Hand::fullDeck()
{
	//Create a Hand with a full deck of cards
	Hand deck;

	const int Suits = 4;
	const int Values = 13;

	Suit suit[Suits] = { Clubs, Diamonds, Hearts, Spades };
	Value face[Values] = { Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace };

	for (int i = 0; i < Suits; i++)
	{
		for (int j = 0; j < Values; j++)
		{

			deck.placeBottom(Card(face[j], suit[i]));

		}
	}

	return deck;

}

void Hand::shuffle()
{
	srand(time(0) + size());
	//Select a new random location for each card
	for (int i = 0; i < size(); i++)
	{
		int newIndex = rand() % size();
		cards.insert(cards.begin() + newIndex, cards.at(i));
		cards.erase(cards.begin() + i);
	}
}


Card* Hand::drawT()
{
	Card* drawnCard = cards.at(0);

	cards.erase(cards.begin());
	return drawnCard;
}

Card* Hand::drawB()
{
	//Remove and return the last card
	Card* card = cards.back();
	cards.erase(cards.end());
	return card;
}

void Hand::placeTop(Card c)
{
	//Insert the card at the beginning of the deck
	cards.insert(cards.begin(), c);
}

void Hand::placeBottom(Card c)
{
	cards.push_back(c);
}

bool Hand::empty()
{
	return cards.empty();
}

int Hand::size()
{
	return cards.size();
}
#include "card.h"
#include <iostream>
#include <string>

Card::~Card()
{

}

string Card::valuePrint(Value value) {

	switch (value) {

	case Two: return "Two of ";
		break;

	case Three: return "Three of ";
		break;

	case Four: return "Four of ";
		break;

	case Five: return "Five of ";
		break;

	case Six:  return "Six of ";
		break;

	case Seven: return "Seven of ";
		break;

	case Eight: return "Eight of ";
		break;

	case Nine: return "Nine of ";
		break;

	case Ten: return "Ten of ";
		break;

	case Jack: return "Jack of ";
		break;

	case Queen: return "Queen of ";
		break;

	case King: return "King of ";
		break;

	case Ace: return "Ace of ";
		break;

	default: throw std::exception("Face value not possible");
	}
}

string Card::suitPrint(Suit suit) {

	switch (suit) {

	case Clubs: return "Clubs";
		break;

	case Diamonds: return "Diamonds";
		break;

	case Hearts: return "Hearts";
		break;

	case Spades: return "Spades";
		break;

	default: throw std::exception("Suit value not possible");
	}
}

bool Card::sameSuit(Card compare)
{
	if (this->suit == compare.suit) {
		return true;
	}

	return false;
}

int Card::compareValue(Card compare)
{
	if (this->faceValue < compare.faceValue) {
		return -1;
	}

	if (this->faceValue > compare.faceValue) {
		return 1;
	}

	return 0;
}

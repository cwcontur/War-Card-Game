#ifndef ___CARD_H
#define ___CARD_H

#include <string>
using std::string;

enum Suit { Clubs, Diamonds, Hearts, Spades };

enum Value { Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace };

class Card {
public:

	Card(Value faceValue = Ace, Suit suit = Spades) : suit(suit), faceValue(faceValue)
	{

	}

	~Card();

	static string suitPrint(Suit suit);

	static string valuePrint(Value value);

	string name() 
	{ 
		return valuePrint(faceValue) + suitPrint(suit); 
	}

	bool sameSuit(Card compare);

	int compareValue(Card compare);

private:

	Suit suit;

	Value faceValue;

};


#endif
#ifndef __HAND_H_
#define __HAND_H_

#include "Card.h"
#include <vector>
#include <stack>
class Hand
{
public:

	Hand();
	~Hand();

	static Hand fullDeck();

	void shuffle();


	Card* drawT();
	Card* drawB();

	void placeTop(Card c);
	void placeBottom(Card c);

	bool empty();
	int size();

protected:

	

private:

	std::stack<Card*> drawTop;
	std::stack<Card*> drawBottom;
	std::vector<Card*> cards;
	//std::vector<Card*> cards;

};

#endif
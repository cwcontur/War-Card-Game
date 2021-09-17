#include "War.h"
#include "Card.h"
#include "Hand.h"

string War::HumanPlayer = "Human";
string War::Computer = "Computer";

Hand Player;
Hand Comp;

bool War::skipToEnd = false; //Gives you the option to skip the entire game

War::War() 
{

}

void War::play()
{

	welcome();
	skipToEnd = false;

	//Creates deck and shuffles cards
	Hand deck = Hand::fullDeck();
	deck.shuffle();

	Player = Hand::Hand();
	Comp = Hand::Hand();

	//Deals cards to each player until the deck is fully distributed
	while (!deck.empty())
	{

		Player.placeBottom(deck.drawTop());
		Comp.placeBottom(deck.drawTop());

	}



	
	//Commences a battle while neither hand is empty
	while (!Player.empty() && !Comp.empty())
	{

		battle();

		if (!skipToEnd)
		{
			checkForSkip();
		}

	}

	//This will print the winner once one of the hands has no remaining cards
	winner();
	
}

//Welcoming/Instructions
void War::welcome()
{

	std::cout << "<<Welcome to the card game War!>>" << endl;
	std::cout << "<<Please press Enter to take your turn, or input any letter to skip all the way to the end>>" << endl << endl;

}

void War::battle()
{

	//Draws a card from each player
	Card PlayerCard = Player.drawTop();
	Card ComputerCard = Comp.drawTop();

	printCards(PlayerCard.name(), ComputerCard.name());

	//Compares values of the cards drawn
	if (PlayerCard.compareValue(ComputerCard) == 0)
	{
	
		//Sets the winner equal to whomever wins the way since the cards drawn were equal
		int winner = war();

		//Gives the cards to the winning player
		if (winner == 1)
		{

			Player.placeBottom(PlayerCard);
			Player.placeBottom(ComputerCard);

			std::cout << HumanPlayer;

		}
		else if (winner == 2)
		{

			Comp.placeBottom(PlayerCard);
			Comp.placeBottom(ComputerCard);

			std::cout << Computer;

		}

		std::cout << " won the battle!" << endl;

	}
	else if (PlayerCard.compareValue(ComputerCard) == 1)
	{

		//Gives cards to the human when it wins
		Player.placeBottom(PlayerCard);
		Player.placeBottom(ComputerCard);
		std::cout << HumanPlayer << " won this round." << endl;

	}
	else if (PlayerCard.compareValue(ComputerCard) == -1)
	{
		//Gives cards to the computer when it wins
		Comp.placeBottom(PlayerCard);
		Comp.placeBottom(ComputerCard);
		std::cout << Computer << " won this round." << endl;

	}
}

int War::war()
{
	Hand Pile;//Creates a pile of cards to put the extra cards in from the round of war
	Card PlayerCard, ComputerCard;
	int winner = 0;

	//Conducts a war when two equalivalent cards are played
	do
	{
		std::cout << "A War will Commence!" << endl;

		if (!skipToEnd) checkForSkip();

		//If a player is out of cards then the game ends and the other player wins
		if (Player.empty())
		{

			std::cout << HumanPlayer << " is out of cards." << endl;
			winner = 2;

			break;

		}
		else if (Comp.empty())
		{

			std::cout << Computer << " is out of cards." << endl;
			winner = 1;

			break;

		}

		//Puts down three cards for each player
		for (int i = 1; i <= 3; i++)
		{
			//Saves a card for the comparison
			if (Player.size() > 1)
			{

				Pile.placeBottom(Player.drawTop());

			}

			if (Comp.size() > 1) 
			{

				Pile.placeBottom(Comp.drawTop());

			}
		}

		//The next two cards will now be compared
		PlayerCard = Player.drawTop();
		ComputerCard = Comp.drawTop();

		//Drawn cards are added to the war pile so that the winner can receive them.
		Pile.placeBottom(PlayerCard);
		Pile.placeBottom(ComputerCard);

		printCards(PlayerCard.name(), ComputerCard.name());

	} while (PlayerCard.compareValue(ComputerCard) == 0);

	//Gives the cards to the winning player
	if (PlayerCard.compareValue(ComputerCard) == 1 || winner == 1)
	{

		int pile_size = Pile.size();

		for (int i = 1; i <= pile_size; i++)
		{
			Player.placeBottom(Pile.drawTop());
		}

		winner = 1;
	}
	else if (PlayerCard.compareValue(ComputerCard) == -1 || winner == 2)
	{

		int pile_size = Pile.size();

		for (int i = 1; i <= pile_size; i++)
		{
			Comp.placeBottom(Pile.drawTop());
		}

		winner = 2;
	}

	return winner;//Gives the winner of the round of war

}

//Prints out who the winner is based on whether or not a hand has no cards
void War::winner()
{

		std::cout << "The  ";
		if (Player.empty())
		{
			std::cout << Computer;
		}
		else 
		{
			std::cout << HumanPlayer;
		}
		std::cout << " has won this game of War!!!!!!!!!!!!!!!" << endl << endl;
	
}

//Checks to see if you want to skip to the end by checking for character input or a lack thereof
void War::checkForSkip()
{

	cin.sync();

	char ans;
	cin.get(ans);

	if (isalpha(ans))
	{
		skipToEnd = true;
	}
	else
	{
		skipToEnd = false;
	}

}

//Prints the current number of cards in each hand (including when cards are down for war so sometimes it looks like some cards have vanished)
void War::printCards(string PlayerCard, string ComputerCard)
{
	
	std::cout << HumanPlayer << "[" << Player.size() + 1 << "]: " << PlayerCard << endl;
	std::cout << Computer << "[" << Comp.size() + 1 << "]: " << ComputerCard << endl;

}
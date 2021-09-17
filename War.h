#pragma once
#ifndef __WAR_H_
#define __WAR_H_

#include "Hand.h"
#include <iostream>
#include <string>

using namespace std;

class War
{
public:

	static void play();

private:

	War();

	static void welcome();

	static void battle();

	static int war();

	static void winner();

	static void checkForSkip();

	static void printCards(string PlayerCard, string ComputerCard);

	static string HumanPlayer, Computer;

	static Hand Player, Comp;

	static bool skipToEnd;
	

};

#endif
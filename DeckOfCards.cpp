#include <iostream>
#include <iomanip>
#include <iomanip>
#include <ctime>

#include "DeckOfCards.h"
using namespace std;

DeckOfCards::DeckOfCards()
{
	for (int row = 0; row <= 3; row++)
	{
		for (int column = 0; column <= 12; column++)
		{
			deck[row][column] = 0;
		}
	}
}

void DeckOfCards::shuffle()
{
	int row;
	int column;

	for (int card = 1; card < 52; card++)
	{
		do
		{
			row = rand() % 4;
			column = rand() % 4;
		} while (deck[row][column] != 0);
		deck[row][column] = card;
	}
}

void DeckOfCards::deal()
{
	static const char *suit[4] = { "H", "D", "C", "S" };
	static const char *face[13] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "0", "J", "Q", "K" };

	for (int card = 1; card <= 52; card++)
	{
		for (int row = 0; row <= 3; row++)
		{
			for (int column = 0; column <= 3; column++)
			{
				if (deck[row][column] == card)
					cout << setw(5) << right << face[column] << " of" << setw(8) << left << suit[row] << (card % 2 == 0 ? '\n' : '\t');
			}
		}
	}
}

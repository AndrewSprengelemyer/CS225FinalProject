#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <stdio.h>
#include <ctime>
#include <cstring>
#include <string>

#include "DeckOfCards.h"
using namespace std;


//DeckOfCards is the default constructor, sets the game deck up
DeckOfCards::DeckOfCards()
{
	for (int row = 0; row <= 4; row++)
	{
		for (int column = 0; column <= 64; column++)
		{
			deck[row][column] = 0;
		}
	}
}

//resetDeck resets the deck in case the deck needs to be refreshed and reshuffled during game 
void DeckOfCards::resetDeck()
{
	for (int row = 0; row <= 4; row++)
	{
		for (int column = 0; column <= 64; column++)
		{
			deck[row][column] = 0;
		}
	}
}

//shuffle randomly assigns 260 cards into a 4 row 65 column array to portray 5 decks of cards with 4 suits and 13 faces.
void DeckOfCards::shuffle()
{
	int row = 0;
	int column = 0;

	for (int card = 1; card <= 260; card++)
	{
		do
		{
			do
			{
				column = 0 + rand() / (RAND_MAX / (64 - 0 + 1) + 1);

			} while (column > 64);
		} while (deck[row][column] != 0);
		deck[row][column] = card;
		if (card % 52 == 0 && row != 4)
		{
			row++;
		}
	}
}

// setDeck assigns the face and suit to each card in the deck array
void DeckOfCards::setDeck()
{
	cout << "\nStarting Set Deck Func\n";
	const char* suit[] = { "H", "D", "C", "S" };
	const char* face[] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };

	cout << "\n Arrays Made \n";

	string hold = " ";

	cout << "\nHold string made\n";
	
	for (int card = 1; card <= 260; card++) //260 card = 5 decks
	{
		for (int row = 0; row <= 4; row++)
		{
			for (int column = 0; column <= 64; column++)
			{
				if (column <= 12)
				{
					if (deck[row][column] == card) //deck 1 allocate
					{
						cout << "\ndeck 1 start\n";
						hold+=face[column]; //combines the selected face
						cout << "\n maybeee \n";
						hold+=suit[row];    //and suit and saves this to
						playDeck[card] = hold;     //the game deck array
						cout << "\ndeck 1 end\n";
					}
				}
				else if (column > 12 && column <= 25) //deck 2 allocate
				{
					if (deck[row][column] == card)
					{
						hold+=face[column - 13];
						hold+=suit[row];
						playDeck[card] = hold;
					}
				}
				else if (column > 25 && column <= 38) //deck 3 allocate
				{
					if (deck[row][column] == card)
					{
						hold.append(face[column - 26]);
						hold.append(suit[row]);
						playDeck[card] = hold;
					}
				}
				else if (column > 38 && column <= 51) //deck 4 allocate
				{
					if (deck[row][column] == card)
					{
						hold.append(face[column - 39]);
						hold.append(suit[row]);
						playDeck[card] = hold;
					}
				}
				else //deck 5 allocate
				{
					if (deck[row][column] == card)
					{
						hold.append(face[column - 52]);
						hold.append(suit[row]);
						playDeck[card] = hold;
					}
				}
			}
		}
	}
}

// returns and array of strings whose elements are individual cards. Each card taken will remove that one from the array.
string DeckOfCards::dealCard(int number)
{
	string help = "TESTING";
	return help;
}
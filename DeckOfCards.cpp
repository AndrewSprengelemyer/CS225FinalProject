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
				row = 0 + rand() / (RAND_MAX / (3 - 0 + 1) + 1);
				do
				{
					column = 0 + rand() / (RAND_MAX / (64 - 0 + 1) + 1);

				} while (column > 64);
			} while (row > 3);
		} while (deck[row][column] != 0);
		deck[row][column] = card;
	}
}

// setDeck assigns the face and suit to each card in the deck array
void DeckOfCards::setDeck()
{
	//default values for a normal deck of cards without jokers
	const char* suit[] = { "H", "D", "C", "S" };
	const char* face[] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };

	string hold = " ";

	int count = 0;

	for (int card = 1; card <= 260; card++) //260 card = 5 decks
	{
		hold = " ";
		//random face and suit
		int k = 0;
		int randomPickerR = 0;
		randomPickerR = 0 + rand() / (RAND_MAX / (3 - 0 + 1) + 1);
		int randomPickerC = 0;
		randomPickerC = 0 + rand() / (RAND_MAX / (12 - 0 + 1) + 1);


		for (int row = 0; row <= 3; row++)
		{
			for (int column = 0; column <= 64; column++)
			{
				if (column <= 12)
				{
					if (deck[row][column] == card) //deck 1 allocate
					{
						hold+=face[randomPickerC]; //combines the selected face
						hold += " ";		//(adds space to split card later)
						hold+=suit[randomPickerR];    //and suit and saves this to
						playDeck[count] = hold;     //the game deck array
					}
				}
				else if (column > 12 && column <= 25) //deck 2 allocate
				{
					if (deck[row][column] == card)
					{
						hold += face[randomPickerC]; //combines the selected face
						hold += " ";
						hold += suit[randomPickerR];    //and suit and saves this to
						playDeck[count] = hold;     //the game deck array
					}
				}
				else if (column > 25 && column <= 38) //deck 3 allocate
				{
					if (deck[row][column] == card)
					{
						hold += face[randomPickerC]; //combines the selected face
						hold += " ";
						hold += suit[randomPickerR];    //and suit and saves this to
						playDeck[count] = hold;     //the game deck array
					}
				}
				else if (column > 38 && column <= 51) //deck 4 allocate
				{
					if (deck[row][column] == card)
					{
						hold += face[randomPickerC]; //combines the selected face
						hold += " ";
						hold += suit[randomPickerR];    //and suit and saves this to
						playDeck[count] = hold;     //the game deck array
					}
				}
				else //deck 5 allocate
				{
					if (deck[row][column] == card)
					{
						hold += face[randomPickerC]; //combines the selected face
						hold += " ";
						hold += suit[randomPickerR];    //and suit and saves this to
						playDeck[count] = hold;     //the game deck array
					}
				}
			}
		}
		count++;
	}
}

// returns an array of strings whose elements are individual cards. Each card taken will remove that one from the array. Basically you get a hand with the amount of cards you wanted in it.
string * DeckOfCards::dealCard(int number)
{
	static string outputArray[260];
	int i = 0;
	int amount = 0;
	int numberSaved = 0;
	amount = number; 
	for (i = 0; i < 260; i++)
	{
		if (playDeck[i] == "E")
		{
			//no array element...move to next array element
		}
		else
		{
			//anything else, save that string to the output array, set drawn card slot to empty
			outputArray[numberSaved] = playDeck[i];
			numberSaved++;
			playDeck[i] = "E";
		}
		if (amount == (numberSaved))
		{
			//break loop if amount == our total cards drawn. (Amount is the amount of cards inputted to function that user wants to be draw)
			i = 1000;
			break;
		}
	}
	return outputArray;
}
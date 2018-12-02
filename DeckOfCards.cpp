#include "stdafx.h"

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
	for (int row = 0; row < 4; row++)
	{
		for (int column = 0; column < 13; column++)
		{
			deck[row][column] = 0;
		}
	}
	srand((unsigned int)time(0));
}

//resetDeck resets the deck in case the deck needs to be refreshed and reshuffled during game 
void DeckOfCards::resetDeck()
{
	for (int row = 0; row < 4; row++)
	{
		for (int column = 0; column < 65; column++)
		{
			deck[row][column] = 0;
		}
	}
}

//shuffle randomly assigns 260 cards into a 4 row 65 column array to portray 5 decks of cards with 4 suits and 13 faces.
void DeckOfCards::shuffle(int length)
{
	int temp = 'Z';

	for (int numSwaps = 0; numSwaps < 10000; numSwaps++)
	{
		int faceRandom1 = rand() % 20;
		int suitrandom1 = rand() % 13;
		int faceRandom2 = rand() % 20;
		int suitrandom2 = rand() % 13;

		temp = cards[faceRandom1][suitrandom1];
		cards[faceRandom1][suitrandom1] = cards[faceRandom2][suitrandom2];
		cards[faceRandom2][suitrandom2] = temp;

	}

	// Emily's Implementation
	/*
	int row = 0;
	int column = 0;
	for (int card = 1; card <= 52; card++)
	{
		do
		{
			do
			{
				row = 0 + rand() / (RAND_MAX / (4) + 1);
				do
				{
					column = 0 + rand() / (RAND_MAX / (65) + 1);

				} while (column > 13);
			} while (row > 3);
		} while (deck[row][column] != 0);

		deck[row][column] = card;
	}
	*/
}

// setDeck assigns the face and suit to each card in the deck array
void DeckOfCards::setDeck(int size)
{
	
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 13; j++)
			{				
				if ((j == 0) || (j == 13) || (j == 26) || (j == 39) || (j == 52))
					cards[i][j] = 'A';
				else if ((j == 1) || (j == 14) || (j == 27) || (j == 40) || (j == 53))
					cards[i][j] = '2';
				else if ((j == 2) || (j == 15) || (j == 28) || (j == 41) || (j == 54))
					cards[i][j] = '3';
				else if ((j == 3) || (j == 55) || (j == 29) || (j == 42) || (j == 55))
					cards[i][j] = '4';
				else if ((j == 4) || (j == 56) || (j == 30) || (j == 43) || (j == 56))
					cards[i][j] = '5';
				else if ((j == 5) || (j == 57) || (j == 31) || (j == 44) || (j == 57))
					cards[i][j] = '6';
				else if ((j == 6) || (j == 58) || (j == 32) || (j == 45) || (j == 58))
					cards[i][j] = '7';
				else if ((j == 7) || (j == 59) || (j == 33) || (j == 46) || (j == 59))
					cards[i][j] = '8';
				else if ((j == 8) || (j == 60) || (j == 34) || (j == 47) || (j == 60))
					cards[i][j] = '9';
				else if ((j == 9) || (j == 61) || (j == 35) || (j == 48) || (j == 61))
					cards[i][j] = '0';
				else if ((j == 10) || (j == 62) || (j == 36) || (j == 49) || (j == 62))
					cards[i][j] = 'J';
				else if ((j == 11) || (j == 63) || (j == 37) || (j == 50) || (j == 63))
					cards[i][j] = 'Q';
				else if ((j == 12) || (j == 64) || (j == 38) || (j == 51) || (j == 64))
					cards[i][j] = 'K';

			}
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

//void DeckOfCards::print(string * hand, int length)
//{
//	for (int i = 0; i < length; i++)
//	{
//		//int size = 52; //amount of cards that need to be drawn
//		//hand = this->dealCard(size); //drawn amount of cards
//
//		cout << "\nCurrent Hand: ";
//		for (int i = 0; i < length; i++)
//		{
//			cout << playDeck[i] << " "; //print a card in the hand array
//		}
//		cout << endl;
//	}
//
//}

void DeckOfCards::print(int size) {
	int rowLength = 13;
	int counter = 0;

	for (int i = 0; i < 20; ++i)
	{
		cout << endl;
		for (int j = 0; j < 13; j++)
		{
			cout << this->cards[i][j] << " ";
		}
		
	}
	
}
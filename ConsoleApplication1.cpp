#include "stdafx.h"

#include "DeckOfCards.h"
#include <sstream>
#include <algorithm>
#include <iterator>
#include <string>

using namespace std;

int main()
{
	/*
	IN ORDER TO USE THE DECK CLASS YOU MUST USE THE DECK IN THE FOLLOWING ORDER:

	DeckofCards test;
	test.shuffle();
	test.setDeck();
	hand = test.dealCard(x);
	IF YOU THINK YOU WILL RUN OUT OF CARDS (there are 260 cards in this deck) THEN USE THE NEXT FEW LINES TO RESET AND RESHUFFLE THE DECK
	------------------(repeat start)
	test.resetDeck();
	test.shuffle();
	test.setDeck();
	hand = test.dealCard(x);
	--------------------(repeat end)
	repeat however many times you need to use the whole deck and reshuffle the cards to reform the deck

	*/
	/*
	DeckOfCards test; //initialize deck
	test.shuffle(); //shuffle deck
	test.setDeck(); //set deck to have faces and suits

	//PRINT FUNCTION BASICALLY:
	int rowLength = 13;
	int counter = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			
			if ((counter % rowLength == 0) && (counter != 0))
				cout << endl;
			
				
			cout << test.deck[i][j] << " " ;
			counter++;
		}
		
	}

	
	*/
	//string *testCardHand;
	//int size = 52; //amount of cards that need to be drawn
	//testCardHand = test.dealCard(size); //drawn amount of cards
	//cout << "\nCurrent Hand: ";
	//for (int i = 0; i < size; i++)
	//{
	//	cout << testCardHand[i] << " "; //print a card in the hand array
	//}
	//cout << endl;
	//test.print(testCardHand, size);

	//
	//string *testCardHand; 

	//cout << "\nShowing Players Current Hand with a test hand size of 5...\n";
	////print current hand
	//
	//int size = 5; //amount of cards that need to be drawn
	//testCardHand = test.dealCard(size); //drawn amount of cards
	//cout << "\nCurrent Hand: ";
	//for (int i = 0; i < size; i++)
	//{
	//	cout << testCardHand[i] << " "; //print a card in the hand array
	//}
	//cout << endl;
	
	//cout << "\nTesting card split to be able to look at face and suit seperate for game rules\n";
	//string hand[2]; //hand has 2 parts in the array, the face and the suit, the array should use a size of 4 due to overflow in the split


	//				//the following function shows how to split the cards in the hand into individual parts (FROM HERE!!!!)
	//istringstream iss(testCardHand[0]);
	//int j = 0;
	//do
	//{
	//	string subs;
	//	iss >> subs;
	//	hand[j] = subs;
	//	j++;
	//} while (iss);

	//cout << "\n Single Card in Hand Split...\n";
	////print out the card in a players hand
	//cout << "\nCard:\nFace: " << hand[0] << "\nSuit: " << hand[1];
	//cout << endl;
	////(TO HERE!!!)

	////print multi cards in a single hand...
	//cout << "Multi Card in hand Split...\n";
	//cout << "\nCurrent Hand: ";
	//int handSize = 12;
	//testCardHand = test.dealCard(handSize);
	//for (i = 0; i < 15; i++)
	//{
	//	cout << testCardHand[i] << " ";
	//}
	//cout << endl;
	//int k = 0;
	//for (k = 0; k < handSize; k++)
	//{
	//	int hands[4];
	//	istringstream iss(testCardHand[k]);
	//	int j = 0;
	//	do
	//	{
	//		int subs;
	//		iss >> subs;
	//		hands[j] = subs;
	//		j++;
	//	} while (iss);

	//	////print out the card in a players hand or you can use string data of... the face data stored in hands[0] and suit data stored in hands[1] for game rule reasons 
	//	//cout << "\nCard: " << k + 1 << "\nFace: " << hands[0] << "\nSuit: " << hands[1];
	//	//cout << endl;
	//}

	//cout << "\nTesting Adding Cards to an already made Hand...\n";
	////WAY TO ADD TO ALREADY MADE HAND-----------------------
	////testCardHand has 2 cards and is supposed to draw 4 for a total of 6 cards

	//testCardHand = test.dealCard(2); //this would be the players starting hand they have for the game
	//DeckOfCards helper; //draw new cards from a seperate deck because of program issues
	//helper.shuffle();
	//helper.setDeck();
	//cout << "\nCurrent Hand: ";
	//for (i = 0; i < 2; i++) //print current hand
	//{
	//	cout << testCardHand[i] << " ";
	//}
	//string *endArray = new string[6];
	//for (int a = 0; a < 2; a++) //add current hand to a hold hand array
	//{
	//	endArray[a] = testCardHand[a];
	//}

	//string *holdArray; //aka new cards to be added to the already made player hand
	//holdArray = helper.dealCard(4);
	//cout << "\nNew Drawn Cards: ";
	//for (i = 0; i < 4; i++) //print drawn cards
	//{
	//	cout << holdArray[i] << " ";
	//}

	//for (int b = 2; b < 6; b++) //add drawn cards to hold hand array
	//{
	//	endArray[b] = holdArray[b - 2];
	//}
	//testCardHand = endArray;
	////THAT ENDS HERE--------------

	//cout << "\nUpdated Hand: ";
	//for (i = 0; i < 6; i++) //print new hand with new cards added
	//{
	//	cout << testCardHand[i] << " ";
	//}
	//cout << "\nHand Successfully Updated...\n";
	

	DeckOfCards testDeck;
	testDeck.setDeck(260);
	testDeck.print(260);

	testDeck.shuffle(260);
	cout << endl << "SHUFFLED: " << endl;
	testDeck.print(260);

	int hold;
	cin >> hold;

	cout << "\nEnding Program...\n";
	return 0;
}
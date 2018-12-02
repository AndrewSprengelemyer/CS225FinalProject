#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <stdio.h>
#include <ctime>
#include <cstring>
#include <vector>
using namespace std;

class DeckOfCards
{
public:
	DeckOfCards();
	void shuffle(int);
	string * dealCard(int);
	void resetDeck();
	void setDeck(int);
	string playDeck[260];
	static string outputArray[260];
	void print(int);
//private:	
	int deck[4][65]; // Emily's
	char cards[20][13]; //Zack's
	//vector <char> cards;
};
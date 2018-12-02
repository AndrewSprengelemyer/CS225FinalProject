#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <stdio.h>
#include <ctime>
#include <cstring>
using namespace std;

class DeckOfCards
{
public:
	DeckOfCards();
	void shuffle();
	string * dealCard(int);
	void resetDeck();
	void setDeck();
	string playDeck[260];
	static string outputArray[260];
private:
	int deck[4][65];
};
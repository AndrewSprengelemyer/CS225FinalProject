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
	string dealCard(int);
	void resetDeck();
	void setDeck();
private:
	int deck[4][65];
	string playDeck[260];
};
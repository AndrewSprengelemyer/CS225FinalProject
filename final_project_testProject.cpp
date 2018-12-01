#include <iostream>
#include "DeckOfCards.h"

using namespace std;

int main()
{
	DeckOfCards test;
	cout << "\nDeck Made\n";
	cout << "\nShuffling...\n";
	test.shuffle();
	cout << "\nShuffling Done...\n";
	cout << "\nDealing... \n";
	test.setDeck();
	cout << "\nDealing Done\n";
	return 0;
}

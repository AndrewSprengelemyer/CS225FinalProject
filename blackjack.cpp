#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;


cout << "                                                                                   ";
cout << "	$$$$$$$\  $$\                     $$\                               $$\         ";
cout << "	$$  __$$\ $$ |                    $$ |                              $$ |        ";
cout << "	$$ |  $$ |$$ | $$$$$$\   $$$$$$$\ $$ |  $$\ $$\  $$$$$$\   $$$$$$$\ $$ |  $$\   ";
cout << "	$$$$$$$\ |$$ | \____$$\ $$  _____|$$ | $$  |\__| \____$$\ $$  _____|$$ | $$  |  ";
cout << "	$$  __$$\ $$ | $$$$$$$ |$$ /      $$$$$$  / $$\  $$$$$$$ |$$ /      $$$$$$  /   ";
cout << "	$$ |  $$ |$$ |$$  __$$ |$$ |      $$  _$$<  $$ |$$  __$$ |$$ |      $$  _$$<    ";
cout << "	$$$$$$$  |$$ |\$$$$$$$ |\$$$$$$$\ $$ | \$$\ $$ |\$$$$$$$ |\$$$$$$$\ $$ | \$$\   ";
cout << "	\_______/ \__| \_______| \_______|\__|  \__|$$ | \_______| \_______|\__|  \__|  ";
cout << "										  $$\   $$ |                                ";
cout << "                                         \$$$$$$  |								";
cout << "                                          \______/									";
cout << "                                                                                   " << endl;

int handSum(Hand hand) //Function that calculates the total sum of all the cards in a hand
{
	int sum = 0;

	for (int i = 0; i < hand.length; i++)
	{
		sum += hand[i] 
		//NEED CODE HERE TO DETERMINE HOW TO ADD FACE CARDS AND SOFT/HARD ACES
	}
}

int checkHand(Hand hand, int user) //switch based on the sum of the cards in the hand.
{
	int sum = handSum(hand);
	
	switch(sum)
		case 21: 
			if (hand.length == 2) //they rolled a 21 on the first hand - Blackjack; player can win
				return 1;
			else
				return 6;

		case > 22:
			return 3; // BUST


		case sum < 17:
			if ((hand.length == 2) && ((sum == 10) || (sum == 11))) // if they got a 10 or 11 on their initial hand, player can double down
				return 2;
			else
				return 4; // dealer still needs to draw because their sum is < 17

		case 17, 18, 19, 20: 
			return 5;		//dealer stands

}


// Instantiate  mainDeck (made up of 5 standard decks, shuffled)
// Shuffle  mainDeck

// Instantiate gameState -- ONGOING, WIN, LOSE, PUSH --> inital value is ONGOING

player.setBankroll = 1000; //set the player's initial bankroll/budget to $1000

player.print(); //print the player's current bankroll, show that they're betting $100, and then show the new bankroll after betting


do //begin the loop that runs until player quits or goes broke
{
	while (gamestate == ONGOING)
	{
		//if (mainDeck.UsableLength < 30 cards)
		//	reshuffle maindeck


		deal(dealer.hand); //just call draw twice, essentially
		deal(player.hand);

		dealer.print();
		player.print();

		player.state = playing;	//similar to gameState, values are playing, stay, & bust?? needs refining
		dealer.state = playing;


		int pcheck = checkHand(player.hand); //returns values corresponding to the sum of the hand
		int dcheck = checkHand(dealer.hand);


		//checking initial hands for win/push conditions (aka blackjack) right off the bat

		if ((pcheck == 1) && (dcheck == 1))				//both got blackjack; push condition
		{
			player.setBankRoll(playet.getBankroll + $100);
			gameState = PUSH;
		}
		else if ((pcheck == 1) && (dcheck != 1))		//Player got blackjack; player wins
		{
			player.setBankRoll(playet.getBankroll + $250);
			gameState = WIN;
		}
		else if (pcheck == 2)		//Player got double down code
		{
			cout << "You have the option to double down (D)." << endl;
			cout << "You can draw one additional card for a chance to win 3x your original bet." << endl;
		}
		//end if
			
		while !((player.state == stay) || (player.state == bust))
		{
			char choice;

			cout << "(S)tand, (H)it: ";
			cin >> choice;
			cout << endl << endl;

			switch(choice):
				case 'S':
					player.state = STAY;

				case 'H':
					draw(player.hand);
					cout << "You draw a " << player.hand[lastValue] << ". " << endl;
					
					if (checkhand(player.hand) == 3)
					{
						player.state == BUST;
						cout << "You Bust." << endl << endl;
						gameState = LOSE;
					}

				case '?' :
					mainDeck.Print(); // print the entire array of the main Deck[260]

				case 'D':
					if (pcheck == 2);
					{
						player.setBankRoll(playet.getBankroll - $50);
						
						draw(player.hand);
						cout << "You draw a " << player.hand[lastValue] << ". " << endl;

						if (checkhand(player.hand) == 3)
						{
							player.state == BUST;
							cout << "You Bust." << endl << endl;
							gameState = LOSE;
						}
						else
							player.state = STAY;
					}

					case 'Q'
						break; //exit out of the entire loop and quit back to the main screen somehow - break? quit? Exit?
						// need to break out of the while loop and make sure that choice == 'Q' to exit the main game loop
					
					default:
						cout << "Please use a valid uppercase letter: " << endl;

		}

		if (player.state == STAY)
		{
			if (dcheck == 1)		//dcheck still holds the value based on the dealer's initial hand
				dealer.state = STAY;
			//end if

			while !((dealer.state == STAY) || (dealer.state == BUST))
			{
				dcheck == checkHand(dealer.hand);

				switch (dcheck)

					case 3:		//dealer busts
						dealer.state = BUST;
						cout << "Dealer Busts." << endl;
						cout << "You Win $200." << endl;
						player.setBankRoll(playet.getBankroll + $200);
						gameState = WIN;

					case 4: //dealer's hand is less than 17; dealer draws
						draw(dealer.hand);
						cout << "Dealer draws a " << dealer.hand[last] << ". " << endl;

					case 5, 6: //dealer's hand is 17 <= handSum <= 21
						dealer.state = STAY;

					default:
						cout << "ERROR" << endl;


			}

			if ((player.state == STAY) && (dealer.state == STAY)) //neither the player or the dealer busted so we compare the sum - closest to 21 wins
			{
				int psum = handSum(player.hand); // holds sum of player's deck
				int dsum = handSum(dealer.hand); // holds sum of dealer's deck


				// NOTE: Following code can also be modified to show what you got vs what the dealer got

				if (psum == dsum) // PUSH CONDITION
				{
					cout << "Game is a Push (Tie)" << endl;
					gameState = PUSH;
					player.setBankRoll(playet.getBankroll + $100);
				}
				else if (psum > dsum) // WIN CONDITION
				{
					cout << "You win! +$200 " << endl;
					gameState = WIN;
					player.setBankRoll(playet.getBankroll + $200);
				}
				else if (psum < dsum) // LOSE CONDITION
				{
					cout << "You lost. -$100" << endl;
					gameState = LOSE;
					player.setBankRoll(playet.getBankroll + $100);
				}



			}


		}





	}





} while!((choice == 'Q') || (player.getBankroll() < = 0)) // exits loop if player quits or goes broke

	cout << endl << "Thanks for Playing Blackjack! " << endl;

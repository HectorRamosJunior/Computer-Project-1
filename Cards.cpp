#include <iostream>
#include <stdlib.h>                      // for rand function
#include <time.h>
#include <math.h>                        // function for ceiling and floor that was recommended
#include <string>                        // include string 

using namespace std; 

struct CARD {                           // initialize Deck
	int value;
	char suit;
};

void CreateDeck(CARD DECK[52]){

}
int main(){

	CARD DECK[52];                     //  Create array which will store the deck.

	
										/* In this code we are going to represent
									      face cards as numbers. For example, Jack = 11,
										  Queen = 12, and King = 13. Also, an Ace = 1.						   
									      */
	// Now we must initialize the deck so that it holds values. 

	for (int i = 1; i <= 52; i++)
	{ 
		if (i <= 13)
		{
			DECK[i].value = i;
			DECK[i].suit = 'S';
		}
		else if (i <= 26)
		{
			DECK[i].value = i % 13;
			DECK[i].suit = 'D';
		}
		else if (i <= 39)
		{
			DECK[i].value = i % 13;
			DECK[i].suit = 'H';
		}
		else if (i <= 52)
		{
			DECK[i].value = i % 13;
			DECK[i].suit = 'C';
		}
		else
		{
			cout << "ERROR.";
		}
		if (DECK[i].value == 0){ DECK[i].value = 13; }
		cout << DECK[i].value << DECK[i].suit << endl;
	}

	
	cin.get();
	return 0; 

}
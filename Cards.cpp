#include <iostream>
#include <stdlib.h>                      // for rand function
#include <time.h>
#include <math.h>                        // function for ceiling and floor that was recommended
#include <string>                        // include string 
using namespace std; 


struct CARD {                           // initialize Deck
	int value;
	char suit;
} DECK[52],TEMP[52];                             //  Create array which will store the deck.


void CreateDeck(){

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
	}
}


void ShuffleDeck(){                                // generate two random numbers which will represent the indices of DECK which will be swapped with each other
	srand(time(0));
	for (int j = 1; j <= 52; j++){
		int i = rand() % 52 + 1;
		int k = rand() % 52 + 1; 

		TEMP[i].value = DECK[i].value;            // place cards in temporary deck
		TEMP[i].suit = DECK[i].suit;
		TEMP[k].value = DECK[k].value;
		TEMP[k].suit = DECK[k].suit;
		
		DECK[i].value = TEMP[k].value;          // cards swapped 
		DECK[i].suit = TEMP[k].suit;
		DECK[k].value = TEMP[i].value;
		DECK[k].suit = TEMP[i].suit;
	}
}
void PrintDeck(){

	for (int j = 1; j <= 52; j++){
		cout << DECK[j].value << DECK[j].suit << endl; 
	}
}

int main(){
	CreateDeck();
	ShuffleDeck();
	PrintDeck(); 

	cin.get();
	return 0; 

}


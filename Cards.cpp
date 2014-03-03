#include <iostream>
#include <stdlib.h>                      // for rand function
#include <time.h>
#include <math.h>                        // function for ceiling and floor that was recommended
#include <string>                        // include string 

using namespace std; 


struct CARD {                           // initialize Deck
	int value;
	char suit;
	CARD() : value(), suit() {}               // constructor
	CARD(int v, int s) : value(v), suit(s){}
}DECK[52];                             //  Create array which will store the deck.

struct HAND {                         // players hands
	int value; 
	char suit; 
 }HandA[5], HandB[5];

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

void ShuffleDeck()
{                                // generate two random numbers which will represent the indices of DECK which will be swapped with each other
	int tempValue;
	char tempSuit; 
	srand(time(0));
	for (int j = 1; j <= 52; j++)
	{
		int i = rand() % 52 + 1;
		int k = rand() % 52 + 1;

		tempValue = DECK[i].value;            // place cards in temporary deck
		tempSuit= DECK[i].suit;
		DECK[i].value = DECK[k].value;
		DECK[i].suit = DECK[k].suit;
		DECK[k].value = tempValue; 
		DECK[k].suit = tempSuit; 
	}
}

void PrintDeck()
{
		for (int j = 1; j <= 52; j++)
		{
			cout << DECK[j].value << DECK[j].suit << endl;
		}
}

void DealHands()
{
	int j = 1 , k = 1;
	for (int i = 1; i <= 10; i++){                         // this represents the dealer dealing to the hand every other card
		if ((i % 2) == 0){
			HandA[j].value = DECK[i].value;
			HandA[j].suit = DECK[i].suit;
			j++; 
		}
		else 
		{
			HandB[k].value = DECK[i].value;
			HandB[k].suit = DECK[i].suit;
			k++; 
		}

		DECK[i].suit = NULL; 
		DECK[i].value = NULL;
	}
}

void PrintHands()
{
	cout << endl;
	for (int t = 1; t <= 5; t++){
		cout << HandA[t].value << HandA[t].suit << endl;
	}
	cout << endl;
	for (int t = 1; t <= 5; t++){
		cout << HandB[t].value << HandB[t].suit << endl;
	}

}

int main(){

	CreateDeck();
	ShuffleDeck();
	//PrintDeck(); 
	DealHands(); 
	PrintHands(); 

	cin.get();
	return 0; 

}


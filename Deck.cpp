#include <iostream>
#include <stdlib.h>         // for rand function
#include <time.h>			// for rand
#include <algorithm>		// for swap function
#include <math.h>           // function for ceiling and floor that was recommended
#include <string>           // include string 
#include "deck.h"			//includes the header file

using namespace std; 

Deck::Deck() : value(52) , suit(52) { //Deck Constructor, Initializes Vector Lengths
	createDeck();
}

void Deck::createDeck() {

	for (int i = 0; i <= 51; i++)
	{
		if (i <= 12)
		{
			value.at(i) = i+1;
			suit.at(i) = 'S';
		}
		else if (i <= 25)
		{
			value.at(i) = (i + 1) % 13;
			suit.at(i) = 'D';
		}
		else if (i <= 38)
		{
			value.at(i) = (i + 1) % 13;
			suit.at(i) = 'H';
		}
		else if (i <= 51)
		{
			value.at(i) = (i + 1) % 13;
			suit.at(i) = 'C';
		}
		else
		{
			cout << "ERROR.";
		}
		if (value.at(i) == 0){ value.at(i) = 13; }
	}
}

void Deck::shuffle() {
	int deckSize = value.size();
	srand(time(0));

	for (int i = 1; i <= 10000; i++)
	{
		int j = rand() % deckSize ;
		int k = rand() % deckSize ;

		if( j != k)
		{
			std::swap(value[j], value[k]);
			std::swap(suit[j], suit[k]);
		}

	}

}

void Deck::print() {
	for (int i = 0; i < value.size(); i++)
	{
		cout << value.at(i) << suit.at(i) << endl;
	} 
	cout << endl << endl << endl;
}


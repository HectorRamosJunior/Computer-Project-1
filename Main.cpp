#include <iostream>
#include <stdlib.h>                      // for rand function
#include <time.h>
#include <math.h>                        // function for ceiling and floor that was recommended
#include <string>                        // include string 
#include "deck.h"
#include "hand.h"

using namespace std; 



int main(){

	Deck game1;                                // create Deck object
	//game1.print();
	game1.shuffle();
	Hand hand1,hand2;                          // create 2 hands
	//game1.print();
	cout << endl; 
	hand1.addCards(game1, 0);
	hand2.addCards(game1, 1);
	game1.value.erase(game1.value.begin(), game1.value.begin() + 10);   // delete first ten cards from deck after dealt
	game1.suit.erase(game1.suit.begin(), game1.suit.begin() + 10);
	hand1.sortHand();
	hand2.sortHand();
	hand1.printHand();
	hand2.printHand();
	cout << endl;
	hand1.determineHand();
	cout << endl; 
	hand2.determineHand();
	
	cin.get();
	return 0; 
}


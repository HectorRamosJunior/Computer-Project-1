// Hand.h
#include <vector>
#include "Deck.h"

#ifndef HAND_H
#define HAND_H



class Hand {
 
public:
	Hand();
	void print();				//Prints Hand
	void print(int);			//Prints specific hand element
	void printHand();

	void createHand();			//Creates Hands, called within Constructor
	void addCards(Deck deck, int startIndex);
	void sortHand(); 
	void determineHand(); 
	std::vector<int> value;		// Value vector, Vector chosen for easy dynamic manipulation
	std::vector<char> suit;		// Suit vector, Vector chosen for easy dynamic manipulation
	int score; 
	 
};

#endif

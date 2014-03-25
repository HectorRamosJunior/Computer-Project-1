// Deck.h
#include <vector>

#ifndef DECK_H
#define DECK_H

class Deck {
 
public:
	Deck();						// Default Constructor
	void shuffle();				// Shuffle Function, calls rand()
	void sort();				// Sorts Deck
	void print();				// Prints whole deck
	void print(int);			// Prints specific element within deck
	void createDeck();			// Creates Deck, called within Constructor

	std::vector<int> value;		// Value vector, Vector chosen for easy dynamic manipulation
	std::vector<char> suit;		// Suit vector, Vector chosen for easy dynamic manipulation
};

#endif
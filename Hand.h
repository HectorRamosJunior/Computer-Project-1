// Hand.h
#include <vector>
#include "Deck.h"

#ifndef HAND_H
#define HAND_H



class Hand {
 
public:
	Hand(int i);
	void printHand();

	void addCards(Deck deck, int startIndex);
	int drawCards(Deck deck);
	void sortHand(); 
	void determineHand(); 

	std::vector<int> value;		// Value vector, Vector chosen for easy dynamic manipulation
	std::vector<char> suit;		// Suit vector, Vector chosen for easy dynamic manipulation
	std::vector<int> bucketVector;

	int score, playerNumber; 
	int suitS, suitD, suitC, suitH;
	 
};

#endif

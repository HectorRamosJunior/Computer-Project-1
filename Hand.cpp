#include <iostream>
#include <stdlib.h>                      // for rand function
#include <time.h>
#include <math.h>                        // function for ceiling and floor that was recommended
#include <string>                        // include string 
#include "hand.h"						 // includes the header file

using namespace std;

Hand::Hand() : value(10), suit(10) {    //Hand Constructor, Initializes Vector Lengths, Set score to one to signify high card
	createHand();
	score = 1; 
}


void Hand::createHand(){
			
}

void Hand::addCards(Deck deck, int startIndex) {         // This function adds cards to the Hand object. 

	int j = startIndex;

	for (int i = 0; i < 10; i++){

		value.at(i) = deck.value.at(j);
		suit.at(i) = deck.suit.at(j);
		j = j + 2;                                       // A startIndex variable is used to simulate a dealer dealing cards in an alternating
	}                                                    // fashion to the players. This is why it is j+2 as the loop iterates, because a 
	                                                     // startIndex of 0 and 1 is passed to player 1 and 2 respectively. 
}

void Hand::sortHand()
{                                          // This function uses insertion sort, to sort the hand. This makes it easier to store
										   // the cards in the buckets. 
	int i, j;
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (value.at(i) < value.at(j))  // Explanation:  
			{
				int temp = value.at(i);     //swap 
				int tempC = suit.at(i);
				value.at(i) = value.at(j);
				suit.at(i) = suit.at(j);
				value.at(j) = temp;
				suit.at(j) = tempC;
			}
		}
	}
}

void Hand::printHand()                                          // This function prints the users hand. 
{
	for (int i = 0; i < 10; i++)
	{
		std:: cout << value.at(i) << suit.at(i) << endl;
	}
	std:: cout << endl << endl << endl;
}

void Hand::determineHand()
{
	/*
	The idea of a bucket vector is the program will search each players hand.
	The program will count the number of instances the value of a card appears
	for each player, and store the number of instances in a vector. 
	This will help the program determine the hands much easier.
	Refer to references where this idea came from.
	*/
	vector<int> bucketVector;                                     // initialize bucket vector of length 13 with 0's
	bucketVector.assign(13, 0);

	for (int j = 0; j < bucketVector.size(); j++)
	{
		int counter = 0;
		for (int i = 0; i < 10; i++){                             // search the players hand and store the instances
																  // that each card occurs in the corresponding bucket.
			if (value.at(i) == j+1)                               // we set the value equal to j+1 because our vector places
			{													  // index from 0 to 12, however our values from ace to king
				counter++;                                        // range from 1 to 13. 
			}
		}
		bucketVector[j] = counter;                                // store the number of instances a card occurs in the corresponding bucket

	}
	// We assign a score to each hand to make it easier in determining a winner when comparing the hands.

	/*Scoring System assigned to hands:
		Royal Flush:    10
		Straight Flush: 9
		4 of a Kind:    8
		Full House:     7
		Flush:          6
		Straight:       5
		3 of a Kind:    4
		2 Pair:         3
		1 Pair:         2
		High Card:      1

		*/

	int suitS = 0;                                               // this code is used to determine flushes. We are counting the instances
	int suitC = 0;                                               // at which each suit occurs in a hand. 
	int suitH = 0;
	int suitD = 0;
	for (int i = 0; i < 10; i++)                     
	{
		if (suit.at(i) == 'S'){ suitS++; }
		if (suit.at(i) == 'C'){ suitC++; }
		if (suit.at(i) == 'H'){ suitH++; }
		if (suit.at(i) == 'D'){ suitD++; }

	}

	int straightCounter = 0;                                            // This variable is used to determine straights.
	
	if ((suitS == 5) || (suitD == 5) || (suitC == 5) || (suitH == 5))   // If the suit counter is equal to five, then the player
	{                                                                   // has a flush. 
		if (6 > score) { score = 6; }                                   // If the player's score is greater than the constructor with a 
	}                                                                   // guaranteed score of 1 for a high card, then set the player's score
	                                                                    // to 6 signifying a flush. 


	for (int i = 0; i < 13; i++)                                        // This code is used to determine if the player has a straight.
	{																	// This code iterates through each bucket in the bucket counter,
		if (straightCounter == 5)										// and finds out if each successive bucket contains a card. If the bucket contains a card, 
		{																// straightCounter will increment by one. To have a straight,
			if (5 > score) { score = 5; }                               // five buckets in a row must contain one card. For example,                                                        
		}																// if bucket 0, 1, 2 each contain one card, and bucket 3 has
		if (bucketVector[i] > 0)                                        // has two cards, then the straightCounter will never increment
		{																// to 5 when searching the vector because the rest of the succeeding
			straightCounter++;                                          // buckets contain no cards. Therefore the straightCounter will be set to zero. 
		}
		else
		{
			straightCounter = 0;
		}
	}

	/*
	 If the straightCounter is equal to five, as explained in the previous code, there is a straight present. This code also
	 checks if any of the suit counters are eqaul to five. This would show that the hand has a flush as well. Therefore the 
	 player has a straight flush, and the score is set to 9. 
	*/
	
	if ((straightCounter == 5) && ((suitS >= 5) || (suitD >= 5) || (suitC >= 5) || (suitH >= 5)))      
	{
		if (9 > score) { score = 9; }
	}


	for (int i = 0; i < 13; i++)                                    // This code iterates through the bucket and checks if the player's 
	{																// hand is a Four-of-a-Kind, Full House, Three-of-a-Kind, Two pair,
																	// or single pair. 
		if (bucketVector[i] == 4)									// If any of the buckets contain 4 cards, than the player has a 
		{															// Four-of-a-Kind. The score is set to 8. 
			if (8 > score) { score = 8; }
		}

		if ((bucketVector[i] == 2) && (bucketVector[i] == 3))	  // If a bucket contains two cards, and another three, then the player 
		{														  // has a Full House, and the score is set to 7. 
			if (7 > score) { score = 7; }
		}
		
		if (bucketVector[i] == 3)							     // If a bucket contains three cards, than the code checks to see if 
		{                                                        // another bucket has two cards to signify a full house, otherwise the score is
						                                         // set to 4 to represent Three-of-a-Kind. 
			 if (score == 2) { //full house
				score = 7;
			}
			 else if (4 > score) { //3 of a kind
				 score = 4;
			 }
			
		}

		if (bucketVector[i] == 2)                               // If a bucket contains two cards, then the user has a pair, and the score is set
		{														// to 2. As the loop iterates through the bucket vector and finds another bucket that 
			if (2 > score) {									// contains two cards, and the score is already 2, than the player has two pairs.
				score = 2;
			}
			else if (score == 2) { //two pair
				score = 3;
			}
			else if (score == 4) { //full house               // If the bucket vector finds another bucket that contains two cards, and the hand already
				score = 7;                                    // has Three-of-a-Kind, then the player has a full house.
			}
		}

		if (((bucketVector[9] == 1) && (bucketVector[10] == 1)      // This is the highest hand the player can get. If the player has one 10, one Jack, 
			&& (bucketVector[11] == 1) && (bucketVector[12] == 1)   // one Queen, one King, and one Ace, all of them being the same suit, than the user has a Royal Flush.
			&& (bucketVector[0] == 1)) && ((suitS >= 5) || (suitD >= 5) || (suitC >= 5) || (suitH >= 5)))  // The score for a Royal Flush is 10. 
		{
			if (10 > score) { score = 10; }
		}
	}


	std:: cout << score; 

	std:: cout << suitS << suitD << suitC << suitH << endl;
	
}
#include <iostream>
#include <stdlib.h>                      // for rand function
#include <time.h>
#include <math.h>                        // function for ceiling and floor that was recommended
//#include <string>                        // include string 
#include "deck.h"
#include "hand.h"

using namespace std; 

void decideWinner(Hand hand1, Hand hand2);


int main(){

	Deck game1;                                // create Deck object
	game1.shuffle();

	Hand hand1(1),hand2(2);                          // create 2 hands
	hand1.addCards(game1, 0);
	hand2.addCards(game1, 1);

	game1.value.erase(game1.value.begin(), game1.value.begin() + 10);   // delete first ten cards from deck after dealt
	game1.suit.erase(game1.suit.begin(), game1.suit.begin() + 10);

	hand1.sortHand();
	hand2.sortHand();
	hand1.printHand();
	hand2.printHand();

	hand1.determineHand();
	hand2.determineHand();
	cout << endl;
	
	int cardsDrawn;
	cardsDrawn = hand1.drawCards(game1);
	game1.value.erase(game1.value.begin(), game1.value.begin() + cardsDrawn);   // delete cards drawn from deck
	game1.suit.erase(game1.suit.begin(), game1.suit.begin() + cardsDrawn);

	cardsDrawn = hand2.drawCards(game1);
	game1.value.erase(game1.value.begin(), game1.value.begin() + cardsDrawn);   // delete cards drawn from deck
	game1.suit.erase(game1.suit.begin(), game1.suit.begin() + cardsDrawn);

	cout << endl << "The deck now has " << game1.value.size() << " cards." << endl << endl;
	
	hand1.sortHand();
	hand2.sortHand();
	hand1.printHand();
	hand2.printHand();

	hand1.determineHand();
	hand2.determineHand();

	decideWinner(hand1, hand2);

	cin.get();
	return 0; 
}

void decideWinner(Hand hand1, Hand hand2)
{
	if( hand1.score > hand2.score ){
		cout << "Player " << hand1.playerNumber << " wins!";
	}

	else if( hand2.score > hand1.score ){
		cout << "Player " << hand2.playerNumber << " wins!";
	}
	
	else {
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

		if(hand1.score == 1)		// High Card
		{

			if( hand1.value.at(4) > hand2.value.at(4) )
				cout << "Player " << hand1.playerNumber << " wins!";
			else if( hand1.value.at(4) < hand2.value.at(4) )
				cout << "Player " << hand2.playerNumber << " wins!";
			else{
				if(hand1.value.at(3) > hand2.value.at(3))	cout << "Player " << hand1.playerNumber << " wins!";
				else if(hand1.value.at(3) < hand2.value.at(3)) cout << "Player " << hand2.playerNumber << " wins!";
				else{
					if(hand1.value.at(2) > hand2.value.at(2))	cout << "Player " << hand1.playerNumber << " wins!";
					else if(hand1.value.at(2) < hand2.value.at(2)) cout << "Player " << hand2.playerNumber << " wins!";
					else{
						if(hand1.value.at(1) > hand2.value.at(1))	cout << "Player " << hand1.playerNumber << " wins!";
						else if(hand1.value.at(1) < hand2.value.at(1)) cout << "Player " << hand2.playerNumber << " wins!";
						else{
							if(hand1.value.at(0) > hand2.value.at(0))	cout << "Player " << hand1.playerNumber << " wins!";
							else if(hand1.value.at(0) < hand2.value.at(0)) cout << "Player " << hand2.playerNumber << " wins!";
							else	cout << "It's a tie!";
						}
					}
				}
			}	
		}

		if(hand1.score == 2)		//1 Pair
		{
			int pair1 = 0 , pair2 = 0;
			int high11 = 0, high12 = 0, high13 = 0;
			int high21 = 0, high22 = 0, high23 = 0;

			for(int i = hand1.bucketVector.size()-1; i >= 0; i--){
				if(hand1.bucketVector.at(i) == 2)						pair1 = i+1;
				if(hand1.bucketVector.at(i) == 1 && high11 == 0)		high11 = i+1;
				if(hand1.bucketVector.at(i) == 1 && high11 != 0)		high12 = i+1;
				if(hand1.bucketVector.at(i) == 1 && high12 != 0)		high13 = i+1;

				if(hand2.bucketVector.at(i) == 2)						pair2 = i+1;
				if(hand2.bucketVector.at(i) == 1 && high21 == 0)		high21 = i+1;
				if(hand2.bucketVector.at(i) == 1 && high21 != 0)		high22 = i+1;
				if(hand2.bucketVector.at(i) == 1 && high22 != 0)		high23 = i+1;
			}

			if( pair1 > pair2 )
				cout << "Player " << hand1.playerNumber << " wins!";
			else if( pair1 < pair2 )
				cout << "Player " << hand2.playerNumber << " wins!";
			else{
				if(high11 > high21)	cout << "Player " << hand1.playerNumber << " wins!";
				else if(high11 < high21) cout << "Player " << hand2.playerNumber << " wins!";
				else{
					if(high12 > high22)	cout << "Player " << hand1.playerNumber << " wins!";
					else if(high12 < high22) cout << "Player " << hand2.playerNumber << " wins!";
					else{
						if(high13 > high23)	cout << "Player " << hand1.playerNumber << " wins!";
						else if(high13 < high23) cout << "Player " << hand2.playerNumber << " wins!";
						else{
							cout << "It's a tie!";
						}
					}
				}
			}	
		}

		if(hand1.score == 3)		//2 Pair
		{
			int pair11 = 0 , pair12 = 0 , pair21 = 0 , pair22 = 0;
			int high1 = 0 , high2 = 0;

			for(int i = hand1.bucketVector.size()-1; i >= 0; i--){
				if(hand1.bucketVector.at(i) == 2 && pair11 == 0)		pair11 = i+1;
				if(hand1.bucketVector.at(i) == 2 && pair11 != 0)		pair12 = i+1;
				if(hand1.bucketVector.at(i) == 1)						high1 = i+1;

				if(hand2.bucketVector.at(i) == 2 && pair21 == 0)		pair21 = i+1;
				if(hand2.bucketVector.at(i) == 2 && pair21 != 0)		pair22 = i+1;
				if(hand2.bucketVector.at(i) == 1)						high2 = i+1;
			}

			if( pair11 > pair21 )
				cout << "Player " << hand1.playerNumber << " wins!";
			else if( pair11 < pair21 )
				cout << "Player " << hand2.playerNumber << " wins!";
			else{
				if(pair12 > pair12)	cout << "Player " << hand1.playerNumber << " wins!";
				else if(pair12 < pair12) cout << "Player " << hand2.playerNumber << " wins!";
				else{
					if(high1 > high2)		cout << "Player " << hand1.playerNumber << " wins!";
					else if(high1 < high2)	cout << "Player " << hand2.playerNumber << " wins!";
					else					cout << "It's a tie!";
				}
			}	
			
		}

		if(hand1.score == 4)		//Three of a Kind
		{
			int pair1 = 0 , pair2 = 0;
			int high11 = 0, high12 = 0, high21 = 0, high22 = 0;

			for(int i = hand1.bucketVector.size()-1; i >= 0; i--){
				if(hand1.bucketVector.at(i) == 3)						pair1 = i+1;
				if(hand2.bucketVector.at(i) == 1 && high11 == 0)		high11 = i+1;
				if(hand2.bucketVector.at(i) == 1 && high11 != 0)		high12 = i+1;

				if(hand2.bucketVector.at(i) == 3)						pair2 = i+1;
				if(hand2.bucketVector.at(i) == 1 && high21 == 0)		high21 = i+1;
				if(hand2.bucketVector.at(i) == 1 && high21 != 0)		high22 = i+1;
			}

			if( pair1 > pair2 )
				cout << "Player " << hand1.playerNumber << " wins!";
			else if( pair1 < pair2 )
				cout << "Player " << hand2.playerNumber << " wins!";
			else{
				if(high11 > high21)				cout << "Player " << hand1.playerNumber << " wins!";
				else if(high11 < high21)		cout << "Player " << hand2.playerNumber << " wins!";
				else{
					if(high12 > high22)			cout << "Player " << hand1.playerNumber << " wins!";
					else if(high12 < high22)	cout << "Player " << hand2.playerNumber << " wins!";
					else						cout << "It's a tie!";
				}
			}	
		}

		if(hand1.score == 5)		//Straight
		{
			if( hand1.value.at(4) > hand2.value.at(4) )
				cout << "Player " << hand1.playerNumber << " wins!";
			else if( hand1.value.at(4) < hand2.value.at(4) )
				cout << "Player " << hand2.playerNumber << " wins!";
			else
				cout << "It's a tie!";
		}
	
		if(hand1.score == 6)		//Flush
		{
			if( hand1.value.at(4) > hand2.value.at(4) )
				cout << "Player " << hand1.playerNumber << " wins!";
			else if( hand1.value.at(4) < hand2.value.at(4) )
				cout << "Player " << hand2.playerNumber << " wins!";
			else{
				if(hand1.value.at(3) > hand2.value.at(3))	cout << "Player " << hand1.playerNumber << " wins!";
				else if(hand1.value.at(3) < hand2.value.at(3)) cout << "Player " << hand2.playerNumber << " wins!";
				else{
					if(hand1.value.at(2) > hand2.value.at(2))	cout << "Player " << hand1.playerNumber << " wins!";
					else if(hand1.value.at(2) < hand2.value.at(2)) cout << "Player " << hand2.playerNumber << " wins!";
					else{
						if(hand1.value.at(1) > hand2.value.at(1))	cout << "Player " << hand1.playerNumber << " wins!";
						else if(hand1.value.at(1) < hand2.value.at(1)) cout << "Player " << hand2.playerNumber << " wins!";
						else{
							if(hand1.value.at(0) > hand2.value.at(0))	cout << "Player " << hand1.playerNumber << " wins!";
							else if(hand1.value.at(0) < hand2.value.at(0)) cout << "Player " << hand2.playerNumber << " wins!";
							else	cout << "It's a tie!";
						}
					}
				}
			}
		}

		if(hand1.score == 7)		//Full House
		{
			int pair11 = 0 , pair12 = 0 , pair21 = 0 , pair22 = 0;

			for(int i = hand1.bucketVector.size()-1; i >= 0; i--){
				if(hand1.bucketVector.at(i) == 3)		pair11 = i+1;
				if(hand1.bucketVector.at(i) == 2)		pair12 = i+1;

				if(hand2.bucketVector.at(i) == 3)		pair21 = i+1;
				if(hand2.bucketVector.at(i) == 2)		pair22 = i+1;
			}

			if( pair11 > pair21 )
				cout << "Player " << hand1.playerNumber << " wins!";
			else if( pair11 < pair21 )
				cout << "Player " << hand2.playerNumber << " wins!";
			else{
				if(pair12 > pair12)			cout << "Player " << hand1.playerNumber << " wins!";
				else if(pair12 < pair12)	cout << "Player " << hand2.playerNumber << " wins!";
				else						cout << "It's a tie!";
			
			}	
			
		}


		if(hand1.score == 8)		//4 of a kind
		{
			int pair1 = 0 , pair2 = 0;
			int high1 = 0, high2 =0;

			for(int i = hand1.bucketVector.size()-1; i >= 0; i--){
				if(hand1.bucketVector.at(i) == 4)						pair1 = i+1;
				if(hand1.bucketVector.at(i) == 1)						high1 = i+1;

				if(hand2.bucketVector.at(i) == 4)						pair2 = i+1;
				if(hand2.bucketVector.at(i) == 1)						high2 = i+1;
			}

			if( pair1 > pair2 )
				cout << "Player " << hand1.playerNumber << " wins!";
			else if( pair1 < pair2 )
				cout << "Player " << hand2.playerNumber << " wins!";
			else{
				if(high1 > high2)			cout << "Player " << hand1.playerNumber << " wins!";
				else if(high1 < high2)		cout << "Player " << hand2.playerNumber << " wins!";
				else						cout << "It's a tie!";				
			}
		}

		if(hand1.score == 9)		//Straight Flush
		{
			if( hand1.value.at(4) > hand2.value.at(4) )
				cout << "Player " << hand1.playerNumber << " wins!";
			else if( hand1.value.at(4) < hand2.value.at(4) )
				cout << "Player " << hand2.playerNumber << " wins!";
			else
				cout << "It's a tie!";
		}

		if(hand1.score == 10)		//Royal Flush
			cout<< "It's a tie!";

	}
}
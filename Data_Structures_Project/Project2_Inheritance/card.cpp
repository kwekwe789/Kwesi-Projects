// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// kkyeifordjour
#include "card.h"
#include <string>
std::string Card::SUIT[] = {"No Suit", "Spades", "Hearts", "Diamonds", "Clubs"};

std::string Card::FACE[] = {"Joker", "Ace", "Two", "Three", "Four", "Five", "Six",  
                       "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

Card::Card() //Contstructor
{
}
Card::Card(int, int) //Contstructor for initialization
{
}
Card::~Card() //Destructor
{
}	 	

std::string Card::getSuit()	 //Function to return the suit value
{
return SUIT[suitVal_];
}
std::string Card::getFace()	 //Function to return the face value
{
	return FACE[faceVal_];
}
		/**
	     * Returns a string with the full name of the card. (e.g., "Ace of Spades")
	     *
	     * @return          String
	    */ 
std::string Card::print() //Function to print the card
{
	std::string cards = FACE[faceVal_] + " of " + SUIT[suitVal_] ;
	return cards;
}

void Card::initialize(int x, int y) //Function to give a card its face and suit
{
	suitVal_ = x;
	faceVal_ = y;
}
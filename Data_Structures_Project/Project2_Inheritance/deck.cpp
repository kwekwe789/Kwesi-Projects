// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// kkyeifordjour
#include "deck.h"
#include <iostream>
#include <iostream> //Here I define the libraries that I will use
#include <string>
#include <stdlib.h>
#include <time.h>
#include <iterator>

Deck::Deck() //Constructor that allocates memory
{
	deck_ = new Card[10000];
	numCards_ = 0;
	p = 1;
	b = 1;
}

Deck::~Deck() //Destructor
{
	delete [] deck_;
}

bool Deck::isEmpty() //Function that checks if the deck is empty
{
	if (numCards_ > 0)
	{
		return false;
	}
	else
	{
		return true;
	}
	
}

int Deck::getNumCards() //Function that returns the number of cards
{
	return numCards_;
}

void Deck::displayCard(int i) //Function that displays a particular card  in the deck
{
	std::cout<< "15th card: " <<  deck_[i].print() << std::endl;
}

void Deck::printDeck() //I create a loop to go through each card in the deck and print it using the print fucntion
{
	int i(0);
	int cnt(0);
		for(i=1; i<numCards_+1; i++)
		{
			std::cout << deck_[cnt].print() << std::endl;
			cnt++;
		}
}

bool Deck::addCard(Card c) //Function that checks if there is space in the deck and if there is, it will add a card to the back of it if not it will return false
{
	if(numCards_ < 52)
	{
		deck_[numCards_]= c;
		numCards_++;
		return true;
	}
	else 
	{
		std::cout<<"Deck is full...\n";
		return false;
	}
}

void Deck::shuffle() //Function that shuffles the deck
{
	int iterator(0),i(0),j(0),cnt1(0),cnt2(0),k(0),card(0),l(1); //Here I declare variables that I will need including an array of integers
	int num[4000];
	card = numCards_ - 1;
	Card place;
	srand((unsigned) time(NULL)); //Here I create a loop that will generate random numbers between 0 and 51 and put them into an array
	for(i = 1; i <= 4000 i++) 
	{
		num[j] = (rand() % card);
		j++;
	}	
	for(iterator=0;iterator<numCards_*3; iterator++)  //In this loop I essentially simulate swap sorting where I take 2 numbers from my array and swap the contents of the deck
	{										  //that pertain to their place in the deck, I do this swapping 160 to ensure it is shuffled well
		cnt1 = num[k];
		cnt2 = num[l];
		place = deck_[cnt1];
		deck_[cnt1]=deck_[cnt2];
		deck_[cnt2]=place;
		k = k+2;
		l = l + 2;
	}
}

Card Deck::dealCard() //Function where I return the top card of the deck, 
{
	int cnt(0);
	cnt = numCards_ - p;
	p++;
	return deck_[cnt];
}

Card Deck::dealBattle() // Another Function where I return the first card of the deck but this one also decreasing the number of cards in the deck eachtime it is called
{
	int cnt(0);
	cnt = numCards_ - b;
	numCards_ --;
	return deck_[cnt];
}

Card Deck::getCard(int i) //Function that returns a card based off of its position in the deck
{
	return deck_[i];
}


void Deck::reset1() //Function used to reset the number of cards in a deck to zero
{
	numCards_=0;
}

std::string Deck::getFace(int i) //function used to get the face value of a card given the position of that card in the deck
{
	return deck_[i].getFace();
}
	

void Deck::reset2()
{
	numCards_ = numCards_/2
}

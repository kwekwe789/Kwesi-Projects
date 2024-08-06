// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// kkyeifordjour
#include <iostream> //Here I define the libraries that I will use
#include <string>
#include "standardDeck.h"
#include <stdlib.h>
#include <time.h>
#include <iterator>
#include "deck.h"

StandardDeck::StandardDeck() //Constructor that allocates memory
{
	deck_ = new Card[52];
	numCards_ = 0;
	p = 1;
	b = 1;
}

StandardDeck::~StandardDeck() //Destructor
{
	delete [] deck_;
}


virtual bool mergeDecks(StandardDeck & D1, bool k) //Function that will merge 2 standard decks
{
	if (numCards_ < 52) //I want this to only work if the first deck isnt full
	{
		int x(0);	
		x = D1.numCards_; 
		int track(0);
		track = numCards_;
		for(int i=0; i<x; i++) //Here I have the next position in the first deck get the first card of the second deck then increase the number of cards in the first deck by 1
		{
			deck_[numCards_] = D1.deck_[i];
			numCards_ ++;
			if(numCards_ == 52)
			{
				break;
			}
		}
		if(k=true) //If the user inputs yes then the deck will automatically shuffle using the same code as shuffle from above
		{
			int iterator(0),i(0),j(0),cnt1(0),cnt2(0),k(0),card(0),l(1);
			int num[400];
			card = numCards_ - 1;
			Card place;
			srand((unsigned) time(NULL));
			for(i = 1; i <= 400; i++) 
			{
				num[j] = (rand() % card);
				j++;
			}	
			for(iterator=0;iterator<160; iterator++)
			{	
				cnt1 = num[k];
				cnt2 = num[l];
				place = deck_[cnt1];
				deck_[cnt1]=deck_[cnt2];
				deck_[cnt2]=place;
				k = k + 2;
				l = l + 2;
			}		
		}
	}
	return true;
}

virtual void StandardDeck::initializeDeck() //Function where I loop through and add 52 cards to a deck using the card initialize function
{
	
	int j(1);
	int i(0);
	int cnt(0);
	while(j<5)
	{
		for(i=1; i<13; i++)
		{
			deck_[cnt].initialize(j,i);
			cnt++;
		}
		j++; 
	} 
	numCards_ = cnt;	
}
	
virtual void StandardDeck::reset2() //Function used to set the number of cards in a deck to 26
{
	numCards_ = 26;
}
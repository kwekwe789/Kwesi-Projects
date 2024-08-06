// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// kkyeifordjour
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <cstddef>

NonStandardDeck::NonStandardDeck()
{
	deck_ = nullptr;
	p = 1;
	b = 1;
}

NonStandardDeck::~NonStandardDeck()
{
	virtual delete [] deck_;
}


virtual bool NonStandardDeck::mergeDecks(NonStandardDeck & D1, bool k)
{
	int x(0),t(0);
	x = D1.numCards_; 
	int track(0);
	track = numCards_;
	for(int i=0; i<x; i++)
	{
		deck_[numCards_] = D1.deck_[i];
		numCards_ ++;
	}
	if(k=true)
	{
		int iterator(0),i(0),j(0),cnt1(0),cnt2(0),k(0),card(0),l(1);
		int num[4000];
		card = numCards_ - 1;
		Card place;
		srand((unsigned) time(NULL));
		for(i = 1; i <= 4000; i++) 
		{
			num[j] = (rand() % card);
			j++;
		}	
		t = numCards_ * 3;
		for(iterator=0;iterator<t; iterator++)
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
	return true;
}

virtual void NonStandardDeck::initializeDeck()
{
	std::ifstream inStream; 
 	std::ifstream inputFile("Deck.txt");
	int x(0),y(0),z(0),a(0),k(0);
	while (!inputFile.eof())
	{		
		if(x ==0)
		{
			inputFile >> numCards_;
			x++;
			deck_ = new Card[numCards_ * 20];
		}
		else
		{
			inputFile >> y >> z;
			deck_[a].initialize(y,z);
			a++;
		}
	}
	inStream.close();
	p = numCards_;
}

// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// kkyeifordjour
#ifndef NON_STANDARD_DECK_H
#define NON_STANDARD_DECK_H

#include <iostream>
#include "card.h"
#include "deck.h"

class NonStandardDeck :public Deck
{
	public:
		/// Default constructor.
		NonStandardDeck();
		
		/// Default destructor.
		~NonStandardDeck();

		/**
	     * Returns True/False (1/0) whether or not the Deck is empty.
	     *
	     * @return          Boolean
	    */ 
		bool isEmpty();	

		/**
	     * Returns the number of cards remaining in the deck.
	     *
	     * @return          Integer		value
	    */ 
		int getNumCards();

		/**
	     * Displays the i'th card in the Deck.
	     *
		 * @param[in]      Index
	    */
		void displayCard(int i);

		/**
	     * Prints the contents of the Deck. This method should call the 
		 * print() method on each Card.
	    */
		void printDeck();	
		
		bool addCard(Card c);
		
		void shuffle(); 
		
		bool mergeDecks(NonStandardDeck & D1, bool k); 
		
		void initializeDeck();
		
		Card dealCard();
		
		Card dealBattle();
		
		Card getCard(int i);
		
		void reset1();
		
		void reset2();
		
		std::string getFace(int i);
		
		void initializeDeck2();
		
	protected: 
		Card * deck_;	// Pointer to record the location of the array of Cards in memory.
		int numCards_;
		int p; // Stores the number of Cards currently in the deck.
		int b;
};

#endif
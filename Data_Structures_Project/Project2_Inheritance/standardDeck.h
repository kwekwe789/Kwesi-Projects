// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// kkyeifordjour
#ifndef STANDARD_DECK_H
#define STANDARD_DECK_H

#include "card.h"
#include "deck.h"

#define DECK_SIZE 52

/**
 * @class StandardDeck
 *
 * The StandardDeck class represents a standard deck of 52 cards.
 * 
 */
class StandardDeck:public Deck
{
	public:
		
		virtual bool mergeDecks(StandardDeck & D1, bool k); 
		
		virtual void initializeDeck();
		
	protected: 
		Card * deck_;	// Pointer to record the location of the array of Cards in memory.
		int numCards_;
		int p; // Stores the number of Cards currently in the deck.
		int b;
};

#endif
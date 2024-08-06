// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// kkyeifordjour
#include "card.h"


class Deck
{
	public:
		/// Default constructor.
		Deck();
		
		/// Default destructor.
		~Deck();

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
		void printDeck();	// In the rest of this document I create other helper functions
		
		bool addCard(Card c);
		
		void shuffle(); 
		
		virtual bool mergeDecks(Deck & D1, bool k) = 0; 
		
		virtual void initializeDeck() = 0;
		
		Card dealCard();
		
		Card dealBattle();
		
		Card getCard(int i);
		
		void reset1();
		
		void reset2();
		
		std::string getFace(int i);
		
	protected: 
		Card * deck_;	// Pointer to record the location of the array of Cards in memory.
		int numCards_;
		int p; // Stores the number of Cards currently in the deck.
		int b;
};
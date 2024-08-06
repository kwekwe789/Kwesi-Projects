// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// kkyeifordjour
#include <iostream>
#include "card.h"
#include "standardDeck.h"
#include "nonstandardDeck.h"

void war();
//void war2();

int main()
{
	//war();
	StandardDeck deck;
	Deck * p1 = &deck;
	p1 -> initializeDeck();
} 

void war()
{
	/*StandardDeck deck;
	Deck * deck1 =  &StandardDeck(); //Here I create the decks that I will be using
	//Deck * p1 = new StandardDeck();
	//Deck * p2 = new StandardDeck();
	//Deck battle;
	Card c,k; //Here I initialze various variables and initialze one of the decks I previously created
	deck->initializeDeck();
	deck->shuffle();
	int y(0),m(0),e(0),g(0),h(0),w1(0),w2(0),win1(0),win2(0),avg1(0),avg2(0);
	for(int l = 0; l<26; l++) //After shuffling the dealers deck I deal out the deck to both players 
	{
		c = deck->dealCard();
		k = deck->dealCard();
		p1->addCard(c);
		p2->addCard(k);
		
	}
	while(h<50 ) //Loop used to simulate the game 50 times
	{
		int x(0),f(0),n(0),cnt(0),v(0); //Initializing more variables that I want to be reinitialized everytime the game is played
		m = p1->getNumCards() -2;
		e = p2->getNumCards() -1;
		battle.addCard(p1->dealBattle()); //Player 1 puts a card on the battle field
		while(v == 0) //A loop that will cause both players to put cards until the battle field until one wins that round
		{
			if(battle.getFace(x) == p2->getFace(e)) //Here I check if the face of the cards match and if they do I will merge player 2s deck with the battleground
			{
				p2->mergeDecks(battle,true);
				
			}
			else
			{
				battle.addCard(p2->dealBattle()); //If they dont match player 2 will put a card onto the battle field
			}
			x++;//Increases the position of the deck that I want to compare to
			if ( p2->getNumCards() ==52 )  // After a possible merge, if player 2 has 52 cards(player 1 has none) I will declare them the winner of this game, increase the number of 
			{								//wins by 1 and their total points by 52
				w2 = w2 + 52;
				win2++;
				v = 1;
				break;
			}
			if(battle.getNumCards() == 52) //If the battleground gets full Ill have the number of cards in the deck reset to 0
			{
				battle.reset1();
			}
			if(battle.getFace(x) == p1->getFace(m)) //Here I check if the face of the cards match and if they do I will merge player 1s deck with the battleground
			{
				p1->mergeDecks(battle,true);
			}
			else
			{
				battle.addCard(p1->dealBattle()); //If they dont match player 1 will put a card onto the battle field
			}
			x++;
			
			m--; //Here I change the card of both players deck that I want to use to compare 
			e--;
			f++;
			if ( p1->getNumCards() ==52 ) // After a possible merge, if player 1 has 52 cards(player 2 has none) I will declare them the winner of this game, increase the number of
			{								//wins by 1 and their total points by 52
				w1 = w1 + 52;
				win1++;
				v = 1;
				break;
			}
			if(battle.getNumCards() == 52)
			{
				battle.reset1();
			}
		}	
		battle.reset1(); 	//Here I reset the battle ground/ shuffle the cards in both players hands so I dont have to redeal them/ then reset their number of cards back to 26 to start a new game
		p1->shuffle();
		p2->shuffle();
		p1->reset2();
		p2->reset2();
	h++;
	}
	if (win1 > win2) //Here I print out who won the game with how many wins they had
	{
		std::cout << "Player 1 was the champion with " << win1<<" victories versus Player 2." <<std::endl;
	}
	else if(win2 > win1)
	{
		std::cout << "Player 2 was the champion with " << win2<<" victories versus Player 1." <<std::endl;
	}
	else if(win1 == win2)
	{
		std::cout << "Player 1 and Player 2 have tied." <<std::endl;
	}
	avg1 = w1/50; //Here I compute and print out theur average number of points per game
	avg2 = w2/50;
	std::cout << "\n";
	std::cout << "Player 1 Average Score: " << avg1 << std::endl; 
	std::cout << "Player 2 Average Score: " << avg2 << std::endl; 
	
	delete p1; //Here I delete all decks that I created.
	delete p2;
	delete deck;*/
}


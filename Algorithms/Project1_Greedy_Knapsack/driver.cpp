#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "item.h"
#include <string>
#include "pq.h"
//Running the program is pretty simple, all you have to do is fill the textFile
//input with the desired n value and the program will take care of the rest.
//If you do want to use a randomly generated textfile just comment out that
//unction and it should work properly. Also make sure the textfile you are
//trying to do work on is called "test.txt"
//you may have to create a pq.cpp that is just blank for it to process in the
//makefile
void textFile(int n); //function to generate text file with needed information
int main()
{
	textFile(20); //calling textfile generation function
	std::string name(""); //function declaration
	int num_items(0), i(0),j(0);
	double pesos(0), weight(0), ratio(0), capacity(0), totweight(0), totprof(0);
	std::ifstream inputFile("test.txt"); //opens text file and reads in
	information
	inputFile >> num_items >> capacity;
	Item items;
	Item solution[num_items];
	pq<Item> que; //ceates priority que for items
	for (int i=0; i<num_items; i++) //reads in a text file and enqueues the read in items
	{
		inputFile >>name>> pesos >> weight;
		items.setName(name);
		items.setPesos(pesos);
		items.setWeight(weight);
		ratio = pesos/weight;
		items.setRatio(ratio);
		que.enqueue(items);
	}
	inputFile.close();
	for(int i=0; i<num_items; i++) //checks if each item in the priority queue will fit and if it does it inserts it into the solution array
	{
	Item check = que.dequeue();
		if(check.getWeight() <=capacity)
		{
			solution[j].setItem(check);
			capacity = capacity - check.getWeight();
			totweight = totweight + check.getWeight();
			totprof = totprof + check.getPesos();
			j++;
		}
	}
	std::cout<< "There are " << j << " items in the solution" << std::endl;
	//prints out the results of the comparisons with the items that did fit
if(j > 0)
{
		std::cout<< std::endl;
		std::cout<< "The total profit of items in the solution is " << totprof << std::endl;
		std::cout<< std::endl;
		std::cout<< "The total weight of items in the solution is " <<
		totweight << std::endl;
		std::cout<< std::endl;
		std::cout<< "Items in the solution: \n";
		for(int i=0; i<j; i++)
		{
			std::cout<< "Item " << i+1 << " name: " << solution[i].getName()
			<< " Item " << i+1 << " pesos: " << solution[i].getPesos() << " Item " << i+1 << "
			weight: " << solution[i].getWeight() << std::endl;
		}
	}
	else
	{
	}
	return 0;
}
void textFile(int n)
{
	srand((unsigned) time(NULL)); //seed for random number generator
	int w = n * 2 + (((rand() % (8*n)) + 1)^n); //usues random number to givetotal capacity based on input n
	std::ofstream outStream("test.txt"); //opens outstream
	outStream << n << " " << w << std::endl;
	std::string letters[26] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j","k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"}; //creates array of letters
	for(int j=0; j<n; j++)
	{
		std::string name("");
		int weight(0), pesos(0);
		weight = (rand() % (3*n)) + 1; //generates random weight
		pesos = (rand() % ((w+1)*2)) + 1; //generates random pesos value
	for(int i = 1; i <= 3; i++) //generates name based on random lettersand numbers
	{
		name = letters[(rand() % 25)] + name;
	}
	for(int i = 1; i <= 3; i++)
	{
		name = std::to_string(rand() % 9) + name;
	}
		outStream << name << " " << weight << " " << pesos << std::endl;
	//fills text file
		}
		outStream.close();
}

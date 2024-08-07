#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <cmath>

void textFile(int n);

int main()
{
	textFile(20);
	return 0;
}


void textFile(int n)
{
	srand((unsigned) time(NULL)); //seed for random number generator
	int w = n * 2 + (((rand() % (8*n)) + 1)^n); //usues random number to give total capacity based on input n 
	std::ofstream outStream("test.txt"); //opens outstream
	outStream << n << " " << w << std::endl;
	std::string letters[26] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"}; //creates array of letters

	for(int j=0; j<n; j++)
	{
		std::string name(""); 
		int weight(0), pesos(0);
		weight = (rand() % (3*n)) + 1; //generates random weight
		pesos = (rand() % ((w+1)*2)) + 1; //generates random pesos value
		for(int i = 1; i <= 3; i++) //generates name based on random letters and numbers
		{
			name = letters[(rand() % 25)] +  name;
			
		}
		for(int i = 1; i <= 3; i++) 
		{
			name = std::to_string(rand() % 9) +  name;	
		}

		outStream << name << " " << weight << " " << pesos << std::endl; //fills text file
	}
	outStream.close();
}
//Honor Pledge:
//I pledge that I have neither given nor
//received any help on this assignment.
//wkissel, majames, sjhartman, kkyeifordjour

#include <iostream>
#include <fstream>
#include "HashTableChaining.h"
#include "HashTableArray.h"
#include "HashTableCuckoo.h"

 
void printOptions(); //function definition

int main()
{
	int select1(0), select2(0), select3(0), i(0); // initialization of variables
	int key = 0;
	int value = 0;
	HashEntry entry [100]; //creates an array of 100 HashEntry
	std::ifstream inputFile("data.txt");
	while (!inputFile.eof()) //reads in a text file and sets the entries key as well as value based on read in value
	{
		inputFile >> key >> value;
		entry[i].setKey(key);
		entry[i].setValue(value);
		i++;
	}
	inputFile.close();
	do
	{
		std::cout << "Welcome to Blue IV's Can of Who Hash!" << std::endl; //prints menu options and allows for the user to insert choices
		std::cout << std::endl;
		std::cout << "1)\tLinear Probing" << std::endl;
		std::cout << "2)\tQuadratic Probing" << std::endl;
		std::cout << "3)\tSeparate Chaining" << std::endl;
		std::cout << "4)\tCuckoo Hashing" << std::endl;
		std::cout << "5)\tQuit Program" << std::endl;
		std::cout << std::endl;
		std::cout << "Please enter your choice: ";
		std::cin >> select1;
		std::cout << std::endl;
		if (select1 == 5) //if 5 is entered the project will terminate
		{
			std::cout << "Thank you for using Blue IV's program - Goodbye!" << std::endl;
			std::cout << std::endl;
			break;
		}
		
		
		else if (select1 == 1) //linear Probing
		{
			std::cout << "Please enter the size of the Hash Table you wish to create: ";
			std::cin >> select2;
			std::cout << std::endl;
			int searchk(0);
			int removek(0);
			HashTableArray * array = new HashTableArray(select2, LINEAR); //creates a hasharray  
			
			for(int x = 0; x < i; x++) //inserts the textfile data based of linear probing
			{
				int z = entry[x].getKey();
				int y = entry[x].getValue();
				array->insert(z,y);
			}
			
			
			array->print();
			
			do 
			{
				printOptions(); //prints menu options
				std::cout << "Please enter your choice: ";
				std::cin >> select3;
				std::cout << std::endl;
				if (select3 == 4) //deletes array and returns to main menu
				{
					array->reset(select2);
					delete array;
					std::cout << std::endl;
				}
				else if (select3 == 1) //search funtion for the table
				{
					std::cout << "Search (Please enter a Key): ";
					std::cin >> searchk;
					std::cout << std::endl;
					int value = array->search(searchk);
					

				}
				else if (select3 == 2) //remove funtion for the table
				{
					std::cout << "Remove (Please enter a Key): ";
					std::cin >> removek;
					std::cout << std::endl;
					array->remove(removek);
				}
				else if (select3 == 3) //print function for table
				{
					array->print();
				}
				else
				{
					std::cout << "Invalid Selection! Please enter a valid selection." << std::endl;
					std::cout << std::endl;
				}
			}
			while(select3 !=4);
		}
		else if (select1 == 2)
		{
			std::cout << "Please enter the size of the Hash Table you wish to create: ";
			std::cin >> select2;
			std::cout << std::endl;
			int searchk(0);
			int removek(0);
			HashTableArray * array = new HashTableArray(select2, QUADRATIC); //creating and quadratic probing of the table
			for(int x(0); x < i; x++)
			{
				array->insert(entry[x].getKey(),entry[x].getValue());
			}
			array->print();
			do 
			{
				printOptions();
				std::cout << "Please enter your choice: ";
				std::cin >> select3;
				std::cout << std::endl;
				if (select3 == 4) //deletes array and returns to main menu
				{
					array->reset(select2);
					delete array;
					std::cout << std::endl;
				}
				else if (select3 == 1) //search funtion for the table
				{
					std::cout << "Search (Please enter a Key): ";
					std::cin >> searchk;
					std::cout << std::endl;
					int value = array->search(searchk);
				}
				else if (select3 == 2) //remove funtion for the table
				{
					std::cout << "Remove (Please enter a Key): ";
					std::cin >> removek;
					std::cout << std::endl;
					array->remove(removek);
				}
				else if (select3 == 3) //print function for table
				{
					array->print();
				}
				else
				{
					std::cout << "Invalid Selection! Please enter a valid selection." << std::endl;
				}
			}
			while(select3 !=4);
		}
		else if (select1 == 3)
		{
			std::cout << "Please enter the size of the Hash Table you wish to create: ";
			std::cin >> select2;
			std::cout << std::endl;
			int searchk(0);
			int removek(0);
			HashTableChaining* chaining = new HashTableChaining(select2); //creation of the table using seperate chaining
			for (int x(0); x < i; x++)
			{
				int z = entry[x].getKey();
				int y = entry[x].getValue();
				chaining->insert(z,y);
			}
			chaining->print();
			do
			{
				printOptions();
				std::cout << "Please enter your choice: ";
				std::cin >> select3;
				std::cout << std::endl;
				if (select3 == 4) //deletes array and returns to main menu
				{
					delete chaining;
					std::cout << std::endl;
				}
				else if (select3 == 1) //search funtion for the table
				{
					std::cout << "Search (Please enter a Key): ";
					std::cin >> searchk;
					std::cout << std::endl;
					int value = chaining->search(searchk);
					if (value != 0)
					{
						std::cout << "Key: " << searchk << " Value: " << value << std::endl;
					}
					else
					{
						std::cout << "Key not found in table." << std::endl;
					}
				}
				else if (select3 == 2) //remove funtion for the table
				{
					std::cout << "Remove (Please enter a Key): ";
					std::cin >> removek;
					std::cout << std::endl;
					chaining->remove(removek);
				}
				else if (select3 == 3) //print function for table
				{
					chaining->print();
				}
				else
				{
					std::cout << "Invalid Selection! Please enter a valid selection." << std::endl;
				}
			} while (select3 != 4);

		}
		else if (select1 == 4) 
		{
			std::cout << "Please enter the size of the Hash Table you wish to create: ";
			std::cin >> select2;
			std::cout << std::endl;
			int searchk(0);
			int removek(0);
			int extraspots = 1;
			bool cycle = false;
			HashTableCuckoo* cuckoo = new HashTableCuckoo(select2); //creating of the cuckoo tables
			for (int x = 0; x < i; x++)
			{
				cuckoo->insert(entry[x].getKey(), entry[x].getValue());
				cycle = cuckoo->getCycle();
			}
			while (cycle) // if a cycle occurs we rehash here by increasing the size of the tables that we are using
			{
				std::cout << "Cycle present. Expanding tables by 1 and rehashing." << std::endl;
				delete cuckoo;
				HashTableCuckoo* cuckoo = new HashTableCuckoo(select2+extraspots);
				for (int x(0); x < i; x++)
				{
					cuckoo->insert(entry[x].getKey(), entry[x].getValue());
					cycle = cuckoo->getCycle();
				}
				extraspots++;
			}
			cuckoo->print();
			do
			{
				printOptions();
				std::cout << "Please enter your choice: ";
				std::cin >> select3;
				std::cout << std::endl;
				if (select3 == 4) //deletes array and returns to main menu
				{
					delete cuckoo;
					std::cout << std::endl;
				}
				else if (select3 == 1) //search funtion for the table
				{
					std::cout << "Search (Please enter a Key): ";
					std::cin >> searchk;
					std::cout << std::endl;
					int value = cuckoo->search(searchk);
					if (value != 0)
					{
						std::cout << "Key: " << searchk << " Value: " << value << std::endl;
					}
					else
					{
						std::cout << "Key not found in table." << std::endl;
					}
					
				}
				else if (select3 == 2) //remove funtion for the table
				{ 
					std::cout << "Remove (Please enter a Key): ";
					std::cin >> removek;
					std::cout << std::endl;
					cuckoo->remove(removek);
				}
				else if (select3 == 3) //print function for table
				{
					cuckoo->print();
				}
				else
				{
					std::cout << "Invalid Selection! Please enter a valid selection." << std::endl;
					std::cout << std::endl;
				}
			} while (select3 != 4);
		}
		else
		{
			std::cout << "Invalid Selection! Please enter a valid selection." << std::endl;
			std::cout << std::endl;
		}
		
	}
	while(select1 != 5);
	return 0;
}

void printOptions() //prints menu options
{
	std::cout << "1)\tSearch For Entry" << std::endl;
	std::cout << "2)\tRemove Entry" << std::endl;
	std::cout << "3)\tPrint Hash Table" << std::endl;
	std::cout << "4)\tReturn to Main Menu" << std::endl;
	std::cout << std::endl;
}

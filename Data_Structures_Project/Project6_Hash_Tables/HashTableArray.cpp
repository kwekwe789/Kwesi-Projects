//Hash Table Array Class Definition
//Honor Pledge:
//I pledge that I have neither given nor
//received any help on this assignment.
//wkissel, majames, sjhartman, kkyeifordjour
#include "HashTableArray.h"

HashTableArray::HashTableArray(int size, Probing probing) : HashTable() //Constructor 
{
	size_ = size;
	entry_ = new HashEntry[size];
	probing_ = probing;
}

HashTableArray::~HashTableArray() //Destructor
{
	if (entry_ != NULL)
	{
		delete[] entry_;
	}
}

void HashTableArray::insert(int key, int value) //insert function
{
	int x = 0; //initialization of variables that will be used
	int y = 0; 
	int n = 0;
	int z = size_ - 1;
	int place = 0;
	if(probing_ == LINEAR) //checking the probing type
	{
		for(int i = 0; i < size_; i++) //a loop to iterate through possible hash positions
		{	
			if(y == 0) //if statement to check if youve reached the end of the array
			{
		
				place  = (key+x) % size_; //linear probing equation
				if (entry_[place].getStatus() == EMPTY) //if the bucket is empty it will fill the bucket with the key and value and set its status to full
				{
					entry_[place].setKey(key);
					entry_[place].setValue(value);
					entry_[place].setStatus(OCCUPIED);
					break;
				}
				else //if its occupied it will check if the position is at the end of the array and if it is it will go to the beginning, if not it will increase "x" of the function
				{
					if(place == z)
					{
						y = 1; //you have reached the end of the array
						place = 0;
					}
					else
					{
						x++;
					}
				}
			}
			else
			{
				if (entry_[place].getStatus() == EMPTY) //this is for when you start at the beginning of the array, and if you find an open bucket you will fill it
				{
					entry_[place].setKey(key);
					entry_[place].setValue(value);
					entry_[place].setStatus(OCCUPIED);
					break;
				}
				else
				{
					place++; //increases the position of where you check
				}
			}
		}
	}
	else
	{
		int m(0); //initialization of variables
		int a(0);
		int s(0);
		int temp(0);
		for(int i = 0; i < size_; i++) //Constructor 
		{
			if(n == 0) //if statement to check if youve reached the end of the array
			{
				m = a*a;
				place  = (key+m) % size_; //quadratic probing equation
				if (entry_[place].getStatus() == EMPTY) //if the bucket is empty it will fill the bucket with the key and value and set its status to full
				{
					entry_[place].setKey(key);
					entry_[place].setValue(value);
					entry_[place].setStatus(OCCUPIED);
					break;
				}
				else //if its occupied it will check if the next position will go past the bounds of the array and if so it will loop to the beginning, if not it will increase "a" of the function
				{
					a++;
					temp = (key + (a*a)) % size_;
					if(temp > z)
					{
						n = 1; //the function will loop to the beginning
					}
				}
			}
			else
			{
				s = size_ - (key % size_); //when you loop around this is the formula used to figure out how many places to go from the beginning
				place = (a*a) - s;
				if (entry_[place].getStatus() == EMPTY) //if the bucket is empty it will fill the bucket with the key and value and set its status to full
				{
					entry_[place].setKey(key);
					entry_[place].setValue(value);
					entry_[place].setStatus(OCCUPIED);
					break;
				}
				else
				{
					a++;
				}
			}
		}
	}
} 

int HashTableArray::search(int key) //search function
{
	int y(0), x(0); //initialization of variables
	int z = size_ - 1;
	int place(0);
	int found(0);
	if(probing_ ==  LINEAR) //everything here is almost exact as the insert function except for the if conditions and what you do when the key matches
	{
		for(int i = 0; i < size_; i++)
		{	
			if(y == 0)
			{
				place  = (key+x) % size_;
				if (entry_[place].getKey() == key && entry_[place].getStatus() == OCCUPIED) //here if checks if the key inputed matches a key in the table and if it does it will print it out and change the found variable
				{
					std::cout<< "Key: " << entry_[place].getKey() << " Value: " << entry_[place].getValue() << std::endl;
					found = 1;
					break;
				}
				else
				{
					if(place == z)
					{
						y = 1;
						place = 0;
					}
					else
					{
						x++;
					}
				}
			}
			else
			{
				if (entry_[place].getKey() == key && entry_[place].getStatus() == OCCUPIED) //if you loop around the array this is the code used to find the key
				{
					std::cout<< "Key: " << entry_[place].getKey() << " Value: " << entry_[place].getValue() << std::endl;
					found = 1;
					break;
				}
				else
				{
					place++;
				}
			}
		}
	}
	else
	{
		int m(0); 
		int a(0);
		int s(0);
		int temp(0);
		int place(0);
		int n(0);
		for(int i = 0; i < size_; i++) //this is the searching for quadratic hashing and as said above everything is almost the same as the insert function
		{
			if(n == 0)
			{
				m = a*a;
				place  = (key+m) % size_;
				if (entry_[place].getKey() == key && entry_[place].getStatus() == OCCUPIED)
				{
					found = 1;
					std::cout<< "Key: " << entry_[place].getKey() << " Value: " << entry_[place].getValue() << std::endl; //if the key matches the key will be printed out onto the screen
					break;
				}
				else
				{
					a++;
					temp = (key + (a*a)) % size_;
					if(temp > z)
					{
						n = 1;
					}
				}
			}
			else
			{
				s = size_ - (key % size_);
				place = (a*a) - s;
				if (entry_[place].getKey() == key && entry_[place].getStatus() == OCCUPIED) //code for if the array needs to be looped around
				{
					std::cout<< "Key: " << entry_[place].getKey() << " Value: " << entry_[place].getValue() << std::endl;
					found = 1;
					break;
				}
				else
				{
					a++;
				}
			}
		}
	}
	if (found > 0)
	{
		
	}
	else
	{
		std::cout<< "Invalid key! Key " << key << " not found in table!" << std::endl; //if the key is not found it will print it out
	}
	std::cout << std::endl;
	return place;
}

void HashTableArray::remove(int key) //uses same process as insert and search but when the key is found it sets the status to removed
{
	int y(0), x(0);
	int z = size_ - 1;
	int place(0);
	int found(0);
	if(probing_ ==  LINEAR)
	{
		for(int i = 0; i < size_; i++)
		{	
			if(y == 0)
			{
				place  = (key+x) % size_;
				if (entry_[place].getKey() == key && entry_[place].getStatus() == OCCUPIED)
				{
					found = 1; //breaks if the key is found
					break;
				}
				else
				{
					if(place == z)
					{
						y = 1;
						place = 0;
					}
					else
					{
						x++;
					}
				}
			}
			else
			{
				if (entry_[place].getKey() == key && entry_[place].getStatus() == OCCUPIED)
				{
					found = 1; //breaks if the key is found
					break;
				}
				else
				{
					place++;
				}
			}
		}
	}
	else
	{
		int m(0); 
		int a(0);
		int s(0);
		int temp(0);
		int place(0);
		int n(0);
		for(int i = 0; i < size_; i++)
		{
			if(n == 0)
			{
				m = a*a;
				place  = (key+m) % size_;
				if (entry_[place].getKey() == key && entry_[place].getStatus() == OCCUPIED)
				{
					found = 1; //breaks if the key is found
					break;
				}
				else
				{
					a++;
					temp = (key + (a*a)) % size_;
					if(temp > z)
					{
						n = 1;
					}
				}
			}
			else
			{
				s = size_ - (key % size_);
				place = (a*a) - s;
				if (entry_[place].getKey() == key && entry_[place].getStatus() == OCCUPIED)
				{
					found = 1; //breaks if the key is found
					break;
				}
				else
				{
					a++;
				}
			}
		}
	}
	if(found == 1) //if found is 1 then it sets the status of the key to removed
	{
		entry_[place].setKey(0);
		entry_[place].setValue(0);
		entry_[place].setStatus(REMOVED);
		std::cout << "Key " << key << " removed." <<std::endl;
	}
	else 
	{
		std::cout<< "Invalid key! Key " << key << " not found in table!" << std::endl; //if not it will say the key isnt found
	}
	std::cout << std::endl;
}

void HashTableArray::print()
{
	std::cout << "**************************" << std::endl; 
	for(int i = 0; i < size_; i++)
	{
		std::cout << "[" << i << "]: ";
		if (entry_[i].getStatus() == OCCUPIED) //goes through table to see if the status is occupied and if it is it will print the contents
		{
			std::cout << entry_[i].getKey() << std::endl;
		}
		else
		{
			std::cout << std::endl;
		}
	}
	std::cout << "**************************" << std::endl; 
	std::cout << std::endl;
}

void HashTableArray::reset(int size) //used to reset the status of all of the buckets to empety when the table is deleted
{
	for(int i = 0; i < (size); i++)
	{
		if(entry_[i].getStatus() != EMPTY)
		{
			entry_[i].setStatus(EMPTY);
		}
	}
}
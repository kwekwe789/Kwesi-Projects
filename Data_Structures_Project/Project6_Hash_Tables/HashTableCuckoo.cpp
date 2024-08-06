//Hash Table Cuckoo Class Declaration
//Honor Pledge:
//I pledge that I have neither given nor
//received any help on this assignment.
//wkissel, majames, sjhartman, kkyeifordjour

#include "HashTableCuckoo.h"

//Constructor
HashTableCuckoo::HashTableCuckoo(int size) : HashTable() //Constructor 
{
	size_ = size;
	cycle_ = false;
	entry_ = new HashEntry[size];
	entry2_ = new HashEntry[size];
}

//Destructor
HashTableCuckoo::~HashTableCuckoo()
{
	if (entry_ != NULL)
	{
		delete[] entry_;
	}

	if (entry2_ != NULL)
	{
		delete[] entry2_;
	}
}

//Accessor Methods
int HashTableCuckoo::getSize()
{
	return size_;
}

void HashTableCuckoo::setSize(int size)
{
	size_ = size;
}

bool HashTableCuckoo::getCycle()
{
	return cycle_;
}

void HashTableCuckoo::setCycle(bool cycle)
{
	cycle_ = cycle;
}

int HashTableCuckoo::hash1(int key)
{
	return key % size_;;
}

int HashTableCuckoo::hash2(int key)
{
	return (key / size_) % size_;
}

//Hash functions
void HashTableCuckoo::insert(int key, int value) //creates 2 arrays 
{
	int hashindex1 = hash1(key);
	int hashindex2 = hash2(key);
	int tempValue = 0;
	int tempKey = 0;
	int count = 0;
	while (count <= size_) //checks to see if we need to rehash
	{
		if (entry_[hashindex1].getStatus() == OCCUPIED) //goes through the hashing arrays to check the status of the buckets
		{
			tempKey = entry_[hashindex1].getKey();
			tempValue = entry_[hashindex1].getValue();
			entry_[hashindex1].setKey(key);
			entry_[hashindex1].setValue(value);

			if (entry2_[hashindex2].getStatus() == OCCUPIED) 
			{
				tempKey = entry2_[hashindex2].getKey();
				tempValue = entry2_[hashindex2].getValue();
				entry2_[hashindex2].setKey(key);
				entry2_[hashindex2].setValue(value);

			}
			else
			{
				entry2_[hashindex2].setValue(tempValue);
				entry2_[hashindex2].setKey(tempKey);
				entry2_[hashindex2].setStatus(OCCUPIED);
				return;
			}

		}
		else
		{
			entry_[hashindex1].setValue(value);
			entry_[hashindex1].setStatus(OCCUPIED);
			entry_[hashindex1].setKey(key);
			return;
		}
		count++;
		if (count > size_) //condition to cause a rehash
		{
			cycle_ = true;
		}
	}
}


int HashTableCuckoo::search(int key) //checks both tables for the key
{
	for (int i = 0; i < size_; i++)
	{
		if (entry_[i].getKey() == key && entry_[i].getStatus() == OCCUPIED)
		{
			return entry_[i].getValue();
		}
		if (entry2_[i].getKey() == key && entry2_[i].getStatus() == OCCUPIED)
		{
			return entry2_[i].getValue();
		}
	}
	return 0;
}

void HashTableCuckoo::remove(int key) //checks both tables for the key, if it is there it will remove it
{
	for (int i = 0; i < size_; i++)
	{
		if (entry_[i].getKey() == key && entry_[i].getStatus() == OCCUPIED)
		{
			entry_[i].setStatus(REMOVED);
			std::cout << "Key " << key << " removed." << std::endl;
			return;
		}
		else if (entry2_[i].getKey() == key && entry2_[i].getStatus() == OCCUPIED)
		{
			entry2_[i].setStatus(REMOVED);
			std::cout << "Key " << key << " removed." << std::endl;
			std::cout << std::endl;
			return;
		}
	}
	std::cout << "Key " << key << " was not found in the tables." << std::endl;
}

void HashTableCuckoo::print() //prints both tables based off if the buckets are occupied
{
	std::cout << "***************" << std::endl;
	for(int i = 0; i < size_; i++)
	{
		if (entry_[i].getStatus() == OCCUPIED)
		{
			std::cout << "[" << i << "]: " << entry_[i].getKey() << std::endl;
		}
		else
		{
			std::cout << "[" << i << "]: " << std::endl;
		}
	}
	std::cout << "***************" << std::endl;

	std::cout << "***************" << std::endl;
	for (int i = 0; i < size_; i++)
	{
		if (entry2_[i].getStatus() == OCCUPIED)
		{
			std::cout << "[" << i << "] " << entry2_[i].getKey() << std::endl;
		}
		else
		{
			std::cout << "[" << i << "] " << std::endl;
		}
	}
	std::cout << "***************" << std::endl;
	std::cout << std::endl;
}
//Hash Table Chaining Class Definition
//Honor Pledge:
//I pledge that I have neither given nor
//received any help on this assignment.
//wkissel, majames, sjhartman, kkyeifordjour

#include "HashTableChaining.h"


HashTableChaining::HashTableChaining(int size) //Constructor 
{
	size_ = size;
	entry_ = new DoublyLinkedList[size];
}

HashTableChaining::~HashTableChaining() //Destructor
{
	if (entry_ != NULL)
	{
		delete[] entry_;
	}
}
void HashTableChaining::insert(int key, int value) //inserts by creating a node based of the passed in values to insert next in the LinkedNode
{
	HashEntry entry;
	entry.setKey(key);
	entry.setValue(value);
	int position = key % size_;
	LinkedNode* newNode = new LinkedNode(entry, nullptr, nullptr);
	entry_[position].insertLinkedNode(newNode, entry);
	delete newNode;
}

int HashTableChaining::search(int key) //goes the the links of the has position and iterates to find the key
{
	int position = 0;
	for (int i = 0; i < size_; i++)
	{
		position = entry_[i].find(key);
		if (position != 0)
		{
			return position;
		}
	}
	return position;
}

void HashTableChaining::remove(int key) //if the key exists in the link of the hash position it will use the remove link function
{
	for (int i = 0; i < size_; i++)
	{
		if (entry_[i].findKey(key) == key)
		{
			entry_[i].removeLinkedNode(key);
			std::cout << "Key " << key << " removed." << std::endl;
			return;
		}
	}
	std::cout << "Key " << key << " not found in table." << std::endl;
	std::cout << std::endl;
}

void HashTableChaining::print() //prints the table
{
	std::cout << "***************" << std::endl;
	for (int i = 0; i < size_; i++)
	{
		std::cout << "[" << i << "]: ";
		if (entry_[i].getHead() != nullptr)
		{
			entry_[i].printList();
		}
		std::cout << std::endl;
	}
	std::cout << "***************" << std::endl;
	std::cout << std::endl;

}
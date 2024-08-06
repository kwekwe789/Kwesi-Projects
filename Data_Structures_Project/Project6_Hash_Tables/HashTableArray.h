//Hash Table Array Class Declaration
//Honor Pledge:
//I pledge that I have neither given nor
//received any help on this assignment.
//wkissel, majames, sjhartman, kkyeifordjour
#include "HashTable.h"
#include "HashEntry.h"
#include <iostream>
enum Probing { LINEAR, QUADRATIC };
class HashTableArray : public HashTable
{

	public:
	
		HashTableArray(int size, Probing probing);
		~HashTableArray();
		void insert(int key, int value);
		int search(int key);
		void remove(int key);
		void print();
		void reset(int size);
		
	private:
		HashEntry * entry_;
		int size_;
		Probing probing_;
};
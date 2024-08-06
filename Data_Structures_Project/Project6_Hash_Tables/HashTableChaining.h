//Hash Table Chaining Class Declaration
//Honor Pledge:
//I pledge that I have neither given nor
//received any help on this assignment.
//wkissel, majames, sjhartman, kkyeifordjour

#include "HashTable.h"
#include "DoublyLinkedList.h"

class HashTableChaining : public HashTable
{

	public:
		HashTableChaining(int size);
		~HashTableChaining();
		void insert(int key, int value);
		int search(int key);
		void remove(int key);
		void print();

	private:
		DoublyLinkedList* entry_;
		int size_;
};
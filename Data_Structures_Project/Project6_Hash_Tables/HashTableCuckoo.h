//Hash Table Cuckoo Class Definition
//Honor Pledge:
//I pledge that I have neither given nor
//received any help on this assignment.
//wkissel, majames, sjhartman, kkyeifordjour

#include "HashTable.h"
#include "HashEntry.h"

class HashTableCuckoo : public HashTable
{
	public:

		HashTableCuckoo(int size);
		~HashTableCuckoo();

		int getSize();
		void setSize(int size);

		bool getCycle();
		void setCycle(bool cycle);

		int hash1(int key);
		int hash2(int key);

		void insert(int key, int value);
		int search(int key);
		void remove(int key);
		void print();

	private:

		HashEntry* entry_;		//Table I
		HashEntry* entry2_;	//Table II
		int size_;
		bool cycle_;
};
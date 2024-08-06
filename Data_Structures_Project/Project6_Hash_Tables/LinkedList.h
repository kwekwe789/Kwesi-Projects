//Linked List Class Declaration
//Honor Pledge:
//I pledge that I have neither given nor
//received any help on this assignment.
//wkissel, majames, sjhartman, kkyeifordjour

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "LinkedNode.h"
#include <iostream>

class LinkedList
{
	public:
		LinkedList();
		~LinkedList();
		bool isEmpty();
		int getLength();
		void insert(HashEntry element);
		void printList();
		LinkedNode * getHead();
		LinkedNode * getTail();
		void setHead(LinkedNode * node);
		void setTail(LinkedNode * node);

	private:
		LinkedNode * head_;
		LinkedNode * tail_;
};
#endif
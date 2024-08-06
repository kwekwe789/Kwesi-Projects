//Doubly Linked List Class Declaration
//Honor Pledge:
//I pledge that I have neither given nor
//received any help on this assignment.
//wkissel, majames, sjhartman, kkyeifordjour

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include "LinkedList.h"

class DoublyLinkedList : public LinkedList
{
	public:
		DoublyLinkedList();
		virtual ~DoublyLinkedList();
		virtual void printList();
		void insertLinkedNode(LinkedNode * node, HashEntry data);
		void insertAfterLinkedNode(LinkedNode * node, HashEntry data);
		void insertBeforeLinkedNode(LinkedNode * node, HashEntry data);
		void removeLinkedNode(int key);
		int find(int key);
		int findKey(int key);
};
#endif
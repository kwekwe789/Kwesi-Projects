// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// kkyeifordjour sbeers
#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include <iostream>
#include "linkedNode.h"
#include "linkedList.h"
class doublyLinkedList: public linkedList
{
    public:
    
        doublyLinkedList() ;
		virtual  ~doublyLinkedList();
        virtual void printDoubleList();
        void insertDoubleLinkedNode(linkedNode *node, int data);
        void insertAfterLinkedNode(linkedNode *node, int data);
        void insertBeforeLinkedNode(linkedNode *node, int data);

};
#endif

// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// kkyeifordjour sbeers
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include "linkedNode.h"
#include "Node.h"
class linkedList
{
    public:
        linkedList();
        ~linkedList();
        bool isEmpty();
        int getSize();
        void insert(int element);
        void insertLinkedNode(linkedNode *node, int element);
        void printList();

        linkedNode * getHead();
        linkedNode * getTail();
        void setHead(int data);
        void setTail(int data);

        bool findElement(int data);
        void remove(int data); //only works if data is unique
    private:
    //helper methods
    linkedNode * head_;
    linkedNode * tail_;
    int size_;
};
#endif

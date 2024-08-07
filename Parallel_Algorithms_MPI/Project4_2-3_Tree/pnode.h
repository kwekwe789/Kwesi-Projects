#include <iostream>
#ifndef PNODE_H
#define PNODE_H
class Node 
{
	public:
	Node * parent;
	int value[6];
	Node * child[6];
	
	Node(); // constructor
	int numChildren();
	void absorb(Node * newChild);
	void discard(Node * removeChild);
	 Node * getRoot(Node * groot);
	
};
#endif
//Linked Node Class Declaration
//Honor Pledge:
//I pledge that I have neither given nor
//received any help on this assignment.
//wkissel, majames, sjhartman, kkyeifordjour

#ifndef LINKEDNODE_H
#define LINKEDNODE_H
#include "Node.h"

class LinkedNode: public Node
{
	public:
		LinkedNode(HashEntry data, LinkedNode * nextLinkedNode, LinkedNode * prevLinkedNode);
		~LinkedNode();
		LinkedNode * getNextLinkedNode();
		LinkedNode * getPrevLinkedNode();
		void setNextLinkedNode(LinkedNode * nextLinkedNode);
		void setPrevLinkedNode(LinkedNode * prevLinkedNode);
		bool hasNextLinkedNode();
		bool hasPrevLinkedNode();
		
	private:
		LinkedNode * nextLinkedNode_;
		LinkedNode * prevLinkedNode_;
};
#endif
//Node Class Definition
//Honor Pledge:
//I pledge that I have neither given nor
//received any help on this assignment.
//wkissel, majames, sjhartman, kkyeifordjour

#include "Node.h"

Node::Node(int data)
{
	data_ = data;
}

Node::~Node()
{

}

int Node::getValue()
{
	return data_;
}

void Node::setValue(int data)
{
	data_ = data;
}
//Linked Node Class Definition
//Honor Pledge:
//I pledge that I have neither given nor
//received any help on this assignment.
//wkissel, majames, sjhartman, kkyeifordjour

#include "LinkedNode.h"

LinkedNode::LinkedNode(HashEntry data, LinkedNode * nextLinkedNode, LinkedNode * prevLinkedNode) : Node(data)
{
	nextLinkedNode_ = nextLinkedNode;
	prevLinkedNode_ = prevLinkedNode;
}
LinkedNode::~LinkedNode()
{
	if(nextLinkedNode_ != nullptr)
	{
		delete nextLinkedNode_;
	}
}
LinkedNode * LinkedNode::getNextLinkedNode()
{
	return nextLinkedNode_;
}
LinkedNode * LinkedNode::getPrevLinkedNode()
{
	return prevLinkedNode_;
}
void LinkedNode::setNextLinkedNode(LinkedNode * nextLinkedNode)
{
	nextLinkedNode_ = nextLinkedNode;
}
void LinkedNode::setPrevLinkedNode(LinkedNode * prevLinkedNode)
{
	prevLinkedNode_ = prevLinkedNode;
}
bool LinkedNode::hasNextLinkedNode()
{
	if(nextLinkedNode_) return true;
	return false;
}
bool LinkedNode::hasPrevLinkedNode()
{
	if(prevLinkedNode_) return true;
	return false;
}
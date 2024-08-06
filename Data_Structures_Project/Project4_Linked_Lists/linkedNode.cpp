// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// kkyeifordjour sbeers
#include "linkedNode.h"
linkedNode:: linkedNode(int data, linkedNode *nextLinkNode, linkedNode *prevLinkNode) : Node(data), nextLinkNode_(nextLinkNode), prevLinkNode_(prevLinkNode) //constructor
{
    
}
linkedNode:: ~linkedNode() //destructor 
{
    if(nextLinkNode_ != nullptr)
	{	
		delete nextLinkNode_;
	}
}
void linkedNode:: setNextLinkNode(linkedNode * nextLinkNode) //sets the given linked node as the next node in the list
{
  
    nextLinkNode_ = nextLinkNode;
    
}

linkedNode * linkedNode:: getNextLinkNode() 
{
    return nextLinkNode_ ; //returns next node 
}
bool linkedNode:: hasNextLinkNode() //checks the pointer of the linked node to see if its pointing to anything
{
    if(nextLinkNode_ != nullptr)
    {
        return true;
    }
    else
    { 
        return false;
    }
}
linkedNode * linkedNode:: getPrevLinkNode() //returns value of the previous node
{
    return prevLinkNode_;

}
void linkedNode:: setPrevLinkNode(linkedNode * prevLinkNode) //sets value of previous node
{
    prevLinkNode_ = prevLinkNode;
}
bool linkedNode:: hasPrevLinkNode() //checks to see if the node is pointing to anything before it
{
    if(prevLinkNode_ != nullptr)
    {
        return true;
    }
    else
    { 
        return false;
    }
}

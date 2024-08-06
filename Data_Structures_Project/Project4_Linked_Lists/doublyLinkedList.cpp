// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// kkyeifordjour sbeers
#include "doublyLinkedList.h"

doublyLinkedList:: doublyLinkedList(): linkedList() //constructor
{

}
doublyLinkedList:: ~doublyLinkedList() //destructor
{
	
}

void doublyLinkedList:: printDoubleList() //prints the list by traversal
{
    if(!isEmpty())
    {
        linkedNode *node = getHead();
        std:: cout << node->getValue() << "<-->";
        while(node->hasNextLinkNode())
        {
            node = (node->getNextLinkNode());
            std:: cout << node->getValue() << "<-->";
        }
    }

}
void doublyLinkedList:: insertDoubleLinkedNode(linkedNode *node, int data) //inserts a node using a function from the linkedNode
{
    insertLinkedNode(node, data);

}
void doublyLinkedList:: insertAfterLinkedNode(linkedNode *node, int data) //inserts a node after the given node
{
    linkedNode *newNode = new linkedNode(data,nullptr,nullptr);
    if(node != nullptr)
    {
        insertLinkedNode(node,data);
    }
    else
    {
        node->setNextLinkNode(newNode);
        newNode->setNextLinkNode(node->getNextLinkNode());
    }
}
void doublyLinkedList:: insertBeforeLinkedNode(linkedNode *node, int data) //inserts a node before the given node
{
    linkedNode *newNode = new linkedNode(data,nullptr,nullptr);
    newNode->setPrevLinkNode(node);
    if(node != nullptr)
    {
        insertLinkedNode(node,data);
    }
    else
    {
        node->setNextLinkNode(newNode);
        newNode->setNextLinkNode(node->getNextLinkNode());
    }
}

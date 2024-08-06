//Doubly Linked List Class Definition
//Honor Pledge:
//I pledge that I have neither given nor
//received any help on this assignment.
//wkissel, majames, sjhartman, kkyeifordjour

#include "DoublyLinkedList.h"

DoublyLinkedList::DoublyLinkedList()
{
	
}
DoublyLinkedList::~DoublyLinkedList()
{

}
void DoublyLinkedList::printList()
{
	LinkedNode * position = getHead();
	std::cout << position->getValue().getKey();;
	while(position->hasNextLinkedNode())
	{
		position = position->getNextLinkedNode();
		std::cout << "<-->" << position->getValue().getKey();
	}

}
//Insert at the head of the list
void DoublyLinkedList::insertLinkedNode(LinkedNode * node, HashEntry data)
{
	LinkedNode * elementNode = new LinkedNode(data, nullptr, nullptr);
	if(isEmpty()) //if its empty we set the head and tail
	{
		setHead(elementNode);
		setTail(elementNode);
	}
	else //if not we insert and repoint
	{
		getHead()->setPrevLinkedNode(elementNode);
		elementNode->setNextLinkedNode(getHead());
		elementNode->setPrevLinkedNode(nullptr);
		setHead(elementNode);
	}
	
}
//Insert after given node
void DoublyLinkedList::insertAfterLinkedNode(LinkedNode * node, HashEntry data)
{
	if(node == nullptr)
	{
		return;
	}
	LinkedNode * elementNode = new LinkedNode(data, nullptr, nullptr);
	elementNode->setNextLinkedNode(node->getNextLinkedNode());
	node->setNextLinkedNode(elementNode); //inserts the repoints based off if its the tail or not
	elementNode->setPrevLinkedNode(node);
	if(elementNode->getNextLinkedNode() != nullptr)
	{
		elementNode->getNextLinkedNode()->setPrevLinkedNode(elementNode);
	}
	else
	{
		setTail(elementNode);
	}
	
}
//Insert before given node
void DoublyLinkedList::insertBeforeLinkedNode(LinkedNode * node, HashEntry data)
{
	if(node == nullptr)
	{
		return;
	}
	LinkedNode * elementNode = new LinkedNode(data, nullptr, nullptr);
	elementNode->setPrevLinkedNode(node->getPrevLinkedNode());
	node->setPrevLinkedNode(elementNode); //inserts the repoints based off if its the head or not
	elementNode->setNextLinkedNode(node);
	if(elementNode->getPrevLinkedNode() != nullptr)
	{
		elementNode->getPrevLinkedNode()->setNextLinkedNode(elementNode);
	}
	else
	{
		setHead(elementNode);
	}
}

void DoublyLinkedList::removeLinkedNode(int key)
{
	//Key == head
	if (key == getHead()->getValue().getKey())
	{
		//Head is not tail, repoint
		if (getHead()->hasNextLinkedNode())
		{
			LinkedNode* currentHead = getHead();
			LinkedNode* nextNode = currentHead->getNextLinkedNode();
			setHead(nextNode);
			nextNode->setPrevLinkedNode(nullptr);
			currentHead->setNextLinkedNode(nullptr);
			delete currentHead;
		}
		//head is also tail
		else
		{
			LinkedNode* currentHead = getHead();
			setHead(nullptr);
			setTail(nullptr);
			delete currentHead;
		}
	}
	//Key == tail
	else if (key == getTail()->getValue().getKey())
	{
		if (getTail()->hasPrevLinkedNode())
		{
			LinkedNode* currentTail = getTail();
			LinkedNode* prevNode = currentTail->getPrevLinkedNode();
			setTail(prevNode);
			prevNode->setNextLinkedNode(nullptr);
			currentTail->setPrevLinkedNode(nullptr);
			delete currentTail;
		}
	}
	//Key == somewhere else
	else
	{
		LinkedNode* currentLinkedNode = getHead();
		bool isFound = false;
		while (currentLinkedNode->hasNextLinkedNode() && !isFound)
		{
			currentLinkedNode = currentLinkedNode->getNextLinkedNode();
			if (currentLinkedNode->getValue().getKey() == key)
			{
				isFound = true;
			}
		}
		if (isFound)
		{
			currentLinkedNode->getPrevLinkedNode()->setNextLinkedNode(currentLinkedNode->getNextLinkedNode());
			currentLinkedNode->getNextLinkedNode()->setPrevLinkedNode(currentLinkedNode->getPrevLinkedNode());
			currentLinkedNode->setNextLinkedNode(nullptr);
			currentLinkedNode->setPrevLinkedNode(nullptr);
			delete currentLinkedNode;
		}
		else
		{
			std::cout << "Key " << key << " not found!" << std::endl;
		}
	}
}

int DoublyLinkedList::find(int key) //traverses linked list
{
	LinkedNode* current = getHead();
	while (current != nullptr)
	{
		if (current->getValue().getKey() == key)
		{
			return current->getValue().getValue();
		}
		current = current->getNextLinkedNode();
	}
	return 0;
}

int DoublyLinkedList::findKey(int key) 
{
	LinkedNode* current = getHead();
	while (current != nullptr)
	{
		if (current->getValue().getKey() == key)
		{
			return key;
		}
		current = current->getNextLinkedNode();
	}
	return 0;
}
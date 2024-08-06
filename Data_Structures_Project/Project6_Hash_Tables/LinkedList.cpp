//Linked List Class Definition
//Honor Pledge:
//I pledge that I have neither given nor
//received any help on this assignment.
//wkissel, majames, sjhartman, kkyeifordjour

#include "LinkedList.h"

LinkedList::LinkedList()
{
	tail_ = nullptr;
	head_ = nullptr;
}
LinkedList::~LinkedList()
{
	if(head_ != nullptr)
	{
		delete head_;
	}
}
bool LinkedList::isEmpty()
{
	return (tail_ == nullptr && head_ == nullptr);
}
int LinkedList::getLength()
{
	int count = 0;
	LinkedNode * position = head_;
	while (position)
	{
		count++;
		position = position->getNextLinkedNode();
	}
	if (position)
	{
		delete position;
	}
	return count;
}
void LinkedList::insert(HashEntry element)
{
	LinkedNode * elementNode = new LinkedNode(element, nullptr, nullptr);
	if(isEmpty())
	{
		head_ = elementNode;
		tail_ = elementNode;
	}
	else
	{
		elementNode->setNextLinkedNode(head_);
		head_ = elementNode;
	}

}
void LinkedList::printList()
{
	LinkedNode * position = head_;
	std::cout << position->getValue().getKey();
	while(position->hasNextLinkedNode())
	{
		position = position->getNextLinkedNode();
		std::cout << "-->" << position->getValue().getKey();
	}
	std::cout << std::endl;
}
LinkedNode * LinkedList::getHead()
{
	return head_;
}
LinkedNode * LinkedList::getTail()
{
	return tail_;
}
void LinkedList::setHead(LinkedNode * node)
{
	head_ = node;
}
void LinkedList::setTail(LinkedNode * node)
{
	tail_ = node;
}
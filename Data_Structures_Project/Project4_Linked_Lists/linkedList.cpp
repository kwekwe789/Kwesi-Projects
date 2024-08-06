// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// kkyeifordjour sbeers
#include "linkedList.h"

linkedList:: linkedList(): head_(nullptr) , tail_(nullptr) //constructor
{
    
}
linkedList:: ~linkedList() //destructor
{
    if(head_ != nullptr)
    {
        delete head_;
    }
}
bool linkedList:: isEmpty() //check if the head pinter is null 
{
    if(head_ == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int linkedList:: getSize() //returns size
{
    return size_;
}
void linkedList:: insert(int element) //uses a seperate funtion to insert nodes
{
    insertLinkedNode(tail_,element);
}
void linkedList:: insertLinkedNode(linkedNode *node, int element) //checks to see what the node is and inserts it based off of that, can be the head tail or just part of the body
{
    std:: cout << "Inserting " << element << std::endl ;
    linkedNode *newNode = new linkedNode(element,nullptr,nullptr);
    if(!isEmpty())
    {
        if(node == tail_)
        {
            tail_ = newNode;
            node->setNextLinkNode(tail_); //if node is last in list, set new node to last and 
            
        }
        else if (node == head_)
        {
            head_ = newNode;
            head_->setNextLinkNode(node);
            
        }
        else
        {
            node->setNextLinkNode(newNode);
            newNode->setNextLinkNode(node->getNextLinkNode());
            
        }
      
    }
    else
    {
        head_ = newNode; //if its the first node it makes it the head and tail
        tail_ = newNode;
        std:: cout << "Element " << tail_->getValue() << " inserted"<< std:: endl;
    } 
    size_++;
}
void linkedList:: printList() //traverses the list and prints the elements
{
    if(!isEmpty())
    {
        linkedNode *node = head_;
        std:: cout << node->getValue() << "-->";
        while(node->hasNextLinkNode())
        {
            node = (node->getNextLinkNode());
            std:: cout << node->getValue() << "-->";
        }
    }
    //std:: cout << tail_->getValue();
    std:: cout << std:: endl;
}

linkedNode * linkedList:: getHead() //returns the head node
{
    return head_;
}
linkedNode * linkedList:: getTail() //returns the tail node
{
    return tail_;
}
void linkedList:: setHead(int data) //sets head node and make sure the pointers are null
{
    linkedNode *newNode = new linkedNode(data,nullptr,nullptr);
    head_ = newNode;
}
void linkedList:: setTail(int data)
{
    linkedNode *newNode = new linkedNode(data,nullptr,nullptr); //sets the tail node 
    tail_ = newNode;
}
bool linkedList:: findElement(int data) //traverses the list to see if the element is in the list
{
    bool found(false);
    int i(0);
    linkedNode *node = head_;
    while (found != true && i != size_)
    {
        if(node->getValue() == data)
        {
            found = true;
        }
        else
        {
            //node->setValue(node->getNextLinkNode());
        }
        i++;
    }
    return found;
}
void linkedList:: remove(int data)
{
    /* linkedNode * = node //find node!!
    linkedNode * prevNode= //find node before ^ that one
    if(node->hasNextNode())
    {
        prevNode->setNextNode(node->getNextNode());
    }
    else
    {
        tail_=prevNode;
    }*/

    size_--;
}

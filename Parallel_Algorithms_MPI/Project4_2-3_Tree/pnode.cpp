#include "pnode.h"


Node::Node()
{
	value[0] = 0;
	value[1] = 0;
	value[2] = 0;
	value[3] = 0;
	value[4] = 0;
	value[5] = 0;
	child[0] = nullptr;
	child[1] = nullptr;
	child[2] = nullptr;
	child[3] = nullptr;
	child[4] = nullptr;
	child[5] = nullptr;
	parent = nullptr;
}		// constructor
int Node::numChildren()
{
	int x(0);
	for(int i=0; i<6; i++)
	{
		if (child[i]!=nullptr)
		{
			x++;
		}
	}
	return x;
}
void Node::absorb(Node * newChild)
{
	Node * temp1 = new Node();
	Node * temp2 = new Node();
	Node * temp3 = new Node();
	Node * temp4 = new Node();
	if(parent==nullptr)
	{
		
		return;
	}
	else
	{
		if(newChild->numChildren()==0) //if a is a leaf
		{
			if(parent->numChildren()==2) // if b's parent has only 2 children
			{
				if(newChild->value[1]<parent->child[0]->value[1]) //if b is the left child move it to the middle and place a in the left
				{	
					newChild->parent=parent;
					temp1=parent->child[0];
					parent->child[0]=newChild;
					parent->child[1]=temp1;
					parent->value[0]=newChild->value[1];
					parent->value[1]=temp1->value[1];
				}
				else //if b is the right child place a in the middle
				{
					parent->child[1]=newChild;
					parent->value[1]=newChild->value[1];
					newChild->parent=parent;	
				}
			}
			else //if b's parent has 3 children
			{
				if(newChild->value[1]<parent->child[0]->value[1]) //if b is the left child move everything over and insert a in the left
				{
					newChild->parent=parent;
					temp1=parent->child[0];
					temp2=parent->child[1];
					temp3=parent->child[2];
					parent->child[0]=newChild;
					parent->child[1]=temp1;
					parent->child[2]=temp2;
					parent->child[3]=temp3;
					parent->value[0]=newChild->value[1];
					parent->value[1]=temp1->value[1];
					parent->value[2]=temp2->value[1];
					parent->value[3]=temp3->value[1];
				}
				else if(newChild->value[1]<parent->child[1]->value[1]) //if b is the middle child place a in the middle and move everything over
				{
					newChild->parent=parent;
					temp1=parent->child[1];
					temp2=parent->child[2];
					parent->child[1]=newChild;
					parent->child[2]=temp1;
					parent->child[3]=temp2;
					parent->value[1]=newChild->value[1];
					parent->value[2]=temp1->value[1];
					parent->value[3]=temp2->value[1];
				}
				else if(newChild->value[1]<parent->child[2]->value[1]) //if b is the right child place a on the right and move b over
				{
					newChild->parent=parent;
					temp1=parent->child[2];
					parent->child[2]=newChild;
					parent->child[3]=temp1;
					parent->value[2]=newChild->value[1];
					parent->value[3]=temp1->value[1];
				}
				Node * newNode = new Node(); //create the parent left node and take the two smallest values
				int value1(0),value2(0); 
				value1=parent->value[2];
				value2=parent->value[3];
				temp1=parent->child[2];
				temp2=parent->child[3];
				newNode->child[0]=parent->child[0];
				newNode->child[2]=parent->child[1];
				newNode->value[2]=parent->value[1];
				newNode->value[0]=parent->value[0];
				parent->child[0]=temp1;
				parent->child[2]=temp2;
				parent->value[0]=value1;
				parent->value[2]=value2;	
				parent->value[1]=0;
				parent->value[3]=0;
				parent->child[1]=nullptr;
				parent->child[3]=nullptr;
				parent->absorb(newNode); //absorb with parent and parent left
			}
		}
		else //if a is not a leaf node
		{
			if(parent->numChildren()==2) //if b's parent has 2 children insert a into the middle child
			{
				if(value[2]==parent->value[0])
				{
					temp1=parent->child[0];
					newChild->parent=parent;
					parent->child[0]=newChild;
					parent->value[0]=newChild->value[2];
					parent->child[1]=temp1;
					parent->value[1]=temp1->value[2];
				}
				else
				{
					newChild->parent=parent;
					parent->value[1]=newChild->value[2];
					parent->child[1]=newChild;
				}
			}
			else//if b's parent has 3 children 
			{
				if(parent->parent==nullptr) //if you are absorbing with the root
				{
					Node * newNode = new Node();
					Node * newRoot = new Node();
					if(value[2]==parent->value[0]) //determining where the placement of the nodes are
					{
						newNode->child[0]=newChild;
						newNode->child[2]=parent->child[0];
						newNode->value[0]=newChild->value[2];
						newNode->value[2]=parent->value[0];
						newChild->parent = newNode;
						parent->child[0]=parent->child[1];
						parent->value[0]=parent->child[1]->value[2];
						parent->child[1]=nullptr;
						parent->value[1]=0;						
						newNode->parent=newRoot;
						parent->parent=newRoot;
						newRoot->child[0]=newNode;
						newRoot->child[2]=parent;
						newRoot->value[0]=newNode->value[2];
						newRoot->value[2]=parent->value[2];
						
						
					}
					else if(value[2]==parent->value[1])
					{
						newNode->child[2]=newChild;
						newNode->child[0]=parent->child[0];
						newNode->value[2]=newChild->value[2];
						newNode->value[0]=parent->value[0];
						newChild->parent = newNode;
						parent->child[0]=parent->child[1];
						parent->value[0]=parent->child[1]->value[2];
						parent->child[1]=nullptr;
						parent->value[1]=0;
						newNode->parent=newRoot;
						parent->parent=newRoot;
						newRoot->child[0]=newNode;
						newRoot->child[2]=parent;
						newRoot->value[0]=newNode->value[2];
						newRoot->value[2]=parent->value[2];
						
					}
					else
					{
						newNode->child[0]=parent->child[0];
						newNode->child[2]=parent->child[2];
						newNode->value[0]=parent->child[0]->value[2];
						newNode->value[2]=parent->child[2]->value[2];
						newChild->parent = parent;
						parent->child[0]=newNode;
						parent->value[0]=newNode->value[2];
						parent->child[1]=nullptr;
						parent->value[1]=0;
						newNode->parent=newRoot;
						parent->parent=newRoot;
						newRoot->child[0]=newNode;
						newRoot->child[2]=parent;
						newRoot->value[0]=newNode->value[2];
						newRoot->value[2]=parent->value[2];
						
					}
				
				}
				else //determining where the placement of the nodes are
				{
					if(parent->value[0]==value[2])
					{
						Node * newNode = new Node();
						newNode->child[0]=newChild;
						newNode->child[2]=parent->child[0];
						newNode->value[0]=newChild->value[2];
						newNode->value[2]=parent->child[0]->value[2];
						parent->child[0]=parent->child[1];
						parent->value[0]=parent->child[1]->value[2];
						parent->child[1]=nullptr;
						parent->value[1]=0;
						newChild->parent=newNode;
						parent->absorb(newNode);
					}
					else if(parent->value[1]==value[2])
					{
						Node * newNode = new Node();
						newNode->child[0]=parent->child[0];
						newNode->value[0]=parent->value[0];
						newNode->child[2]=newChild;
						newNode->value[2]=newChild->value[2];
						parent->child[0]=parent->child[1];
						parent->value[0]=parent->child[1]->value[2];
						parent->child[1]=nullptr;
						parent->value[1]=0;
						newChild->parent=newNode;
						parent->absorb(newNode);
					}
					else
					{
						newChild->parent=parent;
						Node * newNode = new Node();
						newNode->child[0]=parent->child[0];
						newNode->child[2]=parent->child[1];
						newNode->value[0]=parent->value[0];
						newNode->value[2]=parent->value[1];
						parent->child[0]=newChild;
						parent->value[0]=newChild->value[2];
						parent->value[1]=0;
						parent->child[1]=nullptr;
						parent->absorb(newNode);
					}
				}
			}
		}
	}
}
//void Node::discard(Node * removeChild);
 Node * Node::getRoot(Node * groot) //display tree from root
 {
	if(groot->parent==nullptr)
	{
		//std::cout<<"root";
		return groot;
	}
	else
	{
		//std::cout<<"not" << std::endl;
		return getRoot(groot->parent);
	}
 }
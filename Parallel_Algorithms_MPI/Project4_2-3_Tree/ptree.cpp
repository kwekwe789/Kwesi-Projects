#include "ptree.h"

Tree::Tree()
{
	root = nullptr;
}

Node * Tree::search(int valToFind, Node * p)
{
	Node * nodeb = new Node();
	nodeb->value[1]=2000;
	if(p->child[0]->child[0]->numChildren() == 0)
	{
		if(p->numChildren() == 3)
		{
			if(valToFind <= p->child[0]->value[0])
			{
				return p->child[0]->child[0];
			}
			else if(valToFind <= p->child[0]->value[1])
			{
				return p->child[0]->child[1];
			}
			else if(valToFind <= p->child[0]->value[2])
			{
				return p->child[0]->child[2];
			}
			else if(valToFind <= p->child[1]->value[0])
			{
				return p->child[1]->child[0];
			}
			else if(valToFind <= p->child[1]->value[1])
			{
				return p->child[1]->child[1];
			}
			else if(valToFind <= p->child[1]->value[2])
			{
				return p->child[1]->child[2];
			}
			else if(valToFind <= p->child[2]->value[0])
			{
				return p->child[2]->child[0];
			}
			else if(valToFind <= p->child[2]->value[1])
			{
				return p->child[2]->child[1];
			}
			else if(valToFind <= p->child[2]->value[2])
			{
				return p->child[2]->child[2];
			}
			else
			{
				return nodeb;
			}
		}
		else
		{
			if(valToFind <= p->child[0]->value[0])
			{
				return p->child[0]->child[0];
			}
			else if(valToFind <= p->child[0]->value[1])
			{
				return p->child[0]->child[1];
			}
			else if(valToFind <= p->child[0]->value[2])
			{
				return p->child[0]->child[2];
			}
			else if(valToFind <= p->child[2]->value[0])
			{
				return p->child[2]->child[0];
			}
			else if(valToFind <= p->child[2]->value[1])
			{
				return p->child[2]->child[1];
			}
			else if(valToFind <= p->child[2]->value[2])
			{
				return p->child[2]->child[2];
			}
			else
			{
				return nodeb;
			}
		}
	}
	else
	{	
		if(valToFind <= p->value[0])
		{
			return search(valToFind,p->child[0]);
		}
		else if(valToFind <= p->value[1])
		{
			return search(valToFind,p->child[1]);
		}
		else if(valToFind <= p->value[2])
		{
			return search(valToFind,p->child[2]);
			
		}
		else 
		{
			return nodeb;
		}
	}
}
void Tree::insert(int valToAdd)
{
	Node * add = new Node();
	add->value[1]=valToAdd;
	Node * nodeab = new Node();
	search(valToAdd,root)->absorb(add);
	//root->getRoot(root);
}
/*	
bool delete(int valToKill);
void print();*/
void Tree::print(Node * p)
{
	if(p!= nullptr)
	{
		if(p->child[0]!= nullptr && p->value[0] != 0)
		{
			std::cout << p->value[0] << " " ;
		}
		if(p->child[0]!= nullptr && p->value[1] != 0)
		{
			std::cout << p->value[1] << " " ;
		}
		if(p->child[0]!= nullptr && p->value[2] != 0)
		{
			std::cout << p->value[2] << " " ;
		}
		if(p->child[0]!= nullptr && p->value[3] != 0)
		{
			std::cout << p->value[3] << " " ;
		}
		print(p->child[0]);
		print(p->child[1]);
		print(p->child[2]);
		print(p->child[3]);
	}
	else
	{
		return;
	}
}


void Tree::printRoot(Node * p)
{
	Node * newN = new Node();
	p=newN->getRoot(p);
	if(p!= nullptr)
	{
		if(p->child[0]!= nullptr && p->value[0] != 0)
		{
			std::cout << p->value[0] << " " ;
		}
		if(p->child[0]!= nullptr && p->value[1] != 0)
		{
			std::cout << p->value[1] << " " ;
		}
		if(p->child[0]!= nullptr && p->value[2] != 0)
		{
			std::cout << p->value[2] << " " ;
		}
		if(p->child[0]!= nullptr && p->value[3] != 0)
		{
			std::cout << p->value[3] << " " ;
		}
		print(p->child[0]);
		print(p->child[1]);
		print(p->child[2]);
		print(p->child[3]);
	}
	else
	{
		return;
	}
}




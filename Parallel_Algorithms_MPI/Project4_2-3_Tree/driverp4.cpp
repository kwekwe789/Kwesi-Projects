#include <iostream>
#include <fstream>
#include "pnode.h"
#include "ptree.h"
using namespace std;

int main()
{
	Tree * tree = new Tree();
	
	Node * nodea = new Node();
	Node * nodeb = new Node();
	Node * nodec = new Node();
	Node * noded = new Node();
	Node * nodee = new Node();
	Node * nodef = new Node();
	Node * nodeg = new Node();
	Node * nodeh = new Node();
	Node * nodei = new Node();
	Node * nodej = new Node();
	Node * nodek = new Node();
	Node * node1 = new Node();
	Node * node2 = new Node();
	Node * node3 = new Node();
	Node * node4 = new Node();
	Node * node5 = new Node();
	Node * node6 = new Node();
	Node * node7 = new Node();
	Node * node8 = new Node();
	Node * node9 = new Node();
	Node * node10 = new Node();
	Node * node11 = new Node();
	Node * node12 = new Node();
	Node * node13 = new Node();
	Node * node14 = new Node();
	Node * node15 = new Node();
	nodek->value[0]=17;
	nodek->value[1]=28;
	nodek->value[2]=2000;
	nodek->child[0]=nodeh;
	nodek->child[1]=nodei;
	nodek->child[2]=nodej;
	nodeh->value[0]=3;
	nodeh->value[1]=8;
	nodeh->value[2]=17;
	nodeh->child[0]=nodea;
	nodeh->child[1]=nodeb;
	nodeh->child[2]=nodec;
	nodei->value[0]=21;
	nodei->value[2]=28;
	//nodei->value[2]=30;
	nodei->child[0]=noded;
	//nodei->child[1]=nodei;
	nodei->child[2]=nodee;
	nodej->value[0]=33;
	nodej->value[2]=2000;
	//nodek->value[2]=30;
	nodej->child[0]=nodef;
	//nodek->child[1]=nodei;
	nodej->child[2]=nodeg;
	nodea->value[0]=1;
	//nodek->value[1]=28;
	nodea->value[2]=3;
	nodea->child[0]=node1;
	//nodek->child[1]=nodei;
	nodea->child[2]=node2;
	nodeb->value[0]=5;
	//nodek->value[1]=28;
	nodeb->value[2]=8;
	nodeb->child[0]=node3;
	//nodek->child[1]=nodei;
	nodeb->child[2]=node4;
	nodec->value[0]=11;
	nodec->value[1]=14;
	nodec->value[2]=17;
	nodec->child[0]=node5;
	nodec->child[1]=node6;
	nodec->child[2]=node7;
	noded->value[0]=19;
	//nodek->value[1]=28;
	noded->value[2]=21;
	noded->child[0]=node8;
	//nodek->child[1]=node9;
	noded->child[2]=node9;
	nodee->value[0]=24;
	//nodek->value[1]=28;
	nodee->value[2]=28;
	nodee->child[0]=node10;
	//nodek->child[1]=nodei;
	nodee->child[2]=node11;
	nodef->value[0]=31;
	//nodek->value[1]=28;
	nodef->value[2]=33;
	nodef->child[0]=node12;
	//nodek->child[1]=nodei;
	nodef->child[2]=node13;
	nodeg->value[0]=36;
	nodeg->value[2]=2000;
	//nodek->value[2]=30;
	nodeg->child[0]=node14;
	//nodek->child[1]=nodei;
	nodeg->child[2]=node15;
	node1->value[1]=1;
	node2->value[1]=3;
	node3->value[1]=5;
	node4->value[1]=8;
	node5->value[1]=11;
	node6->value[1]=14;
	node7->value[1]=17;
	node8->value[1]=19;
	node9->value[1]=21;
	node10->value[1]=24;
	node11->value[1]=28;
	node12->value[1]=31;
	node13->value[1]=33;
	node14->value[1]=36;
	node15->value[1]=2000;
	///cout << "node 1 has " << node1->numChildren() << "children" << endl;
	//cout << "nodeks children are " << nodek->child[0]->child[0]->child[0]->child[0]->value[1] ;
	nodea->parent=nodeh;
	nodeb->parent=nodeh;
	nodec->parent=nodeh;
	noded->parent=nodei;
	nodee->parent=nodei;
	nodef->parent=nodej;
	nodeg->parent=nodej;
	nodeh->parent=nodek;
	nodei->parent=nodek;
	nodej->parent=nodek;
	node1->parent=nodea;
	node2->parent=nodea;
	node3->parent=nodeb;
	node4->parent=nodeb;
	node5->parent=nodec;
	node6->parent=nodec;
	node7->parent=nodec;
	node8->parent=noded;
	node9->parent=noded;
	node10->parent=nodee;
	node11->parent=nodee;
	node12->parent=nodef;
	node13->parent=nodef;
	node14->parent=nodeg;
	node15->parent=nodeg;
	tree->root=nodek;
	//int val(0);
	//cout << "what value do you want to search for ";
	//cin>> val;
	//cout<<noded->numChildren()<<endl;
	//Node * ab = new Node();
	//ab->value[1]=6;
	//node4->absorb(ab);
	//cout<<nodeb->numChildren()<<endl;
	//tree->print(nodee);
	//cout <<endl;
	
	//Node * nodeab =tree->search(7,nodek);
	//cout << nodeab->value[0] <<endl;
	//cout << nodeh->child[0]->child[2]->value[1];
	//cout << nodek->child[2]->value[1];
	
	//cout<<noded->numChildren()<<endl;
	//tree->print(nodeh);
	
	//cout<<nodeh->numChildren()<<endl;
	//cout<<nodek->numChildren()<<endl;
	tree->insert(12);
	//tree->insert(25);
	//tree->insert(26);
	//tree->insert(18);
	//tree->insert(20);
	//tree->insert(27);
	//nodee->getRoot(nodek);
	//cout<<nodek->parent->numChildren();
	//cout<<nodek->parent->value[0];
	//tree->insert(22);
	//cout <<tree->search(22,nodek)->value[1];
	//cout <<tree->search(26,nodek)->value[1];
	//cout <<tree->search(27,nodek)->value[1];
	
	//tree->printRoot(nodek);
	//cout <<endl;
	//cout<<nodee->value[0]<<endl;
	tree->print(nodek);
	//cout <<endl;
	//cout<<nodei->numChildren()<<endl;
	return 0;
}
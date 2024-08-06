//Main driver for Color Me Dawgs
//Honor Pledge:
//I pledge that I have neither given nor
//received any help on this assignment.
//wkissel, majames, sjhartman, kkyeifordjour

#include <iostream>
#include <fstream>
#include <cmath>
#include "BinarySearchTree.h"
#include "RedBlackTree.h"

int main()
{
	int temp = 0;
	std::ifstream DataFile("data.txt");
	while (DataFile >> temp)
	{
		std::cout << temp << " ";
	}
	std::cout << std::endl;
	DataFile.close();
	
	std::cout << "Phase 2 Start" << std::endl;
	BinarySearchTree * bst = new BinarySearchTree();
	std::ifstream TreeFile("data.txt");
	int inserts = 0;
	while (TreeFile >> temp)
	{
		std::cout << temp << " ";
		bst->insert(temp);
		inserts++;
	}
	TreeFile.close();
	std::cout << std::endl;
	std::cout << "Root: " << bst->getRoot()->getData() << std::endl;
	std::cout << "Height: " << 1+log2(inserts) << std::endl;
	delete bst;

	std::cout << "Phase 3/4 Start" << std::endl;
	RedBlackTree * rbt = new RedBlackTree();
	std::ifstream TreeFile2("data.txt");
	inserts = 0;
	while (TreeFile2 >> temp)
	{
		std::cout << temp << " ";
		rbt->insert(temp);
		inserts++;
	}
	TreeFile2.close();
	std::cout << std::endl;
	std::cout << "Root: " << rbt->getRoot()->getData() << std::endl;
	std::cout << "Root color: " << rbt->getRoot()->getColor() << std::endl;
	std::cout << "Height: " << 1 + log2(inserts) << std::endl;
	delete rbt;
	
	std::cout << "Phase 5 Start" << std::endl;
	RedBlackTree * frbt = new RedBlackTree();
	std::ifstream TreeFileFinal("data.txt");
	inserts = 0;
	while (TreeFileFinal >> temp)
	{
		std::cout << temp << " ";
		frbt->insert(temp);
		inserts++;
	}
	TreeFileFinal.close();
	std::cout << std::endl;
	std::cout << "Red Nodes: ";
	frbt->printRedNodes(frbt->getRoot());
	std::cout << std::endl;
	std::cout << "Black Nodes: ";
	frbt->printBlackNodes(frbt->getRoot());
	std::cout << std::endl;
	std::cout << "Root: " << frbt->getRoot()->getData() << std::endl;
	delete frbt;
}

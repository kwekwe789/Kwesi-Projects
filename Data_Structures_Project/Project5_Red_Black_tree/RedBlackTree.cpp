//Honor Pledge:
//I pledge that I have neither given nor
//received any help on this assignment.
//wkissel, majames, sjhartman, kkyeifordjour
#include "RedBlackTree.h"

RedBlackTree::RedBlackTree() : BinarySearchTree()
{

}
RedBlackTree::~RedBlackTree()
{

}
void RedBlackTree::insert(int data)
{
	TreeNode* newNode = new TreeNode(data);
	setRoot(insertNode(getRoot(), newNode));
	TreeNode* root = getRoot();
	balanceColor(root, newNode);
}
void RedBlackTree::rotateRight(TreeNode *& root, TreeNode *& newNode)
{
	TreeNode* l = newNode->getLeftChild();
	newNode->setLeftChild(l->getRightChild());
	if (newNode->getLeftChild() != nullptr)
	{
		newNode->getLeftChild()->setParent(newNode);
	}
	l->setParent(newNode->getParent());
	if (newNode->getParent() == nullptr)
	{
		root = l;
		setRoot(l);
	}
	else if (newNode == newNode->getParent()->getRightChild())
	{
		newNode->getParent()->setRightChild(l);
	}
	else
	{
		newNode->getParent()->setLeftChild(l);
	}
	l->setRightChild(newNode);
	newNode->setParent(l);
}

void RedBlackTree::rotateLeft(TreeNode *& root, TreeNode *& newNode)
{
	TreeNode* r = newNode->getRightChild();
	newNode->setRightChild(r->getLeftChild());
	if (newNode->getRightChild() != nullptr)
	{
		newNode->getRightChild()->setParent(newNode);
	}
	r->setParent(newNode->getParent());
	if (newNode->getParent() == nullptr)
	{
		root = r;
		setRoot(r);
	}
	else if (newNode == newNode->getParent()->getLeftChild())
	{
			newNode->getParent()->setLeftChild(r);
	}
	else
	{
			newNode->getParent()->setRightChild(r);
	}
	r->setLeftChild(newNode);
	newNode->setParent(r);
}

void RedBlackTree::balanceColor(TreeNode*& root, TreeNode*& newNode)
{
	while (newNode != root && newNode->getParent()->getColor() == "red")
	{
		TreeNode* newParent = newNode->getParent();
		TreeNode* newGrandparent = newParent->getParent();
		if (newParent == newGrandparent->getLeftChild())
		{
			TreeNode* newAunt = newGrandparent->getRightChild();
			if (newAunt != nullptr && newAunt->getColor() == "red")
			{
				newParent->setColor("black");
				newAunt->setColor("black");
				newGrandparent->setColor("red");
				newNode = newGrandparent;
			}
			else
			{
				if (newNode == newParent->getRightChild())
				{
					rotateLeft(root, newParent);
					newNode = newParent;
					newParent = newNode->getParent();
				}

				else
				{
					rotateRight(root, newGrandparent);
					std::string temp = newParent->getColor();
					newParent->setColor(newGrandparent->getColor());
					newGrandparent->setColor(temp);
					newNode = newParent;
				}
			}
		}
		else
		{
			TreeNode* newAunt = newGrandparent->getLeftChild();
			if (newAunt != nullptr && newAunt->getColor() == "red")
			{
				newParent->setColor("black");
				newAunt->setColor("black");
				newGrandparent->setColor("red");
				newNode = newGrandparent;
			}
			else
			{
				if (newNode == newParent->getLeftChild())
				{
					rotateRight(root, newParent);
					newNode = newParent;
					newParent = newNode->getParent();
				}

				else
				{
					rotateLeft(root, newGrandparent);
					std::string temp = newParent->getColor();
					newParent->setColor(newGrandparent->getColor());
					newGrandparent->setColor(temp);
					newNode = newParent;
				}
			}
		}
	}
	root->setColor("black");
}
void RedBlackTree::printRedNodes(TreeNode * root)
{
	if (root == nullptr)
	{
		return;
	}
	
	printRedNodes(root->getLeftChild());
	if (root->getColor() == "red")
	{
		std::cout << root->getData() << " ";
	}
	printRedNodes(root->getRightChild());
}
void RedBlackTree::printBlackNodes(TreeNode * root)
{
	if (root == nullptr)
	{
		return;
	}
	if (root->getColor() == "black")
	{
	std::cout << root->getData() << " ";
	}
	printBlackNodes(root->getLeftChild());
	printBlackNodes(root->getRightChild());
}
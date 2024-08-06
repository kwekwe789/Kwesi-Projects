//BST Class Definition
//Honor Pledge:
//I pledge that I have neither given nor
//received any help on this assignment.
//wkissel, majames, sjhartman, kkyeifordjour
#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree()
{
	root_ = nullptr;
}


BinarySearchTree::~BinarySearchTree()
{
	if (root_ != nullptr)
	{
		delete root_;
	}
}

TreeNode * BinarySearchTree::getRoot()
{
	return root_;
}

void BinarySearchTree::setRoot(TreeNode * root)
{
	root_ = root;
}

void BinarySearchTree::insert(int data)
{
	TreeNode * newNode = new TreeNode(data);
	root_ = insertNode(root_, newNode);
}

TreeNode * BinarySearchTree::insertNode(TreeNode * root, TreeNode * node)
{
	// If the BST is empty - go ahead and make the node the root.
	if (root == nullptr)
	{
		return node;
	}
	else
	{
		// Determine which subtree to insert the node into...
		if (node->getData() < root->getData()) 
		{ 
			// Left Subtree
			root->setLeftChild(insertNode(root->getLeftChild(), node)); 
			root->getLeftChild()->setParent(root); 
		} 
		else 
		{ 
			// Right Subtree
			root->setRightChild(insertNode(root->getRightChild(), node)); 
			root->getRightChild()->setParent(root); 
		}
		
		return root;
	}	
}

void BinarySearchTree::inorder(TreeNode * root)
{
	if (root == nullptr)
	{
		return;
	}
	
	inorder(root->getLeftChild());
	
	std::cout << root->getData() << " ";
	
	inorder(root->getRightChild());
}

void BinarySearchTree::preorder(TreeNode * root)
{
	if (root == nullptr)
	{
		return;
	}
	
	std::cout << root->getData() << " ";
	
	preorder(root->getLeftChild());
	
	preorder(root->getRightChild());

}

void BinarySearchTree::postorder(TreeNode * root)
{
	if (root == nullptr)
	{
		return;
	}
	
	postorder(root->getLeftChild());
	
	postorder(root->getRightChild());

	std::cout << root->getData() << " ";	
}
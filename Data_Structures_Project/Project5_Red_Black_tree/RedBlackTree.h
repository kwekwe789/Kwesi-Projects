//Red Black Tree Class Declaration
//Honor Pledge:
//I pledge that I have neither given nor
//received any help on this assignment.
//wkissel, majames, sjhartman, kkyeifordjour

#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

#include "BinarySearchTree.h"
#include <string>

/*
* @class RedBlackTree
*/

class RedBlackTree : public BinarySearchTree
{
	public:
		RedBlackTree();
		virtual ~RedBlackTree();
		virtual void insert(int data);
		void printRedNodes(TreeNode * root);
		void printBlackNodes(TreeNode * root);
	private:
		void rotateLeft(TreeNode *& root, TreeNode *& newNode);
		void rotateRight(TreeNode *& root, TreeNode *& newNode);
		void balanceColor(TreeNode *& root, TreeNode *& newNode);
};

#endif
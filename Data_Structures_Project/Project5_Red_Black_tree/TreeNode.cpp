//Tree Node Class Definition
//Honor Pledge:
//I pledge that I have neither given nor
//received any help on this assignment.
//wkissel, majames, sjhartman, kkyeifordjour
#include "TreeNode.h"

TreeNode::TreeNode(int data)
{
	data_ = data;
	leftChild_ = nullptr;
	rightChild_ = nullptr;
	parent_ = nullptr;
	color_ = "red";
}

TreeNode::~TreeNode()
{
	// Recursive Delete
	if (leftChild_ != nullptr)
	{
		delete leftChild_;
	}
	
	if (rightChild_ != nullptr)
	{
		delete rightChild_;
	}
}

int TreeNode::getData()
{
	return data_;
}

TreeNode * TreeNode::getLeftChild()
{
	return leftChild_;
}

TreeNode * TreeNode::getRightChild()
{
	return rightChild_;
}

TreeNode * TreeNode::getParent()
{
	return parent_;
}

void TreeNode::setLeftChild(TreeNode * child)
{
	leftChild_ = child;
}

void TreeNode::setRightChild(TreeNode * child)
{
	rightChild_ = child;
}

void TreeNode::setParent(TreeNode * parent)
{
	parent_ = parent;
}
void TreeNode::setColor(std::string color)
{
	color_ = color;
}
std::string TreeNode::getColor()
{
	return color_;
}
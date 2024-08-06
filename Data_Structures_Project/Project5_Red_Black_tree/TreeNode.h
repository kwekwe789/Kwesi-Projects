//Tree Node Class Declaration
//Honor Pledge:
//I pledge that I have neither given nor
//received any help on this assignment.
//wkissel, majames, sjhartman, kkyeifordjour

#ifndef TREENODE_H
#define TREENODE_H
#include "Node.h"
#include <string>
/**
 * @class TreeNode
 *
 * A class that simulates a Node in a Binary Search Tree.
 */
class TreeNode : public Node
{
	public:
		/**
	     * Constructor
	     *
	     * @param[in]	   data		int
	    */	
		TreeNode(int data);
		
		/// Destructor
		~TreeNode();
		
		/// Accessor Methods
		
		/**
	     * Returns the data stored in the tree node.
		 *
	     * @return          int
	    */ 
		int getData();
		
		/**
	     * Returns a pointer to the left child of the given node.
		 *
	     * @return          TreeNode *
	    */ 		
		TreeNode * getLeftChild();
		
		/**
	     * Returns a pointer to the right child of the given node.
		 *
	     * @return          TreeNode *
	    */ 
		TreeNode * getRightChild();
		
		/**
	     * Returns a pointer to the parent of the given node.
		 *
	     * @return          TreeNode *
	    */ 
		TreeNode * getParent();

		/**
		 * Returns the color of the given node.
		 *
		 * @return	   std::string
		*/
		std::string getColor();
		
		/**
	     * Sets the left child of the given node.
	     *
		 * @param[in]	   TreeNode*	leftChild
	    */ 
		void setLeftChild(TreeNode * leftChild);
		
		/**
	     * Sets the right child of the given node.
	     *
		 * @param[in]	   TreeNode*	rightChild
	    */
		void setRightChild(TreeNode * rightChild);
		
		/**
	     * Sets the parent of the given node.
	     *
		 * @param[in]	   TreeNode*	parent
	    */
		void setParent(TreeNode * parent);
		/**
		 * Sets the color of the given node.
		 *
		 * @param[in]	   std::string	color
		*/
		void setColor(std::string color);

	private:
		int data_; 				// Data (int) of the given node
		TreeNode * leftChild_;	// Left child node of the given node
		TreeNode * rightChild_;	// Right child node of the given node
		TreeNode * parent_;		// Parent node of the given node
		std::string color_; //Color of the node
	protected:
		/// Protected Constructor
		TreeNode() {}
};

#endif
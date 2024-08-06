// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// kkyeifordjour sbeers
#ifndef LINKEDNODE_H
#define LINKEDNODE_H
#include "Node.h"
class linkedNode : public Node
{
    public:
        linkedNode(int data, linkedNode *nextLinkNode, linkedNode *prevLinkNode);
        virtual ~linkedNode();
        void setNextLinkNode(linkedNode * nextLinkNode);
        linkedNode * getNextLinkNode();
        bool hasNextLinkNode();
        linkedNode * getPrevLinkNode();
        void setPrevLinkNode(linkedNode * prevLinkNode);
        bool hasPrevLinkNode();

    private:
        linkedNode * nextLinkNode_;
        linkedNode * prevLinkNode_;
};
#endif

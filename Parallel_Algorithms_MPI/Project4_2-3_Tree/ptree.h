#include <iostream>
#include "pnode.h"
#ifndef PTREE_H
#define PTREE_H
 class Tree 
 {
 public:
 Node * root;
 //void print(Node * start);


 Tree(); // constructor
 Node * search(int valToFind, Node * p);
 void insert(int valToAdd);
 //bool delete(int valToKill);
 void print(Node * p);
  void printRoot(Node * p);

 };
 #endif
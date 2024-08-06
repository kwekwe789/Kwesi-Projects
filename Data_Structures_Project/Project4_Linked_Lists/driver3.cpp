// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// kkyeifordjour sbeers
#include "Node.h"
#include "linkedNode.h"
#include "linkedList.h"
#include "doublyLinkedList.h"
#include <iostream>
#include <fstream>

int main()
{
    //Phase 1
    Node node(4); //creates nodes and sets their value
    std:: cout << "Node Value: " << node.getValue() << std:: endl;
    node.setValue(2);
    std:: cout << "Node Value: " << node.getValue() << std:: endl;
    
    //Phase 2
    linkedList List;
    int data;
    std:: ifstream inFile; //declares infile reader
    std :: ofstream outFile;
    inFile.open("data.txt"); 
    if(inFile.is_open()) //reading in the file and storing the data in the list 
    {
        while(!inFile.eof())
        {
            inFile >> data ;
            List.insert(data);
        }
    }
    inFile.close();
    List.printList();
    std:: cout << "Length of list is: "<< List.getSize() << std:: endl; //print list

    //Phase 3

    //Phase 4
    doublyLinkedList * DoubleList = new doublyLinkedList(); //creates list 
    int elements;
    inFile.open("sorted.txt");
    if(inFile.is_open()) //opens up and reads in the file
    {
        int x = 0;
        while(!inFile.eof())
        {
            if(x==0)
            {
                inFile >> elements ;
                DoubleList->setHead(elements);
                x = 1;
            }
            else
            {
                inFile >> elements ;
                DoubleList->insertAfterLinkedNode(DoubleList->getHead(),elements);
            }
        }
    }
    inFile.close();
    DoubleList.printDoubleList(); //prints out the list 

    //DoubleList.printDoubleList();
    //List.insert(3);
    //List.insert(7);
    //List.insert(9);
    //List.printList();
	//delete List;
	delete DoubleList;

    return 0;
};

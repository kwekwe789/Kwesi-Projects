// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// kkyeifordjour sbeers
#include "bitarray.h"
#include "dictionary.h"
#include "set.h"
#include <fstream>
#include <ostream>
int main()
{
	//Phase I
	BitArray Bit(5), Bit2(5);
	char word[] = "Hello";
	char k[] = "Facts";
	Bit.initialize(word,5);
	Bit2.initialize(k,5);
	std::cout << "Number of bits: " << Bit.length() << std::endl;
	Bit.print();
	if (Bit.get(13) == true)
	{
		std::cout << "The 13th bit is set\n";
	}
	else
	{
		std::cout << "The 13th bit is not set\n";
	}
	
	//Phase II
	std:: cout << "Setting bit 2 to 1... "<< std:: endl;
	Bit.set(2);
	Bit.print();
	std:: cout << "Setting bit 6 to 0... "<< std:: endl;
	Bit.set(6,0);
	Bit.print();
	std:: cout << "Flipping bit 16... "<< std:: endl;
	Bit.flip(16);
	Bit.print();
	std:: cout << "Taking complement ..." << std:: endl;
	Bit.complement();
	Bit.print();
	std:: cout << "Clear bit array: "<< std:: endl;
	Bit.clear();
	Bit.print();
	
	//Phase III
	Set Set1(5), Set2(5);
	Set1.initialize(word,5);
	Set2.initialize(k,5);
	std::cout << "Set A is: \n";
	(Set1.getData()).print();
	std::cout << "Set B is: \n";
	(Set2.getData()).print();
	std::cout << "The cardinality of Set A is: "<< Set1.getCardinality() << std::endl;
	Set1.setUnion(Set2);
	Set1.setIntersection(Set2);
	
	//Phase IV
	Dictionary Dict1;
	Dict1.initialize(word,5);
	std::cout << "Rank: " << Dict1.rank(26, 1) << std::endl;
	std::cout << "Rank Range (15-31): " << Dict1.rank_range(15, 31, 1) << std::endl;
	std::cout << "Select (5,1): " << Dict1.select(5, 1) << std::endl;
	std::cout << "Select Range (0, 15, 2, 1): " << Dict1.select_range(0, 15, 2, 1) << std::endl;
	
	//Phase V
	
	std::cout<<"Printing Lookup Table...\n";
	Dict1.printLookupTable();

}
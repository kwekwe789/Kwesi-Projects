// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// kkyeifordjour sbeers
#include "set.h"
#include "bitarray.h"

Set::Set(int size):data_(BitArray(size)) //constructor
{
    
}
Set::~Set()
{
    
}

void Set::initialize(char * word, int size) //destructor
{
    data_.initialize(word, size);
}

BitArray & Set:: getData() //returns the data of the given set
{
    return data_;
}

bool Set::setUnion(Set & B)  //finds bits that are in either one
{
    if(data_.length() == B.data_.length())
    {
        unsigned char x;
		unsigned char z;
        for(int i=0 ; i < (data_.length()/8) ; i++)
        {
            x = data_.get8(i* BIT_IN_BYTE) | B.data_.get8(i*BIT_IN_BYTE); //or's data and second data togethe
            data_.set8(x,i); // sets data to union found above
        }
		std::cout<< "The union of set A and B is: \n";
		data_.print();
		return true;
    }
    else
    {
        return false;
    }
}

bool Set::setIntersection(Set & B) //finds bits that are in both
{
    if(data_.length() == B.data_.length())
    {
        unsigned char y = ' ';
        for(int i=0 ; i < data_.length() ; i++)
        {
            y = data_.get8(i* BIT_IN_BYTE) & B.data_.get8(i*BIT_IN_BYTE); // and's data and second data
            data_.set8(y,i); // sets data to intersection found above
        }
		std::cout<< "The intersection of set A and B is: \n";
		data_.print();
		return true;
    }
    else
    {
        return false;
    }

}

int Set::getCardinality() const //counts number of set bits
{
    int counter = 0;
    for(int i=0; i < data_.length(); i++)
    {
		if(data_.get(i) == true)
        {
            counter = counter + 1;
        }
    }
	return counter;
}
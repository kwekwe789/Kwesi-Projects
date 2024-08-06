// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// kkyeifordjour sbeers
#include "bitarray.h"
#include <iostream>
//
//void print()
//

BitArray::BitArray(int size) //Constructor
{
	data_ = new char[BYTES];
	BYTES = size;
	LENGTH = BYTES * BIT_IN_BYTE;
} 
BitArray:: BitArray(const BitArray & array) : LENGTH(array.LENGTH) , BYTES(array.BYTES), data_(nullptr)//copy constructor
{
    data_ = new char[LENGTH/BYTES];
    for(int i=0; i< LENGTH/BYTES ; i++)
    {
        data_[i] = array.data_[i];
    }
}
BitArray:: ~BitArray() //destructor
{
	delete [] data_;
}
 
bool BitArray:: get(int position) const
{
    int bitPos = position/BIT_IN_BYTE; //right shift the array by the modulus of 8 and the given position then and that with 1, if it equals 1 then its set
    int k = (position%BIT_IN_BYTE ) ;

    if (((data_[bitPos] >> k) & 1) !=0 )
    {
		return true;
    }
    else
    {
		return false;
    }
} 

void BitArray:: print() //given
{
    std::cout << "|";
    for (int i=0; i < BYTES; i++)
    {
        std:: bitset<BIT_IN_BYTE> bits = data_[i];
        std:: cout << bits << "|";
    }
	std::cout<<"\n";
}

void BitArray:: initialize(char * word, int size) //sets the bits of the array based on the given characters
{   

   for (int i=0; i < size; i++)
   {
        data_[i]= word[i]; 
   }
}

bool BitArray:: flip(int position) 
{
    if(position < LENGTH)
    {
        int bitPos = position/BIT_IN_BYTE;
        int k = position%BIT_IN_BYTE ;

        data_[bitPos] = data_[bitPos] ^ (128 >> k);  // exclusive-or's data byte with byte 10000000 rshifted by k
        
        return true;
    }
    else
	{
        return false ;
    }
}
bool BitArray:: set(int position, int bit)
{
    if(position < LENGTH)
    {
        int bitPos = position/BIT_IN_BYTE;
        int k = position%BIT_IN_BYTE ;
		if(bit == 1)
		{
			data_[bitPos] = data_[bitPos] | (1 << k);  // or's data byte with byte 10000000 rshifted by k
		}
		else
		{
			data_[bitPos] = data_[bitPos] ^ (1 << k);
		}
        
        return true;
    }
    else{
        return false ;
    }

}
char BitArray:: get8(int position) const
{
    return data_[position/BIT_IN_BYTE]; //gets byte that position is in
    
} 
void BitArray:: set8(char c, int index)
{
    data_[index] = c ;

}
void BitArray:: complement()
{
    for (int i=0; i < BYTES ; i++)
    {
        data_[i] = data_[i] ^ 255;     // one's complement's each byte in data_ array
    }
}
void BitArray:: clear()
{
    for (int i=0; i < BYTES; i++) //resets all bits to zero
    {
        data_[i] = 0;
    }
} 

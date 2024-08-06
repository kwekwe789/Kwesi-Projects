// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// kkyeifordjour sbeers
#include "dictionary.h"
#include "bitarray.h"
#include "set.h"
Dictionary:: Dictionary() : lookupTable_(new int [256]) //Constructor
{
	char c[1];
	Set s(1);
    for (int i=0; i< 256 ; i++)
    {
        c[0] = i;
        s.initialize(c,1);
        lookupTable_[i] = s.getCardinality();
    }
}
Dictionary::Dictionary (const Dictionary & dict) : lookupTable_(nullptr) //Copy COnstructor 
{
	lookupTable_ = new int(DICTIONARY_SIZE);
	for(int i=0; i < DICTIONARY_SIZE; i++)
	{
		lookupTable_[i] = dict.lookupTable_[i];
	}
}

Dictionary:: ~Dictionary()
{
	delete [] lookupTable_;
}
void Dictionary:: initialize(char * word, int size) //initializes the dictionary
{
    data_.initialize(word, size);
}

/*int Dictionary::search(BitArray k)
{
	char m[1];
	Set l(1);
	int c(0);
	for(int i=0; i<256; i++)
	{
		m[0] = i;
        l.initialize(m,1);
		if(k == l.getData())
		{
			c= l.getCardinality;
		}
	}*/

int Dictionary:: rank(int end, int bit) 
{
	int counter = 0;
    for(int i = end; i != 0 ; i-- ) //goes to the position given and counts how many of the bits match the given bit. Stops counting when it reaches 0
    {
		if (bit == 1)
		{	
			if(data_.get(i) == true)
			{
				counter = counter + 1;
			}
		}
		else 
		{
			if(data_.get(i) == false)
			{
				counter = counter + 1;
			}
		}
	}
    return counter;	
}
int Dictionary:: rank_range(int start, int end, int bit) //Similar to the rank above except it goes to the entered number and counts until it 
{															//reaches the other entered number
	int counter = 0;
    for(int i = end; i > start-1 ; i-- )
    {
		if (bit == 1)
		{	
			if(data_.get(i) == true)
			{
				counter = counter + 1;
			}
		}
		else 
		{
			if(data_.get(i) == false)
			{
				counter = counter + 1;
			}
		}
	}
    return counter;
}
int Dictionary:: select(int k, int bit) //Creates a counter that counts how many times the desired bit was found. Once it reaches the given number it returns
{										//it was found at. To prevent it from being infitite, it breaks once it reaches the legnth of the array
	int i, x, y;
	x = 0;
	i = 0;
	
	while(i!= k )
	{
		if (bit == 1)
		{	
			if(data_.get(x) == true)
			{
				i++;
			}
		}
		else 
		{
			if(data_.get(x) == false)
			{
				i++;
			}
		}
		x++;
		if( x == data_.length())
		{
			break;
		}
	}
	x--;

	return x;
}
int Dictionary:: select_range(int start, int end, int k, int bit) //searchs for the number of bits that match the given bit within the given range.
{																
	int i, x, y;
	x = start;
	i = 0;
	for(y = end; x < y; x++)
	{
		if (bit == 1)
		{	
			if(data_.get(x) == true)
			{
				i++;
			}
		}
		else 
		{
			if(data_.get(x) == false)
			{
				i++;
			}
		}
		if( i ==k )
		{
			break;
		}
	}
	return x;
}

void Dictionary:: printLookupTable() //Creates tables by iterating through the values and writing them to a textfile
{
	std::ofstream output;
	output.open("table.txt");
	output << "Printing Lookup Table "<< std:: endl;
    char k[1];
	BitArray l(1);
	for(int i=0 ; i < 256 ; i++)
    {
        k[0] = i;
        l.initialize(k,1);
		l.get8(i*8);
		output << "Lookup Table";
		for (int i=0; i < 1; i++)
		{
        std:: bitset<BIT_IN_BYTE> bits = l.get8(i*8);
        output << "[" << bits << "]";
		}
		output << " ";
		output << "Lookup Table[" << i << "]: " << lookupTable_[i] <<std:: endl; 
    }	
}


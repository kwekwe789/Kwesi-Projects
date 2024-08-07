#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
using namespace std;

void mergesort (int * a, int first, int last);
void merge(int * a, int * b, int lasta, int lastb, int * output );


int main()
{
	int num(0);
	cout << "How many numbers would you like in your array? ";
	cin >> num;
    int * arr = new int[num];
	int * answer = new int[num];
	
	for (int x = 0; x < num; x++) //random number generator
	{
		arr[x] = rand() % 1000000;	
	}
	for (int x = 0; x < num; x++) //fill array with numbers
	{
		cout << arr[x] << " ";	
	}		
	
	mergesort(arr,0,(num-1)); //mergesort call
	cout << endl;
	
	for (int x = 0; x < num; x++) //print out sorted array
	{
		cout << arr[x] << " ";	
	}
	return 0;
}	




void mergesort (int * a, int first, int last)
{
	int median = (first + last)/2; //find median
	if(first < last) //recursively call merge and mergesort
	{
		mergesort(a,first,median);
		mergesort(a,median+1,last);
		merge(a,a,median,last,answer);	
	}	
	merge(a,a,median,last,answer);
}

void merge(int * a, int * b, int lasta, int lastb, int * output) 
{
	int size1=lasta+1; //size of array a and b used to compare 2 numbers
	int size2=lastb-lasta;
	int arr1[size1];
	int arr2[size2];
	for(int i=0;i<(size1);i++)  //fills array with numbers
	{
		arr1[i] = a[i];
	}
	for(int i=0;i<(size2);i++)
	{
		arr2[i] = a[lasta+1+i];
	}
	int placea(0),placeb(0),placec(0);
	
	while(placea < size1 && placeb < size2) //comparisons
	{
		if(arr1[placea] < arr2[placeb])		
		{	
			a[placec] =  arr1[placea];
			placea++;
			placec++;
		}
		else
		{
			a[placec] = arr2[placeb];
			placeb++;
			placec++;
		}
	}
	
	while(placea<size1)
	{
		a[placec]=arr1[placea];
		placea++;
		placec++;
	}
	while(placeb<size2)
	{
		a[placec]=arr2[placeb];
		placeb++;
		placec++;
	}
}
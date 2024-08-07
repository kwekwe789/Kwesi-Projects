//CS452 Project 3
//wkissel & kkyeifordjour


#include <iostream>
#include <stdio.h>
#include <string.h>
#include <ctime>
#include <math.h>
#include <iomanip>
#include <fstream>
#include "mpi.h" // message passing interface
//using namespace std;

// New compile and run commands for MPI!
// mpicxx -o blah file.cpp
// mpirun -q -np 32 blah   //32 = processer number 

void smerge(int * a, int * b, int lasta, int lastb, int * output);
void mergesort (int * a, int first, int last);
int rank(int * a, int first, int last, int valToFind);
void pmerge(int * a, int * b, int lasta, int lastb, int * output);

int my_rank;			// my CPU number for this process
int p;					// number of CPUs that we have

int main (int argc, char * argv[]) {
    
    int source;				// rank of the sender
	int dest;				// rank of destination
	int tag = 0;			// message number
    MPI_Status status;		// return status for receive

    // Start MPI
    MPI_Init(&argc, &argv);

    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &p);
	
	//Initializing array
	int n(128);
    int * array = new int[n];
	//initialize random number generator to time
	//5500
	srand(5530);
   
    if (my_rank == 0) 
	{
        for (int x = 0; x < n; x++) 
		{
            array[x] = rand() % 500;
            std::cout << array[x] << " ";
        }
        std::cout << std::endl;  
    }
	//Sending array to all processors
    MPI_Bcast(&array[0], n, MPI_INT, 0, MPI_COMM_WORLD);
    mergesort(array, 0, n);
    if (my_rank == 0) 
	{
        for (int x = 0; x < n; x++)
		{
            std::cout << array[x] << "  ";
		}
		std::cout << std::endl;
	}
	

	// Shut down MPI
	MPI_Finalize();

	return 0;
}

void smerge(int * a, int * b, int lasta, int lastb, int * output = NULL) 
{
    int i = 0, j = 0, k = 0;

    while (i < lasta && j < lastb) {
        if (a[i] < b[j])
            output[k++] = a[i++];
        else
            output[k++] = b[j++];
    }
    
    for (int z = i; z < lasta; z++)
        output[k++] = a[z];
    
    for (int z = j; z < lastb; z++)
        output[k++] = b[z];
    
}


void mergesort(int * a, int first, int last) 
{
    if (last < 2)
	{
        return;
    }
    if (last == 2) 
	{
        if (a[0] > a[1]) 
		{
            int temp = a[0];
            a[0] = a[1];
            a[1] = temp;
        }
        return;
    }
	int median = last/2;
    int * rarray = &a[median];
    mergesort(a, first, median);
    mergesort(rarray, first, last-median);
    int * temp = new int[last];
    for (int x = 0; x < last; x++)
	{      
		temp[x] = 0;
	}
    pmerge(a, rarray, median, last-median, temp);

    for (int x = 0; x < last; x++) 
	{
        a[x] = temp[x];
    }
    delete[] temp;
}

int rank(int * a, int first, int last, int valToFind)
{
	if (last == 1) 
	{
        if (valToFind <= a[first])
		{
            return 0;
        }
        else
		{
			return 1;
		}
    }
	else 
	{
        int half = last/2;
        int*right = &a[half];
        if (valToFind < a[half]) 
		{
            return rank(a, first, half, valToFind);
        }
        else 
		{
            return half+rank(right, first, last-half, valToFind);
        }
    }
}

void pmerge(int * a, int * b, int lasta, int lastb, int * output = NULL) 
{
    int x = floor(lasta/log2(lasta));
    int y = floor(lastb/log2(lastb));
    int * shaper = new int[x];
	int * totalrankA = new int[x];
	int * totalrankB = new int[y];
    int selectA[x];
	int selectB[y];
    int * srankA = new int[x];
	int * srankB = new int[y];
	int * endA = new int[x * 2 + 1];
    int * endB = new int[y * 2 + 1];
    int * temp = new int[lasta + lastb];
	for (int i = 0; i < lasta + lastb; i++)
	{
		temp[i] = 0;
	}
	
    for (int i = 0; i < x; i++) 
	{
        selectA[i] = a[i * x];
        srankA[i] = 0;
        totalrankA[i] = 0;
        shaper[i] = i * x;
    }

    for (int i = my_rank; i < x; i += p)
	{
        srankA[i] = rank(b, 0, lastb, selectA[i]);
	}
    
    for (int i = 0; i < y; i++) 
	{
        selectB[i] = b[i * y];
        srankB[i] = 0;
        totalrankB[i] = 0;
    }

    for (int i = my_rank; i < y; i += p)
	{
        srankB[i] = rank(a, 0, lasta, selectB[i]);
	}

    MPI_Allreduce(&srankA[0], &totalrankA[0], x, MPI_INT, MPI_SUM, MPI_COMM_WORLD);
    MPI_Allreduce(&srankB[0], &totalrankB[0], y, MPI_INT, MPI_SUM, MPI_COMM_WORLD);

    smerge(shaper, totalrankB, x, y, endA);
    smerge(shaper, totalrankA, x, y, endB);

    endA[x * 2] = lasta;
    endB[y * 2] = lastb;
    
    for (int i = my_rank; i < x * 2; i += p) 
	{
        smerge(&a[endA[i]], &b[endB[i]], endA[i + 1] - endA[i], endB[i + 1] - endB[i], &temp[endA[i] + endB[i]]);
    }
	
    MPI_Allreduce(&temp[0], &output[0], lasta + lastb, MPI_INT, MPI_MAX, MPI_COMM_WORLD);
    
	delete[] shaper;
	delete[] srankA;
    delete[] srankB;
    delete[] totalrankA;
    delete[] totalrankB;
    delete[] endA;
    delete[] endB;

}
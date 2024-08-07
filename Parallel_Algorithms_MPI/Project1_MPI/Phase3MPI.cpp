#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mpi.h" // message passing interface
using namespace std;

// New compile and run commands for MPI!
// mpicxx -o blah file.cpp
// mpirun -q -np 32 blah

int main (int argc, char * argv[]) {

	int my_rank;			// my CPU number for this process
	int p;					// number of CPUs that we have
	int source;				// rank of the sender
	int dest;				// rank of destination
	int tag = 0;			// message number
	char message[100];		// message itself
	MPI_Status status;		// return status for receive
	
	// Start MPI
	MPI_Init(&argc, &argv);
	
	// Find out my rank!
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
	
	// Find out the number of processes!
	MPI_Comm_size(MPI_COMM_WORLD, &p);
	
	// THE REAL PROGRAM IS HERE
    //cout << my_rank << endl;
	srand(71911); //seeding and variable declaration
	int n = 300000;
	int * a = new int[n];
	int range(11);
	int supermax(0);
	long int sum(0);
	long int supersum(0);
	int min(11);
	int supermin(0);
	int localn = n/p;
	int check(n % p);
	int ex(0);
	if (my_rank == 0) //fills an array with random numbers from zero to 10
	{
		for (int x = 0; x < n; x++)
		{
			a[x] = rand() % range;	
		}	
	}

	int * locala = new int[localn];
	MPI_Scatter(&a[0], localn, MPI_INT, locala, localn, MPI_INT, 0, MPI_COMM_WORLD); //scatters the array to all processors
	int max(0);
	for (int x = 0; x < localn; x++) //local work of summing all the values, finding the local max and local min
	{
		sum += locala[x];
		if(locala[x] > max)
		{
			max = locala[x];
		}
		if(locala[x] < min)
		{
			min = locala[x];
		}
	}
	
	MPI_Reduce(&max, &supermax, 1, MPI_INT, MPI_MAX, 0, MPI_COMM_WORLD); //reducing to find the overall max
	MPI_Reduce(&min, &supermin, 1, MPI_INT, MPI_MIN, 0, MPI_COMM_WORLD); //reducing to find the overall min
	MPI_Reduce(&sum, &supersum, 1, MPI_LONG, MPI_SUM, 0, MPI_COMM_WORLD); //reducing to find the overall sum
	
	if(my_rank == 0 )
	{	
		if(check != 0) //checks to see if there were any numbers not included in the initial scatter and checks for the min max and adds the numbers to the total sum
		{
			for(int x (0); x < n%p; x++)
			{
				ex =  (localn * p) + x;
				if(a[ex]>supermax)
				{
					supermax = a[ex];
				}
				if(a[ex]<supermin)
				{
					supermin = a[ex];
				}
				supersum += a[ex];
			}
		}
		cout << "The maximum number is " << supermax << endl; //prints out the results.
		cout << "The minumun number is " << supermin << endl;
		cout << "The average is " << (supersum/n) << endl;
	}
	MPI_Finalize();

	return 0;
}
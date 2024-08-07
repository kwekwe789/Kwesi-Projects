#include <iostream>
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
	
	int check; //variable declaration
	int place(0);
	int place1(1);
	int ring1 = 1;
	int ring2 = 2;
	check = p % 2;
	int counter = p/2;
	int num = p-2;
	if(check == 0) //does this if statment if the number of processors is even
	{	
		if(my_rank % 2 == 0) // of the rank is even it does the ring1 relay
		{
			if (my_rank != p-2) //if not the last positon of the relay pass to the number 2 ahead
			{
				MPI_Send(&ring1, 1, MPI_INT, my_rank + 2, tag, MPI_COMM_WORLD);
				cout <<my_rank << " Sending message to " << my_rank+2 << "..." << endl;
			}
			else //if the last position pass to 0
			{
				MPI_Send(&ring1, 1, MPI_INT, 0, tag, MPI_COMM_WORLD);
				cout <<my_rank << " Sending message to " <<  0 << "..." << endl;
			}
		}
		else //if the rank is odd it does the ring 2 relay
		{
			if(my_rank != 1) //if not the first position pass to the position 2 less than you
			{
				MPI_Send(&my_rank, 1, MPI_INT, my_rank-2, tag, MPI_COMM_WORLD);
				cout <<my_rank << " Sending message to " << my_rank-2 << "..." << endl;		
			}
			else //if the first position pass to the last position
			{
				MPI_Send(&my_rank, 1, MPI_INT, p-1, tag, MPI_COMM_WORLD);
				cout <<my_rank << " Sending message to " << p-1 << "..." << endl;
			}
		}
	}
	else //if p is odd
	{
		if(my_rank % 2 == 0) // of the rank is even it does the ring1 relay
		{
			if (my_rank != p-1) //if not the last positon of the relay pass to the number 2 ahead
			{
				MPI_Send(&ring1, 1, MPI_INT, my_rank + 2, tag, MPI_COMM_WORLD);
				cout <<my_rank << " Sending message to " << my_rank+2 << "..." << endl;
			}
			else //if the last position pass to 0
			{
				MPI_Send(&ring1, 1, MPI_INT, 0, tag, MPI_COMM_WORLD);
				cout <<my_rank << " Sending message to " <<  0 << "..." << endl;
			}
		}
		else //if the rank is odd it does the ring 2 relay
		{
			if(my_rank != 1) //if not the first position pass to the position 2 less than you
			{
					MPI_Send(&ring2, 1, MPI_INT, my_rank-2, tag, MPI_COMM_WORLD);
					cout <<my_rank << " Sending message to " << my_rank-2 << "..." << endl;
			}
			else
			{
				MPI_Send(&ring2, 1, MPI_INT, p-2, tag, MPI_COMM_WORLD); //if the first position pass to the last position
				cout <<my_rank << " Sending message to " << p-2 << "..." << endl;
			}
		}
	}
	if(check == 0) //does this if statment if the number of processors is even for recieving
	{
		if(my_rank % 2 == 0) // of the rank is even it does the ring1 relay	
		{
			if (my_rank == 0) //if the rank is 0 receive from the last position
			{
				MPI_Recv(&ring1, 1, MPI_INT, num, tag, MPI_COMM_WORLD, &status);
				cout <<my_rank << " Recieving message from " << num << "..." << endl;
			}
			else //if not recieve from 2 positions below you
			{
				MPI_Recv(&ring1, 1, MPI_INT, my_rank - 2, tag, MPI_COMM_WORLD, &status);
				cout <<my_rank << " Recieving message from " << my_rank-2 << "..." << endl;
				
			}
		}
		else //if the rank is odd it does the ring 2 relay
		{
			if(my_rank == (p-1)) //if the rank is in the last position recieve from 1
			{
				MPI_Recv(&ring2, 1, MPI_INT, 1, tag, MPI_COMM_WORLD, &status);
				cout <<my_rank << " Recieving message from " << 1 << "..." << endl;
			}
			else //if not receive from 2 ahead of you
			{
				MPI_Recv(&ring2, 1, MPI_INT, my_rank + 2, tag, MPI_COMM_WORLD, &status);
				cout <<my_rank << " Recieving message from " << my_rank+2 << "..." << endl;
			}
		}
		
	}
	else //does this if statment if the number of processors is odd for recieving
	{
		if(my_rank % 2 == 0)	// of the rank is even it does the ring1 relay	
		{
			if (my_rank == 0) //if the rank is 0 receive from the last position
			{
				MPI_Recv(&ring1, 1, MPI_INT, p-1, tag, MPI_COMM_WORLD, &status);
				cout <<my_rank << " Recieving message from " << p-1 << "..." << endl;
			}
			else //if not recieve from 2 positions below you
			{
				MPI_Recv(&ring1, 1, MPI_INT, my_rank - 2, tag, MPI_COMM_WORLD, &status);
				cout <<my_rank << " Recieving message from " << my_rank-2 << "..." << endl;
				
			}
		}
		else //if the rank is odd it does the ring 2 relay
		{
			if(my_rank == (p-2))  //if the rank is in the last position recieve from 1
			{
				MPI_Recv(&ring2, 1, MPI_INT, 1, tag, MPI_COMM_WORLD, &status);
				cout <<my_rank << " Recieving message from " << 1 << "..." << endl;
			}
			else
			{
				MPI_Recv(&ring2, 1, MPI_INT, my_rank + 2, tag, MPI_COMM_WORLD, &status); //if not receive from 2 ahead of you
				cout <<my_rank << " Recieving message from " << my_rank+2 << "..." << endl;
			}
		}
	}		
	
	MPI_Finalize();

	return 0;
}
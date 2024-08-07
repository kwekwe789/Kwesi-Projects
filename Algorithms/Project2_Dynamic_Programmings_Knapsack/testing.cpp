#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "item.h"
#include <string>
#include <cmath>

int knap(int i, int w, Item itemsarr[], int ** p3arr, Item sol[], int totw, int totp, int num); 

int main()
{
	std::string name(""); //function declaration
	int num_items(0), capacity(0), weight(0),pesos(0), Track(0), totweight(0), totprof(0),phase(0);
	int prof1(0), prof2(0);
	std::ifstream inputFile("test.txt"); //opens text file and reads in information
	inputFile >> num_items >> capacity;
	Item items[num_items];
	Item solution[num_items+3];	
	for (int i=0; i<num_items; i++) //reads in a text file and sets item values
	{
		inputFile >>name>> pesos >> weight;
		items[i].setName(name);
		items[i].setPesos(pesos);
		items[i].setWeight(weight);
	}
	inputFile.close();
	int sol(0);		//variable creation for ints and arrays
	int array(0);
	int totW(capacity);
	array = (num_items+1)*(capacity+1);
	int S[array];
	int t[array];
	int k(0);
	int count(0);
	for(int i(0); i <= num_items -1; i++) //calculate the number of computations
	{
		if(pow(2,i)> capacity)
		{
			count = count + capacity;
		}
		else 
		{
			count = count + pow(2,i);
		}
	}
	int ** matrix = new int * [num_items + 1];  //creation of the matrix and setting all the values to 0
    for (int i = 0; i < num_items + 1; i++)
	{    
		matrix[i] = new int [capacity + 1];
	}
	for (int j(0); j < num_items+1; j++)
	{
		for( int k(0); k < capacity+1; k++)
		{
			matrix[j][k] = 0;
		}
	}
    knap(num_items, capacity, items, matrix, solution, totweight, totprof, sol); //calling knapsack
	sol = matrix[0][0];
	std::cout<< "There are " << sol << " items in the solution" << std::endl; //prints out the results of the comparisons with the items that did fit
	if(sol > 0)
	{
		std::cout<< std::endl;
		std::cout<< "The total profit of items in the solution is " << matrix[1][0] << std::endl; 
		std::cout<< std::endl;
		std::cout<< "The total weight of items in the solution is " << matrix[0][1] << std::endl; 
		std::cout<< std::endl;
		std::cout<< "Items in the solution: \n";
		for(int i=0; i<sol; i++)
		{
			std::cout<< "Item " << i+1 << " name: " << solution[i].getName() << ", Item " << i+1 << " pesos: " << solution[i].getPesos() << ", Item " << i+1 << " weight: " << solution[i].getWeight() << std::endl;
		}
	}
	else
	{
	
	}
	std::cout<< std::endl;
	std::cout<< "There were " << count << " computations" << std::endl; 
	std::cout<< std::endl;
	/*for(int i=0; i<capacity+1; i++)
	{
		S[i] = 0;
		t[i] = 0;
	}
	
	for(int i=capacity+1; i<array; i = i+capacity+1)
	{
		S[i] = 0;
		t[i] = 0;
	}

	std::cout << "\n";
	
	
	for(int i=1; i<num_items+1; i++)
	{
		for(int j=1; j<capacity+1; j++)
		{
			Track = i * (capacity+1);
			Track = Track + j;
			prof1 = (i-1) * (capacity+1);
			prof1 = prof1 + j;
			if(items[i-1].getWeight() <= j)
			{
				int ind(0);
				ind = j - items[i-1].getWeight();
				prof2 = (i-1) * (capacity+1);
				prof2 = prof2 + ind;
				if(S[prof1] < (items[i-1].getPesos() + S[prof2]))
				{
					S[Track] = items[i-1].getPesos() + S[prof2];
					t[Track] = 1;
				}
				else
				{
					S[Track] = S[prof1];
					t[Track] = 0;
				}
				
			}
			else
			{
				S[Track] = S[prof1];
				t[Track] = 0;
			}
		}
	}	
	
	sol = 0;
	int check(0),total(capacity),m(num_items);
	check = (num_items+1)*(capacity+1) -1;
	for(int i = num_items; i >= 1; i--)
	{
		if(t[check] == 1)
		{
			total = total - items[i-1].getWeight();
			solution[sol].setItem(items[i-1]);
			totweight = totweight + solution[sol].getWeight();
			totprof =  totprof + solution[sol].getPesos();
			sol++;
			m--;
			check = m * (capacity+1) + total;
		}
		else
		{
			m--;
			check = m * (capacity+1) + total;
		}
		
	}
	std::cout<< "There are " << sol << " items in the solution" << std::endl; //prints out the results of the comparisons with the items that did fit
	if(sol > 0)
	{
		std::cout<< std::endl;
		std::cout<< "The total profit of items in the solution is " << totprof << std::endl; 
		std::cout<< std::endl;
		std::cout<< "The total weight of items in the solution is " << totweight << std::endl; 
		std::cout<< std::endl;
		std::cout<< "Items in the solution: \n";
		for(int i=0; i<sol; i++)
		{
			std::cout<< "Item " << i+1 << " name: " << solution[i].getName() << ", Item " << i+1 << " pesos: " << solution[i].getPesos() << ", Item " << i+1 << " weight: " << solution[i].getWeight() << std::endl;
		}
	}
	else
	{
	
	}*/
	return 0;	
}

int knap(int i, int w, Item itemsarr[], int ** p3arr, Item sol[], int totw, int totp, int num)
{
	int count(0);
	if(i == 0 || w <= 0) //check if the wanted value is out of bounds
	{
		return 0;
	}
	if(p3arr[i][w]>0)
	{
		return p3arr[i][w];
	}
	int pi = itemsarr[i-1].getPesos();  //gets the value of pesos and weight of the selected item
	int wi = itemsarr[i-1].getWeight();
	int x = i-1;
	if(wi > w)
	{
		p3arr[i][w] = knap(x,w,itemsarr,p3arr, sol, totw, totp, num); //if the weight of the selected item is greater than the capacity choose the profit of the previous computation
		return knap(x,w,itemsarr,p3arr, sol, totw, totp, num);
	}
	else
	{
		if(knap(x,w,itemsarr,p3arr, sol, totw, totp, num)> (knap(x, (w-wi), itemsarr, p3arr, sol, totw, totp, num) + pi)) //if the profit of the previous compuation is greater than the profit of the computed profit choose the previous profit, if not choose the newest computed profit
		{
			
			p3arr[i][w] = knap(x,w,itemsarr,p3arr, sol, totw, totp, num);
			return knap(x,w,itemsarr,p3arr, sol, totw, totp, num);
		}
		else
		{
			
			p3arr[i][w] =	knap(x, (w-wi), itemsarr, p3arr, sol, totw, totp, num) + pi;
			sol[num].setItem(itemsarr[i-1]);
			totw = totw + itemsarr[i-1].getWeight();
			totp = totp + itemsarr[i-1].getPesos();
			num=num+1;
			p3arr[0][0]=num;
			p3arr[0][1]=totw;
			p3arr[1][0]=totp;
			return (knap(x, (w-wi), itemsarr, p3arr, sol, totw, totp, num) + pi);
		}
	}	
}
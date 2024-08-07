#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "item.h"
#include <string>
#include "pq.h"

int num_items(0);
int upperBound(0);
int capacity(0);
int totprofit(0);
int totweight(0);

bool promising(int index, int totprofit, int totweight, Item * items, bool * included, bool * best);
void knapsack(int index, int totprofit, int totweight, Item * items, bool * included, bool * best);

int main()
{
	std::string name(""); //function declaration
	int solitems(0), solpes(0), solw(0);
	double pesos(0), weight(0), ratio(0);
	std::ifstream inputFile("test.txt"); //opens text file and reads in information
	inputFile >> num_items >> capacity;
	Item items;
	Item * knap = new Item[num_items+1];
	bool * included = new bool[num_items];
	bool * best = new bool[num_items];
	pq<Item> que; 					//ceates priority que for items
	for (int i=0; i<num_items; i++) //reads in a text file and enqueues the read in items
	{
		inputFile >>name>> pesos >> weight;
		items.setName(name);
		items.setPesos(pesos);
		items.setWeight(weight);
		ratio = pesos/weight;
		items.setRatio(ratio);
		que.enqueue(items);
	}
	inputFile.close(); 
	
	for(int x(1); x <num_items; x++)
	{
		items = que.dequeue();
		knap[x].setName(items.getName());
		knap[x].setWeight(items.getWeight());
		knap[x].setPesos(items.getPesos());
		knap[x].setRatio(items.getRatio());
	}
	
	knapsack(0,0,0,knap,included,best);
	
    std::cout <<"\nItems in the solution: "<<std::endl;
	std::cout<< std::endl;
    
    for(int x = 0; x < num_items; x++)
    {
        if(best[x]==true)
        {
           solw = solw + knap[x+1].getWeight();
           solpes = solpes + knap[x+1].getPesos();
           solitems++;
		   std::cout<< "Item " << solitems << " name: " << knap[x+1].getName() << " Item " << solitems << " pesos: " << knap[x+1].getPesos() << " Item " << solitems << " weight: " << knap[x+1].getWeight() << std::endl;
        }
		
    }
	std::cout<< std::endl;
   
    std::cout<< "There are " << solitems << " items in the solution" << std::endl;
	std::cout<< std::endl;
    std::cout<< "The total profit of items in the solution is " << solpes<< " pesos" << std::endl;
	std::cout<< std::endl;
    std::cout<< "The total weight of items in the solution is " << solw << " lbs" << std::endl; 
	
	return 0;
	
}



bool promising(int index, int totprofit, int totweight, Item * items, bool * included, bool * best)
{
	int j(0), k(0);
    int maxWeight(0);
    float bound(0);

    if (totweight >= capacity)
    {
        return false;
    }
    else
    {
        j = index+1;
        bound = totprofit;
        maxWeight = totweight;

        while ((j <= num_items) && ((maxWeight + items[j].getWeight()) <= capacity)) 
        {
            maxWeight = items[j].getWeight() + maxWeight;
            bound = bound + items[j].getPesos();
            j++;
        }
        k = j;

        if (k <= num_items)
        {
            bound = bound + (capacity - maxWeight)*(items[k].getRatio());
        }
        if(bound > upperBound)
		{
			return true;
		}
		else
		{
			return false;
		}
		 
   }
	
}


void knapsack(int index, int totprofit, int totweight, Item * items, bool * included, bool * best)
{
	if (totweight <= capacity && totprofit > upperBound)
    {
        upperBound = totprofit;
        for (int x(0); x <= num_items; x++)
        {
            best[x] = included[x];
        }
    }

    if (promising(index, totprofit, totweight, items, included, best))
    {
        included[index] = true;
        knapsack(index+1, totprofit + items[index+1].getPesos(), totweight + items[index+1].getWeight(), items, included, best);
        included[index] = false;
        knapsack (index+1, totprofit, totweight, items, included, best);
    }
}
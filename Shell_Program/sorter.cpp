#include "sorter.h"


Sorter::Sorter()
{
	in = false;
	first_ = false;
	done_ = false;
	pass_ = 0;
	stride_ = 0;
	tt =0.0;
	wt=0.0;
	rt=0.0;
}

void Sorter::initial(int id, int arrival)
{
	id_=id;
	arrival_=arrival;
}

void Sorter::initialer(int id,int arrival, int burst)
{
	id_=id;
	burst_=burst;
	arrival_=arrival;
	remainingB_=burst;
}

#ifndef SORTER_H
#define SORTER_H

class Sorter
{
  public:
	int id_;
    int arrival_;
	int burst_;
	int remainingB_;
	double tt;
	double wt;
	double rt;
	bool first_;
	int pass_;
	int stride_;
	bool done_;
	bool in;
    Sorter();
	void initial(int id,int arrival);
	void initialer(int id,int arrival,int burst);
};


#endif
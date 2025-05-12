#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <iostream>
#include <vector>
#include "process.h"
#include "sorter.h"
#include "queue.h"

class Scheduler
{
  private:

  public:
    Scheduler(const std::vector<Process>&process_List);
    void stats();  // print stats
    void schedule();  // run all policies
    void fifo();
	void sjf();// also SJF with sorted inputs
    void stride();
    void round_robin();
    void random_robin();
	int n_;
	std::vector<Process> process_List;
	double avgResponse;
	double avgTurnaround;
	double avgWait;
	int time;  
};

#endif
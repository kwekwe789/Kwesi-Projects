#ifndef PROCESS_H
#define PROCESS_H

class Process
{
  public:
	int id_;
    int arrival_;
    int burst_;
    int wt; // wait time
    int rt; // response time
    int tt; // turnaround time

    Process();
    Process(int id, int arrival, int burst);
};


#endif

#include "scheduler.h"

Scheduler::Scheduler(const std::vector<Process>&process_List) : process_List(process_List)//constructor
{
  avgResponse = 0.0;
  avgTurnaround = 0.0;
  avgWait = 0.0;
  time = 0;  
	
};


void Scheduler::stats() //prints the stats
{
	std::cout << "Average Turnaround Time: " << avgTurnaround << std::endl;
    std::cout << "Average Response Time: " <<  avgResponse << std::endl;
    std::cout << "Average Wait Time: " << avgWait << std::endl;
	std::cout << " " << std::endl;
	avgResponse = 0.0;
	avgTurnaround = 0.0;
	avgWait = 0.0;
	time = 0;
};

void Scheduler::schedule() //runs the policies
{
    std::cout << "scheduler running" << std::endl;
    fifo();
	sjf();
    round_robin();
    stride();
    random_robin();
};

void Scheduler::fifo()
{
    int n_ = process_List.size();
	Sorter a[n_];
	for(int x(0); x<n_; x++) //creates array of objects to be sorted
	{
		a[x].initialer(process_List[x].id_,process_List[x].arrival_,process_List[x].burst_);
	}
	for(int i=0; i<n_; i++) //sorts objects by arrival 
    {
        for(int j=i+1; j<n_; j++) 
		{
			if(a[i].arrival_>a[j].arrival_)
            {
                Sorter temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
	for(int x(0); x<n_; x++)
	{
		if(x==0) //runs the first process
		{
			a[x].tt=a[x].burst_;
			time = a[x].arrival_ + a[x].burst_; 
			avgTurnaround = a[x].tt + avgTurnaround;	
			
		}
		else
		{

			if(a[x].arrival_ <time) //if the process has arrived run it
			{
				a[x].wt=time-a[x].arrival_;
				a[x].rt=time-a[x].arrival_;
				time = time + a[x].burst_; 
				a[x].tt=time-a[x].arrival_;	
				avgTurnaround = a[x].tt + avgTurnaround;		
				avgResponse = a[x].rt + avgResponse;	
				avgWait = a[x].wt + avgWait;						
			}
			else //if not wait until it arrives and run it
			{
				a[x].wt=0;
				a[x].rt=0;
				time = a[x].arrival_ + a[x].burst_; 
				a[x].tt=a[x].burst_;
				avgTurnaround =a[x].tt + avgTurnaround;										
			}
		}
	}
	avgResponse = avgResponse/n_;
	avgTurnaround = avgTurnaround/n_;
	avgWait = avgWait/n_;	
    stats();
};

void Scheduler::sjf()
{
	int n_ = process_List.size();
	int check(0);
	Sorter b[n_];
	int done(0);
	for(int x(0); x<n_; x++) //create an array of objects to be sorted
	{
		b[x].initialer(process_List[x].id_,process_List[x].arrival_,process_List[x].burst_);
	}
	for(int i=0; i<n_; i++) //sort by burst first
    {
       
		for(int j=i+1; j<n_; j++) { if(b[i].burst_>b[j].burst_)
            {
                Sorter temp1 = b[i];
                b[i] = b[j];
                b[j] = temp1;
            }
        }
    }	
	Sorter a[n_];
	//std::cout << n_;
	for(int x(0); x<n_; x++) //create anotherr array to be 
	{
		a[x].initial(process_List[x].id_,process_List[x].arrival_);
	}
	for(int i=0; i<n_; i++)
    {
        for(int j=i+1; j<n_; j++) { if(a[i].arrival_>a[j].arrival_)
            {
                Sorter temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
	int max = a[n_-1].arrival_;
	for(int i(0); i<n_; i++) //checking id of a with list
	{
		if(a[0].id_==process_List[i].id_) 
		{
			for(int j(0); j<n_; j++)
			{
				if(b[j].id_ == a[0].id_)
				{
					b[j].id_ = 0;
				}
			}
			process_List[i].wt=0;
			process_List[i].rt=0;
			process_List[i].tt=process_List[i].burst_-process_List[i].arrival_;
			time = process_List[i].arrival_ + process_List[i].burst_; 
			avgTurnaround = process_List[i].tt + avgTurnaround;	
		}
	}
	while(done<(n_-1))
	{
		for(int i(0); i<n_; i++) 
		{
			
			if(b[i].arrival_ <= time && b[i].id_ !=0) //run job if its arrived
			{
				time = time + b[i].burst_;
				for(int k(0); k<n_; k++)
				{
					if (b[i].id_ == process_List[k].id_)
					{
						process_List[k].tt=time-process_List[k].arrival_;
						process_List[k].wt=(time-b[i].burst_)-process_List[k].arrival_;
						process_List[k].rt=process_List[k].wt;
						avgTurnaround = process_List[k].tt + avgTurnaround;		
						avgResponse = process_List[k].rt + avgResponse;	
						avgWait = process_List[k].wt + avgWait;
					}
				}
				b[i].id_ =0;
				check=1;
				done++;
				break;				
			}
			else
			{
				check =0;
			}	
		}
		if(check == 0)
		{
		time++;
		}
		
	}
	avgResponse = avgResponse/n_;
	avgTurnaround = avgTurnaround/n_;
	avgWait = avgWait/n_;
    stats();
};	

void Scheduler::stride() 
{
	int n_ = process_List.size();
	int stride_numerator =100;
	int tick=0;	
	Sorter a[n_];
	int done = 0;
	for(int x(0); x<n_; x++)
	{
		a[x].initialer(process_List[x].id_,process_List[x].arrival_,process_List[x].burst_); //determine stride
		a[x].stride_ = (stride_numerator/a[x].burst_);
	}
	for(int i=0; i<n_; i++) //sort by arrival
    {
        for(int j=i+1; j<n_; j++) 
		{
			if(a[i].arrival_>a[j].arrival_)
            {
                Sorter temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
	while(done<n_)
	{
		int selected = 0;
        for (int i=1; i<n_; i++) //determine the process with the lowest pass
        {
            if ( a[i].pass_ < a[selected].pass_ && a[i].done_==false && a[i].arrival_<=tick)
            {    
				selected = i;
				
				
			}
		}
		if(a[selected].first_ == false)
		{
			a[selected].first_ = true;
			a[selected].rt = tick - a[selected].arrival_;
			avgResponse = avgResponse + a[selected].rt;
		}
		
		a[selected].pass_= a[selected].pass_ + a[selected].stride_; //update pass and ticks
		tick = tick + a[selected].stride_;
		if(a[selected].pass_ >= a[selected].burst_ )
		{
			a[selected].done_ = true;
			a[selected].tt= tick - a[selected].arrival_;
			avgTurnaround = avgTurnaround + a[selected].tt;
			done++;
			
		}
		for(int x(0); x<n_; x++)
		{
			if(a[x].arrival_ < tick && a[x].done_ != true && x!=selected)
			{
				a[x].wt = a[x].wt + a[selected].stride_;
				avgWait = avgWait +  a[x].wt;
			}
		}		
	}
	avgResponse = avgResponse/n_;
	avgTurnaround = avgTurnaround/n_;
	avgWait = avgWait/n_;
	stats();
};
void Scheduler::round_robin() 
{
	int n_ = process_List.size();
	int round(1);
	int quantum(2);
	int count(0);
	int temp(0);
	int burst(0);
	int done(0);
	time=0;
	Queue q(n_);
	Sorter a[n_];
	for(int x(0); x<n_; x++)
	{
		a[x].initialer(process_List[x].id_,process_List[x].arrival_,process_List[x].burst_);
	}
	for(int i=0; i<n_; i++)
    {
        for(int j=i+1; j<n_; j++) { if(a[i].arrival_>a[j].arrival_) //sort by arrival
            {
                Sorter temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
	while(done<n_)
	{
		for(int i(0); i<n_; i++)
		{
			if(a[i].arrival_<=(time+2) && a[i].burst_>0 && a[i].in == false) //enqueue processes that have arrived
			{
				q.enQueue(a[i].id_);
				a[i].in = true;
				count++;		
			}
		}
		
		if(count>0)
		{
			temp = q.deQueue(); //dequeue first process
			for(int x(0); x<n_; x++)
			{
				if(temp==a[x].id_)
				{
					if(a[x].first_==false)
					{
						a[x].first_=true;
						a[x].rt = time - a[x].arrival_; 
					}
					
					burst=a[x].burst_;
					a[x].burst_ = a[x].burst_ - quantum;
					if(a[x].burst_==0) //check if process is done if it is determine the time
					{
						time =time +quantum;
						a[x].tt=time-a[x].arrival_;
						for(int m(0); m<n_; m++)
						{
							if(a[m].id_ != temp && a[m].in==true && a[m].burst_ >0)
							{
								a[m].wt = a[m].wt + quantum;
							}
						}
						done++;
					}
					else if(a[x].burst_<0)
					{
						time =time +burst;
						a[x].tt=time-a[x].arrival_;
						for(int m(0); m<n_; m++)
						{
							if(a[m].id_ != temp && a[m].in==true && a[m].burst_ >0)
							{
								a[m].wt = a[m].wt + burst;
							}
						}						
						done++;
					}
					else
					{
						q.enQueue(temp);
						time = time + quantum;
						for(int m(0); m<n_; m++)
						{
							if(a[m].id_ != temp && a[m].in==true && a[m].burst_ >0)
							{
								a[m].wt = a[m].wt + quantum;
							}
						}
					}
					break;
				}
			}
		}
	}
	for(int i(0); i<n_; i++)
	{
		avgResponse = avgResponse + a[i].rt;
        avgTurnaround = avgTurnaround + a[i].tt;
        avgWait = avgWait +  a[i].wt;
	}
	avgResponse = avgResponse/n_;
	avgTurnaround = avgTurnaround/n_;
	avgWait = avgWait/n_;	
	stats();
};
void Scheduler::random_robin() 
{
	srand(static_cast<unsigned>(std::time(0)));
    int random(0);
    int n_ = process_List.size();
	Sorter a[n_];
	
	for(int x(0); x<n_; x++)
	{
		a[x].initialer(process_List[x].id_,process_List[x].arrival_,process_List[x].burst_);
	}
	
    for (int i(0); i < n_; i++)
    {
        random = random + a[i].burst_; //determine random process
    }

    while (random > 0) 
    {
        int win = 1 + rand() % random;
        for (int i(0); i < n_; i++)
        {
            if (a[i].burst_!=0)
            {
                if (a[i].burst_ >= win)
                {
                    a[i].rt = time;
                    a[i].tt = time + a[i].burst_;
                    a[i].wt = time;
                    time = time + a[i].burst_;
                    random =random - a[i].burst_;

                    avgResponse = avgResponse + a[i].rt;
                    avgTurnaround = avgTurnaround + a[i].tt;
                    avgWait = avgWait +  a[i].wt;

                    a[i].burst_= 0;
                }
                else{}
            }
        }
    }
	avgResponse = avgResponse/n_;
	avgTurnaround = avgTurnaround/n_;
	avgWait = avgWait/n_;
	stats();
};






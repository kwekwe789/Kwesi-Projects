#include "shell.h"
#include "process.h"
#include "scheduler.h"
#include "tlb.h"
#include <string>


int main()
{ 
  std::string prompt = "cshell% ";
  std::string input;
  std::string echoString;
  int id(1);
  int arrival(0);
  int burst(0);
  int ref(0);
  std::string result1;
  std::string result2;
  

  while(true)
  {
    std::cout << prompt;
    std::getline(std::cin, input);
    // separate input into tokens
    std::stringstream iss(input);
    std::vector<std::string> tokens;
	std::vector<Process> process_List;
    std::string token;
	std::string file("");

    while(iss >> token)
    {
        tokens.push_back(token);
    }
    
    for (int i = 1; i < tokens.size(); i++)
    {
      echoString = echoString + tokens[i] + " "; 
    }
	if (tokens[0] == "exit")
	{
		exit(0);
	}
	else if (tokens[0] == "cd")
	{
		cd(tokens[1]);
	}
	else if (tokens[0] == "echo")
	{
		std::cout << echoString << std::endl;
	}
	else if (tokens[0] == "help")
	{
		std::cout << "recieved help" << std::endl;
		help();
	}
	else if (tokens[0] == "sched")
	{
		std::ifstream inputfile("input.txt");
		if (!inputfile) {
        std::cerr << "File could not be opened!" << std::endl;}
		
		while (!inputfile.eof())
		{
			inputfile >> arrival >> burst;			
			Process p(id,arrival,burst); 
			id++;
			process_List.push_back(p);
		}
		inputfile.close();
		Scheduler s(process_List);
		s.schedule();
		id=1;
	}
	else if (tokens[0] == "tlb")
	{
		int res1(0);
		int res2(0);
		double hits1(0.0);
		double eat1(0.0);
		double hits2(0.0);
		double eat2(0.0);
		double hits3(0.0);
		double eat3(0.0);
		TLB *tlb1 = new TLB();
		TLB *tlb2 = new TLB();
		TLB *tlb3 = new TLB();
		tlb1->print();
		tlb_entry TLB[1000];
		int number[1000];
		int ii(0);
		std::ifstream inputfile1("input.txt");
		int binaryNum[16];
		if (!inputfile1) {
        std::cerr << "File could not be opened!" << std::endl;}
		while (!inputfile1.eof())
		{
			inputfile1 >> ref;
			number[ii]=ref;
			ii++;
		}
		inputfile1.close();
		for(int x(0); x <1000; x++)
		{	
			ref = number[x];
			res1=ref>>8;
			res2=ref&0xff;
			TLB[x].setPage(res1);
			TLB[x].setFrame(res2);
			result1.clear();
			result2.clear();
			if(tlb1->contains(TLB[x].getPage(),x)==true)
			{
				hits1++;
			}
			else
			{
				if(tlb1->filled_==4)
				{					
					tlb1->replaceFIFO(TLB[x],x);
				}
				else
				{
					tlb1->insert(TLB[x],x);
				}
			}
			if(tlb2->contains(TLB[x].getPage(),x)==true)
			{
				hits2++;
			}
			else
			{
				if(tlb2->filled_==4)
				{					
					tlb2->replaceLRU(TLB[x],x);
				}
				else
				{
					tlb2->insert(TLB[x],x);
				}
			}
			if(tlb3->contains(TLB[x].getPage(),x)==true)
			{
				hits3++;
			}
			else
			{
				if(tlb3->filled_==4)
				{					
					tlb3->replaceRandom(TLB[x],x);
				}
				else
				{
					tlb3->insert(TLB[x],x);
				}
			}
		}
		std::cout << " " << std::endl;
		std::cout << "First in First Out" << std::endl;
		tlb1->print();
		std::cout << "Number of hits: " << hits1 << std::endl;
		std::cout << "Number of references: "<< 1000 << std::endl;	
		hits1=(hits1/1000);
		std::cout << "Hit Ratio: "<< hits1 << std::endl;	
		eat1 = (hits1*(500 + 20)) + ((1-hits1)*((500*2) + 20));
		std::cout << "Effective Access Time: " << eat1 << std::endl;
		std::cout << " " << std::endl;
		std::cout << "Least Recently Used" << std::endl;
		tlb2->print();
		std::cout << "Number of hits: " << hits2 << std::endl;
		std::cout << "Number of references: "<< 1000 << std::endl;	
		hits2=(hits2/1000);
		std::cout << "Hit Ratio: "<< hits2 << std::endl;	
		eat2 = (hits2*(500 + 20)) + ((1-hits2)*((500*2) + 20));
		std::cout << "Effective Access Time: " << eat2 << std::endl;
		std::cout << " " << std::endl;
		std::cout << "Random Replacement" << std::endl;
		tlb3->print();
		std::cout << "Number of hits: " << hits3 << std::endl;
		std::cout << "Number of references: "<< 1000 << std::endl;
		hits3=(hits3/1000);
		std::cout << "Hit Ratio: "<< hits3 << std::endl;
		eat3 = (hits3*(500 + 20)) + ((1-hits3)*((500*2) + 20));
		std::cout << "Effective Access Time: " << eat3 << std::endl;
		delete tlb1;
		delete tlb2;
		delete tlb3;
	}
	else
    {
      pid_t pid; //creation of child using fork
	  pid = fork();
      if (pid == 0)
      {
        // Child process operation
        std::vector<char *> c_args;
        for (const std::string &arg : tokens)
        {
          c_args.push_back(const_cast<char *>(arg.c_str())); //string conversion
        }
        c_args.push_back(nullptr);

        if (execvp(c_args[0], c_args.data()) == -1) //checks to see if the command will fail
        {
          perror("execvp "); //send error message
          exit(EXIT_FAILURE);
        }
      }
      else if (pid < 0) //if an error has occured
      {
        perror("fork operation failed");
      }
      else
      {
        // Parent process waits for child to complete 
        wait(NULL);
      }
    }
  }
  return EXIT_SUCCESS;
}
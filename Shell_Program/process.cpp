#include "process.h"

Process::Process(): id_(0), arrival_(0), burst_(0), wt(0), rt(0), tt(0){}
Process::Process(int id, int arrival, int burst): id_(id), arrival_(arrival), burst_(burst), wt(0), rt(0), tt(0){}

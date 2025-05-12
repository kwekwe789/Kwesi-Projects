#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

#ifndef SHELL_H
#define SHELL_H

void cd(std::string c);
void help();

#endif

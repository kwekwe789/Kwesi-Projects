#include "shell.h"

void cd(std::string direct)
{
	int change = chdir(direct.c_str()); 
    if(change < 0) //check pointer position of string
	{
		std::cout << "Change of directory to " << direct.c_str() << " was unsuccessful." << std::endl;
	}
    else
	{
		
    	std::cout << "The change of directory to " << direct.c_str() << " was successful." << std::endl;
	}
}

void help() //prints out menu for instructions
{
	std::cout << "Help:"  << std::endl;
	std::cout << "cd will change the current directory." << std::endl;
	std::cout << "echo will repeat what you typed in." << std::endl;
	std::cout << "exit will exit the program." << std::endl;
}

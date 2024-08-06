// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// kkyeifordjour
#include <fstream> //Here I'm including the different libraries I will be using including the car declaration
#include <iostream>
#include "car.h"
#include <stdlib.h>
#include <time.h>
void simulaterace(Car arr[33]); //Function declaration
int main()
{
	Car driver[33]; //Here I am creating variables that I will be using, including an array of cars to hold the drivers
	int i(0);
	int randonum(0);
	std::string name("");
	int speed;
	int control;
	std::ifstream inStream; 
 
	std::ifstream inputFile("indy500.txt"); //Here I am using the ifstream to find and open the file I want to read in from 
 
	while (!inputFile.eof()) //Here I'm using a loop to read in each line of the file and set the name, control, and speed of each driver to a car object 
							 //in the previously created array
	{
		inputFile >> name >> speed >> control;
		driver[i].setName(name);
		driver[i].setSpeed(speed);
		driver[i].setControl(control);
		i++;
	}
	inStream.close(); //Here I'm closing the file to avoid data leakage
	std::cout << "\n";
	std::cout << "***Welcome to the 2023 Indianapolis 500 Race!*** "<<std::endl<<std::endl;
	simulaterace(driver); //Here I'm calling the simulaterace function
	std::cout << "Thank you for using my race simulation program - goodbye!"<<std::endl<<std::endl;
	return 0;
}
void simulaterace(Car arr[33]) //This is where I put the actual contents of the simulaterace function
{
	int num[500]; //Here I am declaring variables, including a very large arrray that will hold randomly generated numbers
	int j(0);
	int i;
	int max(0);
	int u(0);
	int win(0);
	int ln(0);
	int min(0);
	int nic(0);
	int stef(0);
	int idk(0);
	int ph(0);
	srand((unsigned) time(NULL)); //Here I am setting the seed for the random number generator
	for(i = 1; i <= 500; i++) //Here I create a loop to generate 500 random numbers from 1 to 10 and place each in an array to be used later
	{
		
		num[j] = (rand() % 10)+1;
		j++;
	}
	int k(0);
	while (max<199) //This is the main loop that I will use to itirate until a racer reaches 200 laps
	{	
		int f(0);
		while(f<33) //This is a loop I will use to figure out the lap number of each driver, it will go through and set the lap only one time.
		{
			if(arr[f].getControl() > 5) //Here I use an if statement to check the control value and use the conditions that apply to find the lap number
			{
				int div(0); //Here I declare more variables
				int step(0);
				div = arr[f].getControl()/num[k]; //If control is greater than 5, I will take a random number from the array and divide the control by that number
				step = div + arr[f].getSpeed() + arr[f].getLap(); //then I will use the get speed and get lap constructors to set the new lap of the driver
				arr[f].setLap(step);
				k++;
				if(arr[f].getLap()> max) //Here I use an if statement to track the driver with the highest lap number and set that to a max variable
				{
					max = arr[f].getLap();
				}
			}
			else //This is the else part of the if else statement where the control is less than 5
			{
				int lap(0);
				lap = arr[f].getLap() + arr[f].getSpeed(); //The lap will be set by simply just adding the speed value to the previous lap number
				arr[f].setLap(lap);
				if(arr[f].getLap()> max) //Here I use an if statement to track the driver with the highest lap number and set that to a max variable
				{
					max = arr[f].getLap();
				}
			}
			f++;
		}
		std::cout << "***--> Racing..." << std::endl;
	}
	for(win = 0; win<33; win++) //Here I create a loop to check which driver has reached 200 laps first, some may get over 200 but I have a way to fix that
	{
		if (arr[win].getLap() == max) //Here I am creating an if statement assuming someone has reached 200 laps or more
		{	
			min = max - 200; //Because I couldn't find a way to cap the laps at 200, I will set the winners lap value at 200 by subtracting by how many laps over 200 the driver is
			nic = arr[win].getLap() - min;
			arr[win].setLap(nic);
			idk = win;
			std::cout << "\n";
			std::cout << "***" << arr[win].getName() <<" has won the 2023 Indianapolis 500! ***" << std::endl; //Here I will print out the winners name
		}
	}
	for(stef = 0; stef<idk ; stef++) //Here I created a loop to cycle through the drivers to find any possible who have a lap value over 200
	{
		if(arr[stef].getLap() >= 200) //Here I'm using an if statement to see if each drivers lap value if greater than or equal to 200, and if they are I will subtract by the same value 
		{							  //That I used in the previous loop to set the winners Lap value to 200. This will ensure that only the winner has a lap value of 200 or more
			ph = arr[stef].getLap() - min;
			arr[stef].setLap(ph);
		}
	}
		
	for(stef = idk + 1; stef<33 ; stef++) //This loop has the same function as the one before except the checks racers after the winner, the previous one only checks racers
	{									  //Before the winner
		if(arr[stef].getLap() >= 200)
		{
			ph = arr[stef].getLap() - min;
			arr[stef].setLap(ph);
		}
	}
	std::cout << "\n";	
	std::cout << "Driver Name: Lap Number" << std::endl;
	std::cout << "***********************" << std::endl;
	for(ln = 0; ln<33; ln++) //Using this loop I will cycle through each driver and print each Racer and their lap value
	{
		std::cout<< arr[ln].getName() << ": " << arr[ln].getLap() << std::endl;
	}
	std::cout << "\n";
}

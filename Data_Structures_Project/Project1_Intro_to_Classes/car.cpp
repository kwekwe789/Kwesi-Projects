// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// kkyeifordjour
#include "car.h" //Here I am including the car object library 
Car::Car() //Here I create the constructor and set every cars Lap value to zero
{
	lap_ = 0;
}

Car::~Car() //Here I create the destructor
{
}
void Car::setName(std::string n) //Here I am creating the getters and setters for the Car objects
{
name_ = n;
}
std::string Car::getName() 
{
return name_;
}
void Car::setSpeed(int speed) 
{
speed_ = speed;
}
int Car::getSpeed()
{
return speed_;
}
void Car::setControl(int control)
{
control_ = control;
}
int Car::getControl()
{
return control_;
}
void Car::setLap(int lap)
{
lap_ = lap;
}
int Car::getLap()
{
return lap_;
}
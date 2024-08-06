// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// kkyeifordjour
#include <string>
class Car
{
	public: 
		Car(); 
		~Car();
		void setName(std::string n); //Listing getters and setters in a public scope
		std::string getName();
		void setSpeed(int speed);
		int getSpeed();
		void setControl(int control);
		int getControl();
		void setLap(int lap);
		int getLap();
	private:
		std::string name_; //Creating attributes of the car class in a private scope
		int speed_;
		int control_;
		int lap_;
};
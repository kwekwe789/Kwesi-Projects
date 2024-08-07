#include <string>
// "struct" is just like "class" except that everything is public by default
// You need to define the four functions listed below to use this function.
// You will not be able to use a priority queue without defining the operatorfunction.
struct Item {
	std::string name_;
	int value_;
	int weight_;
	int ratio_;
	Item();
	double ratio() const;
	void print() const;
	bool operator<(const Item&) const;
	void setName(std::string name);
	void setPesos(int pesos);
	void setWeight(int weight);
	void setRatio(int ratio);
	std::string getName();
	int getPesos();
	int getWeight();
	void setItem(Item item);
};
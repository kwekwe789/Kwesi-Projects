#include <string>
// "struct" is just like "class" except that everything is public by default
// You need to define the four functions listed below to use this function.
// You will not be able to use a priority queue without defining the operator function.
struct Item {
std::string name_;
double value_;
double weight_;
double ratio_;
Item();
double ratio() const;
void print() const;
bool operator<(const Item &) const;
void setName(std::string name);
void setPesos(double pesos);
void setWeight(double weight);
void setRatio(double ratio);
double getRatio();
std::string getName();
double getPesos();
double getWeight();
void setItem(Item item);
};

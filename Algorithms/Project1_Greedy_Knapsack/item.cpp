#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "item.h"
#include <string>
#include "pq.h"
bool Item::operator<(const Item & right) const {
if(ratio_ < right.ratio())
{
return true;
}
else
{
return false;
}
}
Item::Item()
{
name_ = "";
weight_ = 1;
value_ = 0;
}
double Item::ratio()const
{
return ratio_;
}
void Item::print()const
{
std::cout<< name_ << " " << value_ << " " << weight_ << std::endl;
}
void Item::setName(std::string name)
{
name_ = name;
}
void Item::setPesos(double pesos)
{
value_ = pesos;
}
void Item::setWeight(double weight)
{
weight_ = weight;
}
void Item::setRatio(double ratio)
{
ratio_ = ratio;
}
double Item::getRatio()
{
return ratio_;
}
std::string Item::getName()
{
return name_;
}
double Item::getPesos()
{
return value_;
}
double Item::getWeight()
{
return weight_;
}
void Item::setItem(Item item)
{
name_ = item.getName();
value_ = item.getPesos();
weight_ = item.getWeight();
ratio_ = item.getRatio();
}

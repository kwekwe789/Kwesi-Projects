//Hash Entry Class Definition
//Honor Pledge:
//I pledge that I have neither given nor
//received any help on this assignment.
//wkissel, majames, sjhartman, kkyeifordjour
#include "HashEntry.h"

HashEntry::HashEntry()
{
	key_ = 0;
	value_ = 0;
	status_ = EMPTY;
}

HashEntry::~HashEntry()
{

}
//accessor methods for the entrys
int HashEntry::getKey()
{
	return key_;
}

int HashEntry::getValue()
{
	return value_;
}

Status HashEntry::getStatus()
{
	return status_;
}

void HashEntry::setKey(int key)
{
	key_ = key;
}

void HashEntry::setValue(int value)
{
	value_ = value;
}

void HashEntry::setStatus(Status status)
{
	status_ = status;
}
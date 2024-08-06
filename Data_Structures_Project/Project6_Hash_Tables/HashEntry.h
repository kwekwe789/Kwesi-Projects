//Hash Entry Class Declaration
//Honor Pledge:
//I pledge that I have neither given nor
//received any help on this assignment.
//wkissel, majames, sjhartman, kkyeifordjour

#ifndef HASHENTRY_H
#define HASHENTRY_H
enum Status { EMPTY, OCCUPIED, REMOVED };
class HashEntry
{

public:

	HashEntry();
	~HashEntry();
	int getKey();
	int getValue();
	Status getStatus();
	void setKey(int key);
	void setValue(int value);
	void setStatus(Status status);

private:
	int key_;
	int value_;
	Status status_;

};
#endif 
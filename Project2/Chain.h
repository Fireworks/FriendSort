#ifndef __chain__
#define __chain__

#include <iostream>
#include "Person.h"
#include "Addable.h"

using namespace std;

class Chain : public Addable{
public:
struct Node {
	Person* p;
	Node* next;
};
	int sizeC;
	Node* start;
	Chain();
	double execTime;
	int numAccesses;
	void print();
	void add(Person* p);
	void reverse();
	void inSort(int criteria);
	double getExecTime();
	int getNumAccess();
private:
	

};


#endif
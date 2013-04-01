#ifndef __arraylist__
#define __arraylist__

#include <iostream>
#include "TreeLeaf.h"

using namespace std;

class ArrayList {
public:
	ArrayList();
	int size;
	double execTime;
	int numAccesses;
	void add(Person* item);
	void insert(int index, Person* item);
	void set(int index, Person* item);
	void remove(int index, Person* item);
	Person* get(int index);
	void reverse();
	void inSort(int criteria);
	void print();
	double getExecTime();
	int getNumAccess();
private:
	Person** items;

};


#endif
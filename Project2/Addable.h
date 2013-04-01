#ifndef __addable__
#define __addable__

#include <iostream>
#include "Person.h"


class Addable{
public:
	virtual void add(Person* p) {};
	virtual void reverse() {};
	virtual void inSort(int criteria) {};
	virtual void print() {};
	virtual double getExecTime() {return 0.0;};
	virtual int getNumAccess(){return 0;};
private:

};


#endif
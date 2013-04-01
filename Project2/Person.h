#ifndef __person__
#define __person__

#include <iostream>

using namespace std;

class Person{
public:
	Person(string fname, string lname, string birthday, string hometown);
	Person();
	string birthday, fname, lname, hometown;
	int compareTo(int criteria, Person* p);
	string toString();
};

#endif
#include <string.h>
#include "jansson.h"
#include <stdexcept>
#include <iostream>
#include <streambuf>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <ctime>
#include "ArrayList.h"
#include "Person.h"

using namespace std;

Person::Person(string fname, string lname, string birthday, string hometown){
	this->birthday = birthday;
	this->fname = fname;
	this->lname = lname;
	this->hometown = hometown;
}

Person::Person(){}

int Person::compareTo(int criteria, Person* p){
	switch(criteria){
	case 1:
		if(this->lname > p->lname)
			return 1;
		if(this->lname < p->lname)
			return -1;
		else
			return 0;
	case 2:
		if(this->birthday > p->birthday)
			return 1;
		if(this->birthday < p->birthday)
			return -1;
		else
			return 0;
	case 3:
		if(this->hometown > p->hometown)
			return 1;
		if(this->hometown < p->hometown)
			return -1;
		else
			return 0;
	default:
		return 0;
	}
}

string Person::toString(){
	string info = "";
	if(birthday == "" && hometown != "")
		info = lname + ", " + fname + " (" + hometown + ")\n";
	else if (birthday != "" && hometown == "")
		info = lname + ", " + fname + " (" + birthday + ")\n";
	else if (birthday == "" && hometown == "")
		info = lname + ", " + fname + "\n";
	else
		info = lname + ", " + fname + "\n" + birthday + "\n" + hometown + "\n";

	return info;
}
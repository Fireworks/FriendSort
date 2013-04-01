#ifndef __HashMap_
#define __HashMap_

#include <iostream>
#include <string>
#include "Chain.h"
#include "HashEntry.h"
#include "Addable.h"
#include "Person.h"


const int TABLE_SIZE = 2500;

class HashMap : public Addable{
private:
      HashEntry **table;
	  int criteria;
public:
	int hashAccess;
	double execTime;

	HashMap(int criteria) {
		this->criteria = criteria;
		table = new HashEntry*[TABLE_SIZE];
		for (int i = 0; i < TABLE_SIZE; i++)
			table[i] = NULL;
	}

	Chain* get(string key) {
		hashAccess = 0;
		int hash = (atoi(key.c_str()) % TABLE_SIZE);
		hashAccess++;
		while (table[hash] != NULL && table[hash]->getKey() != key){
			hash = (hash + 1) % TABLE_SIZE;
		}
		if (table[hash] == NULL){
			hashAccess++;
			return NULL;
		}else{
			hashAccess++;
			return table[hash]->getValue();
		}
	}

	void put(string key, Chain* value) {
		int hash = (atoi(key.c_str()) % TABLE_SIZE);
		while (table[hash] != NULL && table[hash]->getKey() != key)
				hash = (hash + 1) % TABLE_SIZE;
		if (table[hash] != NULL)
				delete table[hash];
		table[hash] = new HashEntry(key, value);
	}  

	~HashMap() {
		for (int i = 0; i < TABLE_SIZE; i++)
			if (table[i] != NULL)
				delete table[i];
		delete[] table;
	}

	void add(Person* p){
	string temp = "";
	switch(criteria){
	case 1:
		temp = p->lname + ", " + p->fname;
		break;
	case 2:
		temp = p->birthday;
		break;
	case 3:
		temp = p->hometown;
		break;
	default:
		break;
	}

	if(get(temp) != NULL)
		this->get(temp)->add(p);
	else{
		Chain *chain = new Chain();
		chain->add(p);
		this->put(temp,chain);
	}
	}

};



#endif
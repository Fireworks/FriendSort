#include <string.h>
#include "jansson.h"
#include <stdexcept>
#include <iostream>
#include <streambuf>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <ctime>
#include "Person.h"
#include "Chain.h"

using namespace std;


Chain::Chain(){
	this->start = NULL;
	this->sizeC = 0;
};

struct Node {
	Person* p;
	Node* next;
};


void Chain::add(Person* p){
	Node *newNode, *newNode2;

	newNode = new Node;
	newNode->p = p;
	newNode->next = NULL;

	if(start == NULL)
		start = newNode;
	else{
		newNode2 = start;
		while (newNode2->next != NULL){
			newNode2 = newNode2->next;
		}
		newNode2->next = newNode;
	}
	sizeC++;
}

void Chain::reverse(){
	clock_t startClock = clock();
	numAccesses = 0;
	numAccesses++;
	if(start == NULL)
		return;

	Node *prev = NULL, *curr, *next;
	curr = start;
	numAccesses++;
	while(curr != NULL){
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
		numAccesses = numAccesses + 2;
	}

	start = prev;

	clock_t stopClock = clock();
	execTime = (double)(stopClock - startClock)/(double)CLOCKS_PER_SEC;
}

void Chain::inSort(int criteria){
	numAccesses = 0;
	clock_t startClock = clock();
    Node* first = NULL;
        
    for(Node* key = start; key != NULL; key = key->next){
        if(first == NULL || key->p->compareTo(criteria,first->p)<0){
            Node* temp = new Node();
            temp->p = key->p;
            temp->next = first;
            first = temp;
			numAccesses = numAccesses + 2;
            continue;
        }
        for(Node* curr = first; curr!=NULL; curr = curr->next){
            if(key->p->compareTo(criteria,curr->p)>=0 && (curr->next==NULL || key->p->compareTo(criteria,curr->next->p)<0)){
                Node* temp = new Node;
                temp->p = key->p;
                temp->next = curr->next;
                curr->next = temp;
				numAccesses = numAccesses + 3;
                break;
            }
        }
    }
    start = first;
	clock_t stopClock = clock();
	execTime = (double)(stopClock - startClock)/(double)CLOCKS_PER_SEC;
}

void Chain::print(){
	numAccesses = 0;
	clock_t startClock = clock();
	Node *check;
	check = start;

	while(check != NULL){
		numAccesses++;
		cout << check->p->toString() << endl;
		check = check->next;
	}
	clock_t stopClock = clock();
	execTime = (double)(stopClock - startClock)/(double)CLOCKS_PER_SEC;
}

double Chain::getExecTime(){
	return execTime;
}

int Chain::getNumAccess(){
	return numAccesses;
}
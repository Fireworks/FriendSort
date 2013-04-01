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
#include "Chain.h"
#include "HashMap.h"

using namespace std;

void parse(char* filename, Addable* addable);

int main(int argc, char *argv[]){
	double hashTime;
	int hashAccess;

	if(argv[1] != NULL){
		string filename = argv[1];
		char *filechar = new char[filename.size() + 1];
		std::copy(filename.begin(), filename.end(), filechar);
		filechar[filename.size()] = '\0'; 
	
		int dataStructureN = atoi(argv[2]);
		Addable *mainData;
		HashMap *mainhash;

		if(dataStructureN == 3){
			mainhash = new HashMap(atoi(argv[3]));
			mainData = mainhash;
			parse(filechar, mainData);

			for(int i = 4 ; i < argc ; i++){
				string key = argv[i];

				clock_t startClock = clock();
				if(mainhash->get(key) == NULL){
					hashAccess = mainhash->hashAccess;
					cout << "NO RECORDS FOUND." << endl;
				}else{
					mainhash->get(key)->print();
					hashAccess = mainhash->hashAccess;
				}
				clock_t stopClock = clock();
				printf("time taken: %.3fs\n",(double)(stopClock - startClock)/(double)CLOCKS_PER_SEC);
				cout << "Number of accesses/pointer follows: " << hashAccess << "\n" << endl;
			}
			cin.get();
		} else {
			if (dataStructureN == 2){
				mainData = new Chain();					
			} else {
				mainData = new ArrayList();
			}
			parse(filechar, mainData);

			int criteriaN = atoi(argv[2]);
			for(int i = 3 ; i < argc ; i++){

			int commandN = atoi(argv[i]);
				switch(commandN){
					case 1:
						mainData->reverse();
						break;
					case 2:
						mainData->inSort(criteriaN);
						break;
					case 3:
						printf("time taken: %.3fs\n", mainData->getExecTime());
						cout << mainData->getNumAccess() << endl;
						break;
					case 4:
						mainData->print();
						break;
					case 5:
						exit(0);
					default:
						break;
				}
				cin.get();
			}

		}
		return 0;
	}
	cout << "Please input filename" << endl ;
	string filename = "";
	getline(cin, filename);
	char * filechar = new char[filename.size() + 1];
	std::copy(filename.begin(), filename.end(), filechar);
	filechar[filename.size()] = '\0'; 

	cout << "Please choose a data structure" << endl;
	cout << "1. ArrayList" << endl;
	cout << "2. Chain" << endl;
	cout << "3. Hashtable" << endl;
	string dataStructure = "";
	getline(cin, dataStructure);
	int dataStructureN = atoi(dataStructure.c_str());

	cout << "Please choose a criteria" << endl;
	cout << "1. Name" << endl;
	cout << "2. Birthday" << endl;
	cout << "3. Location" << endl;
	string criteria = "";
	getline(cin, criteria);
	int criteriaN = atoi(criteria.c_str());

	Addable *mainData;
	HashMap *mainhash;

		if(dataStructureN == 1)
			mainData = new ArrayList();
		else if(dataStructureN == 2)
			mainData = new Chain();	
		else if (dataStructureN == 3){
			mainhash = new HashMap(criteriaN);
			mainData = mainhash;
		}
		parse(filechar, mainData);

	command:
	if(dataStructureN < 3){
		cout << "Please choose a command" << endl;
		cout << "1. Reverse List" << endl;
		cout << "2. Sort using insertion sort" << endl;
		cout << "3. Print out number of accesses and execution time for last operation" << endl;
		cout << "4. Print out list" << endl;
		cout << "5. Exit" << endl;

		string command = "";
		getline(cin, command);
		int commandN = atoi(command.c_str());

		if(dataStructureN < 3){
			switch(commandN){
				case 1:
					mainData->reverse();
					goto command;
				case 2:
					mainData->inSort(criteriaN);
					goto command;
				case 3:
					printf("time taken: %.3fs\n", mainData->getExecTime());
					cout << mainData->getNumAccess() << endl;
					goto command;
				case 4:
					mainData->print();
					goto command;
				case 5:
					exit(0);
				default:
					break;
			}
		}

	} else {
		criteria:
		cout << "Enter a value for the selected criteria or enter 'exit' to exit:" << endl;
		string cvalue = "";
		getline(cin, cvalue);
		if(cvalue == "exit")
			exit(0);
		clock_t startClock = clock();
		if(mainhash->get(cvalue) == NULL){
			hashAccess = mainhash->hashAccess;
			cout << "NO RECORDS FOUND." << endl;
		}
		else{
			mainhash->get(cvalue)->print();
			hashAccess = mainhash->hashAccess;
		}
		clock_t stopClock = clock();
		printf("time taken: %.3fs\n",(double)(stopClock - startClock)/(double)CLOCKS_PER_SEC);
		cout << "Number of accesses/pointer follows: " << hashAccess << endl;
		goto criteria;
	}
		delete[] filechar;
}

void parse(char* filename, Addable* addable){
	json_error_t error;
	json_t *root;
	json_t *names;
	root = json_load_file(filename, 0, &error);
	names = json_object_get(root, "data");

	int arraySize = json_array_size(names);

	for(int i = 0 ; i < json_array_size(names) ; i++){
		json_t *name;
		name = json_array_get(names, i);

		string fname, lname, birthday, hometown = "";
		
		if(json_object_get(name,"first_name") == NULL)
			fname = "";
		else
			fname = json_string_value(json_object_get(name,"first_name"));

		if(json_object_get(name, "last_name") == NULL)
			lname = "";
		else
			lname = json_string_value(json_object_get(name,"last_name"));
		

		if(json_object_get(name,"birthday") == NULL)
			birthday = "";
		else
			birthday = json_string_value(json_object_get(name,"birthday"));
		
		
		if(json_object_get(name,"hometown") == NULL)
			hometown = "";
		else{
			hometown = json_string_value(json_object_get(json_object_get(name,"hometown"), "name"));
		}
		
		addable->add(new Person(fname, lname, birthday, hometown));
	}
	return;
}

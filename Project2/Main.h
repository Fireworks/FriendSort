#ifndef __main__
#define __main__
#include <jansson.h>
#include <iostream>

using namespace std;

class Main{

public:
	json_t parse(char* filename);
	int main(int argc, char *argv[]);
};
#endif
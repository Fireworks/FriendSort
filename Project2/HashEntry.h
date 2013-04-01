#ifndef __HashEntry_
#define __HashEntry_

#include <iostream>
#include <string>
#include "Chain.h"

using namespace std;

class HashEntry {
private:
      string key;
      Chain* value;
public:
      HashEntry(string key, Chain* value) {
            this->key = key;
            this->value = value;
      }

      string getKey() {
            return key;
      }

      Chain* getValue() {
            return value;
      }
};

#endif
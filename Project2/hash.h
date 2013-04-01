// functions to convert from type K to nonnegative integer
// derived from similar classes in SGI STL


#ifndef hash_
#define hash_

#include <iostream>
#include <string>

using namespace std;

class Hash
{
   public:
      size_t operator()(const string theKey) const
      {// Convert theKey to a nonnegative integer.
         unsigned long hashValue = 0; 
         int length = (int) theKey.length();
         for (int i = 0; i < length; i++)
            hashValue = 5 * hashValue + theKey.at(i);
    
         return size_t(hashValue);
      }
};



#endif

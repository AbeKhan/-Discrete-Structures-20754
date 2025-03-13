#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using std::string;
using std::istream;
using std::ostream;

class Set
{
  private:
    int capacity;   // Capacity of the set, e.g. max number of available elements
    int size;       // size of the set
    string* elements;      // Pointer to a string array, used to implement this set
  
  public:
    Set(int cap = 100);
    ~Set();
    bool isFull(void);    // Check whether this set reaches its capacity
    bool isEmpty(void);   // Check whether this set is empty
    int find(string v);   // Find the index of a specific string in this set
    void insert(string v);    // Insert a single element to this set
    void scan(istream& i);    // Read the elements from a input stream
    void print(ostream& o, const char* msg);   // Print all the elements of this set
};



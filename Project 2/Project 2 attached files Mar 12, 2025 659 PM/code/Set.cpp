#include "Set.h"
using std::cout;
using std::endl;

/* This exception is thrown when the status of this list is invalid. */
struct SetException {
    SetException(const char* m) {
	    cout << endl << "There is a problem with this set: " << m << "." << endl;
    }
};

/* Constructor */
Set::Set(int cap): capacity(cap),size(0) {
    elements = new string[capacity];
}

/* Destructor */
Set::~Set() {
    if (elements) {
        delete[] elements;
    }
}

/* Check whether this list is full. */
bool Set::isFull(void) {
    return size >= capacity - 1;
}

/* Check whether this list is empty. */
bool Set::isEmpty(void) {
    return size <= 0;
}

/* Check whether a string target v is contained in this set.
 * If found, return the index of this string. Otherwise return -1. */
int Set::find(string v) {
    for (int idx = 0; idx < size; idx++) {
        if (v.compare(elements[idx]) == 0) {
            return idx;
        }
    }
    return -1;
}

/* Insert a string v into the list.
 * If string v has already been saved in this set, no need to add it again. This 
 * means no duplicates in this set.
 * SetException would be thrown if the list is full. */
void Set::insert(string v) {
    if (isFull()) {
        throw SetException("This set is full!");
    }

    if (find(v) == -1) {
        elements[size++] = v;
        //print(); Custom testing visual
    }
    // If no duplicate check is needed, we can use "elements[size++] = v;"
    // Complete: check duplicated values before insertion
	
}

/* Scan the input stream, and insert all the strings in this
 * stream into the list. */
void Set::scan(istream& i) {
    string v;
    while (i >> v) {
        insert(v);
    }
}

/* Display all the string elements in this list to a stream. */
void Set::print(ostream& o, const char* msg) {
    o << msg << "{";
    for (int idx = 0; idx < size; idx++) {
        if (idx > 0) {
            o << ",";
	    }
        o << elements[idx];
    }
    o << "}" << endl;
}
/*Custom Overloads ----------------------------------------------------------------------------------------*/
void Set::print(ostream& o, const char* msg, int columnCount) {
    int counter = 1;
    o << msg;
    for (int idx = 0; idx < size; idx++) {
        o << elements[idx];
        if (idx >= 0 && idx < size-1) {
            o << ",";
        }
        if (counter >= columnCount && idx < size - 1) {
            counter = 1;
            o << "\n";
        }
        else
        {
            counter++;
        }
    }
    
    if (columnCount > 0) {
        o << "}" << endl;
    }else{
        o << endl;
    }
}

int Set::sizeCount(/*Return 'Size' privateVariable*/) {return size;}

string Set::find(int v /*Index without mapping*/) {
    return elements[v];
}

void Set::insert(Set& object /*Inserting Subset*/) {
    if (isFull()) {
        throw SetException("This set is full!");
    }
    string buildingString;
    for (int i = 0; i < object.sizeCount(); i++) {
        if (object.sizeCount()==1) {
            buildingString = object.find(i);
            continue;
        }
        buildingString = buildingString + "," + object.find(1);
    }
    insert("{" + buildingString + "}");
}

//void Set::print(string msg /*Custom Testing Only*/) {
//    cout << msg;
//    for (int idx = 0; idx < size; idx++) {
//        if (idx > 0) {
//            cout << ",";
//        }
//        cout << elements[idx];
//    }
//    cout << "}\n" << endl;
//}
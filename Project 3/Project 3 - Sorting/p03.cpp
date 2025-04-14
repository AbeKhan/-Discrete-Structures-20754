/*
 * This program evaluates the performance of improved insertion sort.
 * ----------------------------------------------
 * Author(s):   Abraham Khan        &&      Justin Stevenson
 * Email(s):    Akhan33@uco.edu     &&      Jstevenson19@uco.edu
 * ----------------------------------------------
 */


#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cstring>
#include <time.h>

#include <vector>

//using std::cout, std::cin, std::endl;
//using std::string;
//using std::istream, std::ostream, std::ofstream;
using namespace std;

#ifndef MAX_FILE_LENGTH
#define MAX_FILE_LENGTH 255
#endif

/*
 * Handle command line error
 */
struct CommandLineException {
    CommandLineException(int max, int provided) {
        cout << endl;
        cout << "Number of command line arguments is wrong." << endl;
        cout << provided << " arguments were entered, and " << max << " are needed." << endl;
    }  
};

/*
 * Handle exception when openning a file
 */
struct FileException {
  FileException(const string file) {
    cout << endl;
    cout << "File \"" << file << "\" could not be opened." << endl;
  }
};

/*
 * Generate random elements for the input arrays.
 * The content for two arrays are the same.
 */
void GenerateArray(int* arr1, int* arr2, int size) {
  for (int i = 0; i < size; i++) {
    int num = (rand()) % size;
    arr1[i] = num;
    arr2[i] = num;
  }
}

/*
 * Print all the elements in int array arr to output stream o.
 * Elements are separated by a single space.
 */
void PrintArray(int* arr, int size, ostream& o) {
  for (int i = 0; i < size; i++) {
    o << arr[i] << " ";
  }
  o << endl;
}

/*
 * Print all the elements in int array arr to output stream o1.
 * Elements are separated by a single space.
 * The time used for this algorihtm is printed to output stream o2.
 * If we have multiple runs of this functions, the result will be append to this o1 and o2:
 * the result for each run will be a new line.
 * The time is in millisecond.
 */
void PrintResult(int* arr, ostream& o1, ostream& o2, int size, double duration) {
  for (int i = 0; i < size; i++) {
    o1 << arr[i] << " ";
  }
  o1 << endl;
  o2 << duration << endl;
}


/* Your implementation of the insertion sort. */
void MyInsertionSort(int* arr, int size) {
  /*** Complete: put your code here ***/
    int lastHold; 

    for (int lastPostion = size-1; lastPostion >= 0; lastPostion--) { //back of the array
        for (int startPostion = 0; startPostion < size; startPostion++) { //looping through array front -> back
            if (arr[lastPostion] <= arr[startPostion]) {
                lastHold = arr[lastPostion];
                arr[lastPostion] = arr[startPostion];
                arr[startPostion] = lastHold;
            }
        }

    }
    int tempHold = arr[0];
    for (int i = 0; i < size; i++) {
        arr[i] = arr[i + 1];
    }
    arr[size - 1] = tempHold;
    cout << arr[0] << endl;

}

/* Your implementation of the binary insertion sort. */
void MyImprovedSort(int* arr, int size) {
  /*** TODO: put your code here ***/
    int low, high;
    int mid;
    vector<int> vec(size);    
    
    for (int i = 0; i < size; i++) {
        low = 0, high = vec.size();
        while (high - low > 1) {
            mid = (high + low) / 2;
            if (vec[mid] < arr[i]) {
                /*if (arr[mid] = arr[i]) {

                }*/
                low = mid + 1;
            }
            else {
                high = mid;
            }
        }
        vec.insert(vec.begin() + vec[mid], arr[i]);
        cout << vec[mid] << endl;

    }
    copy(vec.begin(), vec.end(), arr);
    
    //if (arr[low] == searchingFor) {
    //    //cout << "Found"	<< " At Index " << low << endl;
    //    /*return result = low;*/
    //}
    //else {
    //    
    //    if (arr[high] == searchingFor) {
    //        cout << "Found" << " At Index " << high << endl;
    //        /*return result = high;*/
    //    }
    //    else {
    //        cout << "Not Found" << endl;
    //    }
    //}
    /*return result;*/
}



/*
 * ostream references can match the command line arguments
 * The input list is generated into the o1
 * The sorted list using algorithm 1 is stored into o2
 * The sorted list using algorithm 2 is stored into o3
 * The time used for each run of algorithm 1 is stored into o4
 * The time used for each run of algorithm 2 is stored into o5
 */
void P03Manager(ostream& o1, ostream& o2, ostream& o3, ostream& o4, ostream& o5) {
  // integer size is used to control the size of the list for sorting
  for (int size = 1000; size <= 10000; size += 1000) {
    int* arr1 = new int[size];
    int* arr2 = new int[size];
    
    clock_t t1, t2;
    double elapsed_time;

    // since the list is randomly generated, the time used would differ
    // we need to get the average time for performance evaluation
    // to get this average,we need to have multiple runs
    for (int i = 0; i < 1; i++) { /*Need to chnage*/
      // generate the arrays randomly
      GenerateArray(arr1, arr2, size);
      PrintArray(arr1, size, o1);

      // sort using algorithm 1
      t1 = clock();
      MyInsertionSort(arr1, size);
      t2 = clock();
      elapsed_time = (double)(t2 - t1) / CLOCKS_PER_SEC;	
      PrintResult(arr1, o2, o4, size, elapsed_time);

      // sort using algorithm 2
      t1 = clock();
      MyImprovedSort(arr2, size);
      t2 = clock();
      elapsed_time = (double)(t2 - t1) / CLOCKS_PER_SEC;
      PrintResult(arr2, o3, o5, size, elapsed_time);
    }

    delete [] arr2;
    delete [] arr1;
    arr2 = nullptr;	// make sure this memory isn't used
    arr1 = nullptr;	// make sure this memory isn't used
  }
}

int main(int argc, char* argv[])
{
  try
    {
      srand(time(NULL));  // seed for generating random numbers

      char ofn1[MAX_FILE_LENGTH],  // File for the unsorted list
        ofn2[MAX_FILE_LENGTH],     // File for the sorted list using insertion sort
	    ofn3[MAX_FILE_LENGTH],     // File for the sorted list using binary insertion sort
	    ofn4[MAX_FILE_LENGTH],     // File for the time used by each execution of binary sort
	    ofn5[MAX_FILE_LENGTH];     // File for the time used by each execution of insertion sort


/*Custom need to remove before turning project in*/
      bool testMode = 1;
      if (testMode){
          strcpy_s(ofn1, "Unsorted List");
          strcpy_s(ofn2, "Sorted - Insertion Sort");
          strcpy_s(ofn3, "Sorted - Binary Insertion Sort");
          strcpy_s(ofn4, "Time - Binary Sort");
          strcpy_s(ofn5, "Time - Insertion Sort");
          goto skipCmdInput;
      }
/*-------------------------------------------------------------------------*/


      cout << "Parameters specified in command line: " << endl;
      switch(argc) {
        case 6: cout << "the name of output file 5 for time used by algorithm 2, ";
        case 5: cout << "the name of output file 4 for time used by algorithm 1, ";
        case 4: cout << "the name of output file 3 for sorted array using algorithm 2, ";
        case 3: cout << "the name of output file 2 for sorted array using algorithm 1, ";
        case 2: cout << "the name of output file 1 for unsorted array. " << endl; break;
        case 1: cout << "nothing." << endl; break;
        default: throw CommandLineException(5, argc - 1);
      }

      // If there are not sufficient parameter from command line, we need to let the use input them
      switch (argc) {
        case 1: cout << endl << "Enter the name of output file 1 for unsorted array: "; cin >> ofn1;
		    case 2: cout << endl << "Enter the name of output file 2 for sorted array using algorithm 1: "; cin >> ofn2;
		    case 3: cout << endl << "Enter the name of output file 3 for sorted array using algorithm 2: "; cin >> ofn3;
		    case 4: cout << endl << "Enter the name of output file 4 for time used by algorithm 1: "; cin >> ofn4;
		    case 5: cout << endl << "Enter the name of output file 5 for time used by algorithm 2: "; cin >> ofn5; break;
		    case 6: break;
		    default: throw CommandLineException(5, argc - 1);
      }

      switch (argc) {
      //Original Code
		    /*case 6: strcpy(ofn5, argv[5]);
		    case 5: strcpy(ofn4, argv[4]);
		    case 4: strcpy(ofn3, argv[3]);
		    case 3: strcpy(ofn2, argv[2]);
		    case 2: strcpy(ofn1, argv[1]); break;*/
            
      //Small modification for my compiler
            case 6: strcpy_s(ofn5, argv[5]);
            case 5: strcpy_s(ofn4, argv[4]);
            case 4: strcpy_s(ofn3, argv[3]);
            case 3: strcpy_s(ofn2, argv[2]);
            case 2: strcpy_s(ofn1, argv[1]); break;
		    case 1: break;
		    default: throw CommandLineException(5, argc - 1);
      }

  skipCmdInput:
      ofstream o1(ofn1), o2(ofn2), o3(ofn3), o4(ofn4),o5(ofn5);

      if (!o1) throw FileException(ofn1);
      if (!o2) throw FileException(ofn2);
      if (!o3) throw FileException(ofn3);
      if (!o4) throw FileException(ofn4);
      if (!o5) throw FileException(ofn4);

      P03Manager(o1, o2, o3, o4, o5);

      o1.close();
      o2.close();
      o3.close();
      o4.close();
      o5.close();
    }
  catch(...)
    {
      cout << "Program ended with problem(s)." << endl;
      exit(EXIT_FAILURE);
    }
  return 0;
}

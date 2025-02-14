#pragma once

//Libraries
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip> //This is used for the display/output


using namespace std;

class Proposition
{
private:
    int partCount;
    int variableCount;
    int colCount;
    int rowCount;
    int** array;
    string charArray;
    wstring origString;

    void characterSwap(wstring equation) { //Use Switch instead of if statments
        int tempChar;
        int i = 0;
        while (i < equation.size()) {
            tempChar = (int)equation[i];
                                   //LogicOperator   DisplayOperator    CodeOperator
            if (tempChar == 8743) {//  ∧    *    &&
                equation[i] = '*';
            }
            if (tempChar == 8744) {//  V    +    ||
                equation[i] = '+';
            }
            if (tempChar == 8853 || tempChar == 10753) {//  ⨁    ^    XOR
                equation[i] = '^';
            }
            if (tempChar == 172 || tempChar == 126 ) {// ~    
                equation[i] = '~';
            }
            if (tempChar == 8801) {// ≡    ====
                equation.erase(i,1);
                equation.insert(i, 4, '=');
            }
            if (tempChar == 8594) {// →    ->    
                equation[i] = '-';
                equation.insert(i+1, 1, '>');
                i++;
            }
            if (tempChar == 8596) {// ↔    <->    
                equation[i] = '<';
                equation.insert(i+1, 1, '-');
                equation.insert(i+2, 1, '>');
                i++; i++;
            }
        i++;
        }
        /*Testing Only*/ wcout << equation << endl;
    }
    int numberOfVariables(wstring equation) {
        int i = 0;
        char tempChar;  //wchar_t tempChar;
        bool addChar;
        while (i<equation.size()){                  //Reviewing each character of the string.
            tempChar = equation[i];
            if( ((int)tempChar >= 97 && (int)tempChar <= 122)/*a-z*/   ||  ((int)tempChar >= 65 && (int)tempChar <= 90)/*A-Z*/  ){
                addChar = true;
                for (int j = 0; j <= charArray.size(); j++) {  //Checking for unique chars
                    if (tempChar == charArray[j]){
                        addChar = false;
                        break;
                    }
                }
                if (addChar == true) {
                    charArray.push_back(tempChar);    //Adding Char
                    /*Testing*/ wcout << tempChar << " : " << (int)tempChar << " : " << charArray.size() << " : " << endl;
                } 
            }//End if for a-Z
            i++;
        }
        return charArray.size();
    }

    void buildingArray(int cols, int rows) {
        for (int i = 0; i < rows; ++i) {
            array[i] = new int[cols];
        } 
    }

    void assignVariableValues() { // Assigning the Base Variables Values 
        bool flippingValue;
        int flippingRow = rowCount;

        int i = 0; int row;
        while (i<(variableCount)) {//All Varaiable Columns
            if (flippingRow < 1) { flippingRow = 1; }
            row = 0;
            while (row<rowCount) { //All Rows Needed in columns
                int j = 0;
                flippingValue = 1;  //True
                while (j < (flippingRow / 2) || (flippingRow == 1 && j < flippingRow)) {  //First half
                    array[i][row] = flippingValue;
                    //cout << array[i][row] << endl;//Testing Purpose
                    j++; row++;
                }

                flippingValue = 0;  //False
                while (j < flippingRow || (flippingRow == 1 && j == flippingRow)) {  //Second half
                    array[i][row] = flippingValue;
                    //cout << array[i][row] << endl;//Testing Purpose
                    j++;  row++;
                }
            }

            flippingRow = flippingRow / 2;
            i++;
        }
    }

public:
    
    Proposition(wstring equation) { //Constructor

        origString = equation;
        characterSwap(equation);
        variableCount = numberOfVariables(equation);
        partCount = 3;
        colCount = partCount + variableCount;
        rowCount = pow(2, variableCount); // 2 ^ variableCount;  
        array = new int* [rowCount];        //Defining the size of the array
        buildingArray(colCount, rowCount);  //Building Array
        assignVariableValues();

	}
    ~Proposition() {//Deconstructor

    }

    int fRowCount()     {return rowCount;}
    int fColCount()     {return colCount;}
    int fPartCount()    {return partCount;}
    int fValCount()     {return variableCount;}
    void fReleaseMemory() {
        //for (int i = 0; i < 3; ++i) {
        //    delete[] array[i];  // Delete each row
        //}
        /*for (int i = 0; i < rowCount; ++i) {
            array[i] = nullptr;
            delete[] array[i];
        }*/
        //delete[] array;
        //array = nullptr;
    }

    //Setting the Value of p
    void displayTruthTable() {
        int i = 1;
        while (i <= colCount) {//Column Names
            cout << setw(10) << " Column" << i;
            i++;
        }
        i = 1; cout << endl;
        while (i <= colCount) {//Line Separator
            cout << setw(11) << "-------";
            i++;
        }
        i = 0; cout << endl;
        while (i<rowCount) {
            int j = 0;
            while (j<variableCount){
                cout << setw(11) << array[j][i];
                j++;
            }
            cout << endl;
            i++;
        }
        cout << "\n The End \n";
    }

};


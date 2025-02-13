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
    int** array;// = new int* [rowCount];
    char charArray[];

    string characterSwap(string equation) {
        for (char& c : equation) {
            cout << (int)c << endl;
        }
        cout << equation.size() << endl;
        return equation;
    }
    int numberOfVariables(wstring equation) {
        int count = 0;
        int i = 0;
        wchar_t tempChar;
        bool addChar;
        //charArray = new char[2];
        while (i<equation.size()){                  //Reviewing each character of the string.
            tempChar = equation[i];
            if( ((int)tempChar >= 97 && (int)tempChar <= 122)/*a-z*/   ||  ((int)tempChar >= 65 && (int)tempChar <= 90)/*A-Z*/  ){
                addChar = true;
                for (int j = 0; j <= count; j++) {  //Checking for unique chars
                    if (tempChar == charArray[j]){
                        addChar = false;
                        break;
                    }
                }
                if (addChar == true) {
                    charArray[count] = tempChar;    //Adding Char
                    count++;                        //Character count
                    /*Testing*/wcout << tempChar << " : " << (int)tempChar << " : " << charArray[count-1] << " : " << endl;
                }  
            }
            i++;
        }
        
        //cout << "Something went wrong \n";
        return count;
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
    
    Proposition(string equation) { //Constructor

        if (equation == "Equation1") {
            variableCount = numberOfVariables(L"(p∨q)∧(p∧q)⨁r"); //Something goes wrong in the memory when Variables 4+  

            partCount = 3;
            colCount = partCount + variableCount;
            rowCount = pow(2, variableCount); // 2 ^ variableCount;  
            array = new int* [rowCount];
            buildingArray(colCount, rowCount);
            assignVariableValues();
        }else
        if (equation == "Equation2") {
            partCount = 3;
            variableCount = 2;
            colCount = partCount + variableCount;
            rowCount = pow(2, variableCount);;
        }else
        if (equation == "Equation3") {
            partCount = 5;
            variableCount = 3;
            colCount = partCount + variableCount;
            rowCount = pow(2, variableCount);;
        }else
        if (equation == "Equation4") {
            partCount = 5;
            variableCount = 3;
            colCount = partCount + variableCount;
            rowCount = pow(2, variableCount);;
        }else
        {
            partCount = 0;
            variableCount = 0;
            colCount = partCount + variableCount;
            rowCount = pow(2, variableCount);;
        }


       
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
        for (int i = 0; i < rowCount; ++i) {
            array[i] = nullptr;
            delete[] array[i];
        }
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


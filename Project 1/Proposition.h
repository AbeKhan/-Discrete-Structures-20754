#pragma once

//Libraries
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>  //This is used for the display/output
#include <locale>   //Testing for Unicode accepting chars :


using namespace std;

class Proposition
{
private:
    int partCount;                      //How many parts in the equation ()
    int colCount;                       //Total number of columns in the truth table
    int rowCount;                       //Total number of rows in the truth table
    int** array;                        //The total size of the Truth Table, Also where the answer values are stored
    string charArray;                   //Unique CHARs of variables p, q, r, etc...
    string displayEquation;             //Building the string for display, Idk if this is needed.
    string evaluateEquation;            //Building the string to be evaluated, Idk if this is needed.

    string* equPartArray;//Testing

    void parseString(wstring equation) { //Use Switch instead of if statements
        int tempChar;
        bool addChar;
        int i = 0;
        while (i < equation.size()) {
            tempChar = (int)equation[i];

            switch (tempChar)                                   //LogicOperator   DisplayOperator    CodeOperator
            {
            case 8743:                                          //  ∧    *    &&
                displayEquation.push_back('*');
                evaluateEquation = evaluateEquation + "&&";
                break;
            case 8744:                                          //  V    +    ||
                displayEquation.push_back('+');
                evaluateEquation = evaluateEquation + "||";
                break;
            case 8853: case 10753:                              //  ⨁    ^    XOR
                displayEquation.push_back('^');
                evaluateEquation = evaluateEquation + "XOR";
                break;
            case 126:                           
            case 172:                                           //  ~
                displayEquation.push_back('~');
                evaluateEquation.push_back('~');                //not sure what to put here yet.
                break;
            case 8801:                                          //  ≡    ====
                displayEquation = displayEquation + "====";
                evaluateEquation = evaluateEquation + "==";     //not sure what to put here yet.
                break;
            case 8594:                                          //  →    ->
                displayEquation = displayEquation + "->";
                evaluateEquation = evaluateEquation + "<=";     //Not Sure
                break;
            case 8596:                                          //  ↔    <->
                displayEquation = displayEquation + "<->";
                evaluateEquation = evaluateEquation + ">=";     //Not Sure
                break;
            case 40:
                partCount++;
            default:
                displayEquation.push_back(equation[i]);
                evaluateEquation.push_back(equation[i]);
                break;
            }
            if (((int)tempChar >= 97 && (int)tempChar <= 122)/*a-z*/ || ((int)tempChar >= 65 && (int)tempChar <= 90)/*A-Z*/) {
                addChar = true;
                for (int j = 0; j <= charArray.size(); j++) {  //Checking for unique chars
                    if (tempChar == charArray[j]) {
                        addChar = false;
                        break;
                    }
                }
                if (addChar == true) {
                    charArray.push_back(tempChar);    //Adding Char
                    //wcout << tempChar << " : " << (int)tempChar << " : " << charArray.size() << " : " << endl;      /*Testing*/ 
                }
            }//End if for a-Z
        //cout << displayEquation << endl << evaluateEquation << endl; /*Testing Only*/
        i++;
        }
        if ((int)equation[0] != 40) {   //This is the final check for number of parts.
            partCount++;
        }

        //wcout << equation << endl; /*Testing Only*/ 
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
        while (i<(charArray.size())) {//All Variable Columns
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

    string defineEquationParts(string equPart, int count /*Recursion*/) {
        int loopCount = 0;
        bool skip;
        int i = 1;
        while (loopCount < equPart.size())
        {
            skip = false;
            if (equPart[loopCount] == '(') {        //Down the rabbit trail
                /*cout << equPart.substr(loopCount+1) << endl;*/     /*Testing Only*/
                equPartArray[count] = equPartArray[count] + "(" + defineEquationParts(equPart.substr(loopCount + 1), count + i);
                /*I wonder if I can get the '(' to be apart of the level below string?*/
                i++;
                skip = true;
                loopCount = equPartArray[count].size();
            }
            if (equPart[loopCount] == ')')          //UP the rabbit trail
            {
                equPartArray[count] = equPartArray[count] + equPart[loopCount];
                return equPartArray[count];
            } 
            if (skip != true) {                     //Building the rabbit trail
                equPartArray[count] = equPartArray[count] + equPart[loopCount];
                loopCount++;
            }
            //cout << equPartArray[count] << endl;    /*Testing Only*/
        }
        return (equPartArray[count]);
    } 

    int evaluateEquation(string equPart, int Column /*Recursion*/) {
        int loopCount = 0;
        bool skip;
        int i, j, k;    i = 1;/*EquaPart & Column*/  j = 1;/*Row*/  k = 1/*Column*/;
        while (loopCount < equPart.size())
        {
            j = 0;
            while (true)
            {
                
            } 
            //skip = false;
            //if (equPart[loopCount] == '(') {        //Down the rabbit trail
            //    array[][] = defineEquationParts(equPart.substr(loopCount + 1), count + i);
            //    i++;
            //    skip = true;
            //    loopCount = equPartArray[count].size();
            //}
            //if (equPart[loopCount] == ')')          //UP the rabbit trail
            //{
            //    array[][] = equPartArray[count] + equPart[loopCount];
            //    return 1;
            //}
            //if (skip != true) {                     //Building the rabbit trail
            //    array[][] = equPartArray[count] + equPart[loopCount];
            //    loopCount++;
            //}
            //cout << equPartArray[count] << endl;    /*Testing Only*/

            loopCount++;
        }
        return array[][]; //Default?
    }

    int evaluateEquation(string equPart) { //str.find(ch);
        int loopCount = 0;
        bool tempAnswer;

        while (loopCount < rowCount) {  //Going through each row
            
            if (
                ((int)equPart[loopCount] >= 97 && (int)equPart[loopCount] <= 122)/*a-z*/ || ((int)equPart[loopCount] >= 65 && (int)equPart[loopCount] <= 90)/*A-Z*/) {
               
                for (int j = 0; j <= charArray.size(); j++) {  //Checking for unique chars
                    if (equPart[loopCount] == charArray[j]) {
                        tempAnswer = array[loopCount][charArray.find(charArray[j])];
                        cout << charArray[j] << " has value of : " << tempAnswer << endl; /*Testing Only*/
                        break;
                    }
                }
            }

        }


        while (loopCount < equPart.size()) {

        }

        return 1; //IDK
    }


public:
    
    Proposition(wstring equation /*Constructor*/) {
        parseString(equation);                          /*Going through String, building the strings 'displayEquation', 'evaluateEquation' */
        partCount;                                      /*How many to parts of the equation*/
        colCount = partCount + charArray.size();
        rowCount = pow(2, charArray.size());            //Setting number of rows in true table 2 ^ variableCount;  
        array = new int* [rowCount];                    //Defining the size of the array
        buildingArray(colCount, rowCount);              //Building Array - only the variable columns    
        assignVariableValues();
        equPartArray = new string[partCount];
        defineEquationParts(displayEquation, 0);

	}
    ~Proposition() {}                                   /*Deconstructor*/
    int fRowCount()     {return rowCount;}              //Retunring number of rows in true table       
    int fColCount()     {return colCount;}              //Returning number of columns in truth table
    int fPartCount()    {return partCount;}             //Returning number of equation parts ()
    int fValCount()     {return charArray.size();}      //Returning number of unique chars in equation.
    void fReleaseMemory(/*Not working*/) {
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

    void displayTruthTable(/*Displaying the truth table, Only half complete.*/) {
        int varCount = charArray.size();
        
        //while (i <= colCount) {//Column Names
        //    cout << setw(10) << " Column" << i;
        //    i++;
        //}
        int i = 0;
        while (i <= charArray.size()) {
            cout << setw(8) << charArray[i];
            i++;
        }
        i = 1;
        while (i < partCount){
            cout << setw(8) << equPartArray[i];
            i++;
        }
        cout << setw(8) << equPartArray[0] << endl;

        i = 1; cout << endl;
        while (i <= colCount) {//Line Separator
            cout << setw(8) << "-------";
            i++;
        }
        i = 0; cout << endl;
        while (i<rowCount) {
            int j = 0;
            while (j< varCount){ //This will change
                cout << setw(8) << array[j][i];
                j++;
            }
            cout << endl;
            i++;
        }
        cout << "\n The End \n";
    }

};

 
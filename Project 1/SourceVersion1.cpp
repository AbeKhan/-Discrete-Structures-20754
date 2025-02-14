/**
* Abrham & Justin
* Discrete Structures
* Group Project 1
* 2025-02-09
*/

//Libraries

#include <iostream>
#include <string>
//#include <locale> //Testing for Unicode accepting chars : 
                 //handle the output correctly, you may need to set the locale to one that supports Unicode.

//Header Files
#include "Proposition.h"

using namespace std;
int main() {

    //u32string equationTest = U"(𝑝∨𝑞)∧(𝑝∧𝑞)⨁";
    Proposition equationTest(L"~(𝑝∨𝑞)∧(𝑝∧𝑞)⨁");
  
    /*
    Proposition equation1(L"(p∨q)∧(~p∧~q)");
    Proposition equation2(L"(p↔q)→(~p↔~q)");
    Proposition equation3(L"(p∨q)∧(~p∨r)→(p∧r)");
    Proposition equation4(L"((p→r)→q)↔(p→(q→r))");
    */

    //equation4 = characterSwap(equation1);
    Proposition equation1(L"");
    equationTest.displayTruthTable();
    equationTest.fReleaseMemory(); //Not working

   
    return 0;
}
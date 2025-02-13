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
    /*
    ∧   *           V   +          ~
    ⨁   ^           →   ->         ↔   <->
    ≡   ====        T   1          F    0
    */

    //char32_t ch = U'𐍈'; // Example Unicode character beyond BMP
    //int unicodeValue = static_cast<int>(ch);

    //Not working std::setlocale(LC_ALL, "");
    //Not working std::wcout.imbue(std::locale(""));
    //u32string equationTest = U"(𝑝∨𝑞)∧(𝑝∧𝑞)⨁";
    //wstring equationTest = L"~(𝑝∨𝑞)∧(𝑝∧𝑞)⨁";
    //wcout << static_cast<int>(equationTest[6]) << endl;
    //if (equationTest[10] = "∧") { cout << "Match" << endl; }



    //equation4 = characterSwap(equation1);
    Proposition equation1("Equation1");
    equation1.displayTruthTable();
    equation1.fReleaseMemory(); //Not working

   
    return 0;
}
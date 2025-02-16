#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>

using namespace std;

void proposition(int input);                             // Forward declaration of proposition
void printTruthTable(int input, bool p, bool q, bool r); // Forward declaration of printTruthTable

int main()
{
    int input;
    cout << "Which expression would you like to see?" << endl;
    cout << "1: (p ⋁ q) ⋀ (¬p ⋀ ¬q)" << endl;
    cout << "2: (p ↔ q) → (¬p ↔ ¬q)" << endl;
    cout << "3: (p ⋁ q) ⋀ (¬p ⋀ r) → (p ⋀ r)" << endl;
    cout << "4: ((p → r) → q) ↔ (p → (q → r))" << endl; // Fixed extra parenthesis

    cin >> input;

    proposition(input); // Call the function to evaluate the expression

    return 0;
}

void proposition(int input)
{
    bool p, q, r, result;

    switch (input)
    {
    case 1:
    //(p ⋁ q) ⋀ (¬p ⋀ ¬q)
        for (int i = 0; i <= 1; i++)
        {
            p = i;
            for (int ii = 0; ii <= 1; ii++)
            {
                q = ii;
                result = (p || q) && (!p && !q); // Changed '==' to '='

                cout << "This is the result: " << result << endl;
            }
        }
        break;
    case 2:
    //(p ↔ q) → (¬p ↔ ¬q)
        for (int i = 0; i <= 1; i++)
        {
            p = i;
            for (int ii = 0; ii <= 1; ii++)
            {
                q = ii;
                bool p_iff_q = (p == q);
                bool not_p_iff_not_q = (!p == !q);
                result = !p_iff_q || not_p_iff_not_q;

                cout << "Value of P: " << p << " Value of Q: " << q << endl;
                cout << "Value of p_iff_q: " << p_iff_q << " not_p_iff_not_q: " << not_p_iff_not_q << endl;
                cout << "This is the result: " << result << endl
                     << endl;
            }
        }
        break;
    case 3:
    //(p ⋁ q) ⋀ (¬p ⋀ r) → (p ⋀ r)
        for (int i = 0; i <= 1; i++)
        {
            p = i;
            for (int ii = 0; ii <= 1; ii++)
            {
                q = ii;
                for (int iii = 0; iii <= 1; iii++)
                {
                    r = iii;

                    
                    //(p || q) && (!p && r) || (p && r)
                }
            }
        }
        break;
    }

    void printTruthTable(int input, bool p, bool q, bool r)
    {
        switch (input)
        {
        case 1:
            cout << "Check truth value for: (p ⋁ q) ⋀ (¬p ⋀ ¬q)" << endl; // Fixed typo "balue" to "value" and added endl
            break;
        // Add cases for other expressions as needed
        default:
            cout << "Invalid input" << endl;
            break;
        }
    }

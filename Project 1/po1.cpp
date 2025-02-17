#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>

using namespace std;

void proposition(int input);
void printTruthTable(int input, bool p, bool q, bool r);

int main()
{
    int input;
    cout << "Which expression would you like to see?" << endl;
    cout << "1: (p ⋁ q) ⋀ (¬p ⋀ ¬q)" << endl;
    cout << "2: (p ↔ q) → (¬p ↔ ¬q)" << endl;
    cout << "3: (p ⋁ q) ⋀ (¬p ⋀ r) → (p ⋀ r)" << endl;
    cout << "4: ((p → r) → q) ↔ (p → (q → r))" << endl;

    cin >> input;

    proposition(input);

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
                result = (p || q) && (!p && !q);

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
                result = !(p_iff_q) || not_p_iff_not_q;

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

                    bool p_or_q = (p || q);
                    bool notp_and_r = (!p && r);
                    bool part1 = p_or_q && notp_and_r;
                    bool part2 = (p && r);

                    result = !(part1) || part2;

                    cout << "This is the result: " << result << endl;
                }
            }
        }
        break;

    case 4:
        //((p → r) → q) ↔ (p → (q → r))
        for (int i = 0; i <= 1; i++)
        {
            p = i;
            for (int ii = 0; ii <= 1; ii++)
            {
                q = ii;
                for (int iii = 0; iii <= 1; iii++)
                {
                    r = iii;

                    // Evaluate part 1: ((p → r) → q)
                    bool if_p_then_r = !p || r;
                    bool part1 = !if_p_then_r || q;

                    // Evaluate part 2: (p → (q → r))
                    bool if_q_then_r = !q || r;
                    bool part2 = !p || if_q_then_r;

                    // Equivalence check
                    result = (part1 == part2);

                    //cout << "part1: " << part1 << " part2: " << part2 << endl;
                    cout << "p: " << p << " q: " << q << " r: " << r << endl;
                    cout << "This is the result: " << result << endl;
                }
            }
        }
        break;
    }
}
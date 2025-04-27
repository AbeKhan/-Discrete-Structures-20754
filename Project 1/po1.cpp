/**
* Abraham & Justin
* Discrete Structures
* Group Project 1
* Group #13
* 2025-02-16
*/
#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;
void proposition(int input);                             // Forward declaration of proposition
string tableEvaluation(int trueCount, int rowCount);     // conclusion of expression

int main() {
    int input;
    cout << "Which expression would you like to see?" << endl;
    cout << "1: (p ⋁ q) ⋀ (¬p ⋀ ¬q)" << endl;
    cout << "2: (p ↔ q) → (¬p ↔ ¬q)" << endl;
    cout << "3: (p ⋁ q) ⋀ (¬p ⋀ r) → (p ⋀ r)" << endl;
    cout << "4: ((p → r) → q) ↔ (p → (q → r))" << endl;
    cin >> input;
    proposition(input); // Call the function to evaluate the expression
    return 0;
}

void proposition(int input) {
    bool p, q, r, result;
    string equation; int trueCount = 0;
    cout << endl;
    switch (input) {
    case 1:
        //(p ⋁ q) ⋀ (¬p ⋀ ¬q)
        equation = "(p+q)*(~p*~q)";
        cout << "Check true value for: " << equation << endl;
        cout << setw(8) << "p" << setw(8) << "q" << setw(10) << "(p+q)" << setw(10) << "(~p*~q)" << setw(15) << equation << endl;
        for (int i = 0; i <= 1; i++) {
            p = i;
            for (int ii = 0; ii <= 1; ii++) {
                q = ii;
                result = (p || q) && (!p && !q); 
                if (result == 1) { trueCount++; }
                cout << setw(8) << p << setw(8) << q << setw(8) << (p || q) << setw(9) << (!p && !q) << setw(12) << result << endl;
            }
        }
        cout << "There are " << trueCount << " true cases." << endl;
        cout << equation << " is a " << tableEvaluation(trueCount, 4) << endl;
        break;
    case 2:
        //(p ↔ q) → (¬p ↔ ¬q)
        equation = "(p<->q)->(~p<->~q)";
        cout << "Check true value for: " << equation << endl;
        cout << setw(8) << "p" << setw(8) << "q" << setw(10) << "(p<->q)" << setw(10) << "(~p<->~q)" << setw(20) << equation << endl;
        for (int i = 0; i <= 1; i++) {
            p = i;
            for (int ii = 0; ii <= 1; ii++) {
                q = ii;
                bool p_iff_q = (p == q);
                bool not_p_iff_not_q = (!p == !q);
                result = !p_iff_q || not_p_iff_not_q;
                if (result == 1) { trueCount++; }
                cout << setw(8) << p << setw(8) << q << setw(7) << p_iff_q << setw(9) << not_p_iff_not_q << setw(15) << result << endl;
            }
        }
        cout << "There are " << trueCount << " true cases." << endl;
        cout << equation << " is a " << tableEvaluation(trueCount, 4) << endl;
        break;
    case 3:
        //(p ⋁ q) ⋀ (¬p ⋀ r) → (p ⋀ r)
        equation = "(p+q)*(~p*r)->(p*r)";
        cout << "Check true value for: " << equation << endl;
        cout << setw(8) << "p" << setw(8) << "q" << setw(8) << "r"
            << setw(10) << "(p+q)" << setw(10) << "(~p*r)" << setw(10) << "(p*r)" << setw(15) << "(p+q)*(~p*r)" << setw(23) << equation << endl;
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
                    //(p ⋁ q) ⋀ (¬p ⋀ r)
                    bool part1 = p_or_q && notp_and_r;
                    bool part2 = (p && r);

                    result = !(part1) || part2;
                    if (result == 1) { trueCount++; }
                    cout << setw(8) << p << setw(8) << q << setw(8) << r
                        << setw(8) << p_or_q << setw(10) << notp_and_r << setw(10) << part1 << setw(11) << part2 << setw(18) << result << endl;
                }
            }
        }
        cout << "There are " << trueCount << " true cases." << endl;
        cout << equation << " is a " << tableEvaluation(trueCount, 4) << endl;
        break;
    case 4:
        equation = "((p->r)->q)<->(p->(q->r))";
        cout << "Check true value for: " << equation << endl;
        cout << setw(8) << "p" << setw(8) << "q" << setw(8) << "r"
            << setw(10) << "(p->r)" << setw(15) << "((p->r)->q)" << setw(10) << "(q->r)" << setw(15) << "(p->(q->r))" << setw(28) << equation << endl;
        for (int i = 0; i <= 1; i++) {
            p = i;
            for (int ii = 0; ii <= 1; ii++) {
                q = ii;
                for (int iii = 0; iii <= 1; iii++) {
                    r = iii;

                    // Evaluate part 1: ((p → r) → q)
                    bool if_p_then_r = !p || r;
                    bool part1 = !if_p_then_r || q;

                    // Evaluate part 2: (p → (q → r))
                    bool if_q_then_r = !q || r;
                    bool part2 = !p || if_q_then_r;

                    // Equivalence check
                    result = (part1 == part2);
                    if (result == 1) { trueCount++; }
                    cout << setw(8) << p << setw(8) << q << setw(8) << r
                        << setw(8) << if_p_then_r << setw(12) << part1 << setw(13) << if_q_then_r << setw(12) << part2 << setw(21) << result << endl;
                }
            }
        }
        cout << "There are " << trueCount << " true cases." << endl;
        cout << equation << " is a " << tableEvaluation(trueCount, 4) << endl;
        break;
    }
}
string tableEvaluation(int trueCount, int rowCount) {
    if (trueCount == rowCount) {
        return "tautology.";
    }
    else if (trueCount == 0)
    {
        return "contradiction.";
    }
    else {
        return "contingency.";
    }
}
// Group 13
// ----------------------------------------------
// Author(s):   Abraham Khan        &&      Justin Stevenson
// Email(s):    Akhan33@uco.edu     &&      Jstevenson19@uco.edu
// ----------------------------------------------

#include <iostream>
using namespace std;

// Function to calculate GCD using Euclidean Algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;

        
    }
    return a;
}

// Function to find the modular inverse using Extended Euclidean Algorithm
int modInverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;

    if (gcd(a, m) != 1) {
        cout << "Inverse doesn't exist!\n";
        return -1;
    }

    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m;
        a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    return (x1 + m0) % m0;
}

// Function to solve linear congruence ax ≡ b (mod m)
void solveCongruence(int a, int b, int m) {
    int inverse = modInverse(a, m);
    if (inverse != -1) {
        int x = (inverse * b) % m;
        //cout << "Solution: x ==== " << x << " (mod " << m << ")\n";
        cout << "The solution for " << a << "x===" << b << "(mod" << m << ") is x===" << x << "(mod" << m << ")\n";
    }
}

int main(int argc, char* argv[]) {
    int a, b, m, choice;

    // cout << "Choose operation:\n";
    // cout << "1. Compute GCD\n";
    // cout << "2. Find modular inverse\n";
    // cout << "3. Solve linear congruence\n";
    // cout << "Enter choice: ";

    // cout << "Enter choice: ";
    // cin >> choice;
    //     if (choice == 1) {
    //         cout << "Enter two positive integers: ";
    //         cin >> a >> b;
    //         cout << "GCD(" << a << ", " << b << ") = " << gcd(a, b) << endl;
    //     }
    //     else if (choice == 2) {
    //         cout << "Enter integer a and modulus m: ";
    //         cin >> a >> m;
    //         //cout << "Modular inverse of " << a << " mod " << m << " is " << modInverse(a, m) << endl;
    //         cout << modInverse(a, m) << " is the inverse of " << a << " modulo " << m << endl;
    //     }
    //     else if (choice == 3) {
    //         cout << "Enter integers a, b and modulus m: ";
    //         cin >> a >> b >> m;
    //         solveCongruence(a, b, m);
    //     }
    //     else {
    //         cout << "Invalid choice!\n";
    //     }

    /*
    This is to test the command line arguments.
    Uncomment the following lines to see the arguments passed to the program.
    
     cout << "Number of arguments: " << argc << endl;
     for (int i = 0; i < argc; i++) {
         cout << "Argument " << i << ": " << argv[i] << endl;
     }
    */


    choice = atoi(argv[1]);

    if (choice == 1) {
       // cout << "Enter two positive integers: ";
        //cin >> a >> b;
        a = atoi(argv[2]);
        b = atoi(argv[3]);
        cout << "gcd(" << a << ", " << b << ") = " << gcd(a, b) << endl;
    }
    else if (choice == 2) {
       // cout << "Enter integer a and modulus m: ";
        //cin >> a >> m;
        a = atoi(argv[2]);
        m = atoi(argv[3]);
        //cout << "Modular inverse of " << a << " mod " << m << " is " << modInverse(a, m) << endl;
        cout << modInverse(a, m) << " is the inverse of " << a << " modulo " << m << endl;
    }
    else if (choice == 3) {
       // cout << "Enter integers a, b and modulus m: ";
       // cin >> a >> b >> m;

        a = atoi(argv[2]);
        b = atoi(argv[3]);
        m = atoi(argv[4]);
        solveCongruence(a, b, m);
    }
    else {
        cout << "Invalid choice!\n";
    }


    return 0;
}
#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

#define PLUS    0
#define MINUS   1
#define TIMES   2
#define DIVIDE  3

double operate(double a, double b, int op);
bool next_choice(int *);

int main() {
    int digits[4] = {0, 1, 2, 3};
    int maximum = 0;
    string maxString = "";

    // Loop over each range of digits such that a < b < c < d
    do {
        set<int> result{};

        // Loop through each permutation of the digits
        do {
            int ops[3] = {PLUS, PLUS, PLUS};

            // Cycle through each possible set of operations
            for (int i = 0; i < 64; i++) {

                // Case 1: Balanced binary tree (digits are leaves)
                double t = operate((double)digits[0], (double)digits[1], ops[0]);
                t = operate(t, (double)digits[2], ops[1]);
                t = operate(t, (double)digits[3], ops[2]);

                if (floor(t) == t && t > 0)
                    result.insert((int)t);

                // Case 2: Imbalanced binary tree (only one structural imbalanced tree)
                double s = operate((double)digits[0], (double)digits[1], ops[0]);
                t = operate((double)digits[2], (double)digits[3], ops[2]);
                t = operate(s, t, ops[1]);

                if (floor(t) == t && t > 0)
                    result.insert((int)t);

                ops[0]++;
                for (int j = 0; j < 3; j++) {
                    if (ops[j] > DIVIDE) {
                        ops[j] = 0;
                        if (j < 2) ops[j+1]++;
                    }
                }
            }
        } while (next_permutation(digits, digits + 4));

        // Determine the maximum run
        int last = 0;
        for (auto& i : result) {
            if (i != last + 1) break;
            last = i;
        }

        // Check if we've exceeded the maximum
        if (last > maximum) {
            maximum = last;
            maxString = "";
            for (int i = 0; i < 4; i++)
                maxString += to_string((int)digits[i]);
        }
    } while ( next_choice(digits) );

    cout << "Result: " << maxString << " (1 through " << maximum << ")" << endl;
}

bool next_choice(int *digits) {
    if (digits[0] == 6) {
        for (int i = 0; i < 4; i++)
            digits[i] = i;
        return false;
    }
    else if (digits[1] == 7) {
        digits[0]++;
        for (int i = 1; i < 4; i++)
            digits[i] = digits[i-1] + 1;
    }
    else if (digits[2] == 8) {
        digits[1]++;
        digits[2] = digits[1] + 1;
        digits[3] = digits[2] + 1;
    }
    else if (digits[3] == 9) {
        digits[2]++;
        digits[3] = digits[2] + 1;
    }
    else {
        digits[3]++;
    }

    return true;
}

double operate(double a, double b, int op) {
    switch (op) {
        case PLUS:  return a + b;
        case MINUS: return a - b;
        case TIMES: return a * b;
    }
    return a / b;
}

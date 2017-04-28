#include "../lib/euler.hpp"
#include <iostream>
#include <vector>
using namespace std;

int score(int a, int b, vector<bool> s) {
    int n = 0;
    int eval = n*n + a*n + b;

    while (eval > 2 && eval < 1e6 && !s[eval - 2]) {
        ++n;
        eval = n*n + a*n + b;
    }
    return n;
}

int main() {
    const int N = 1000000, n = 1000;
    vector<bool> s = sieve(N);
    int max_ = 0, maxab = 0;
    for (int a = -n+1; a < 0; ++a) {
        for (int b = 0; b < n; ++b) {
            if (score(a, b, s) > max_) {
                max_ = score(a, b, s);
                maxab = a*b;
                cout << "New max a = " << a << " b = " << b <<
                " with n = " << max_ << endl;
            }   
        }
    }
    cout << maxab << endl;
}

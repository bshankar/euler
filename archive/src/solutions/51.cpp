#include "../lib/euler.hpp"
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int primeSet(int prime, vector<bool>& s) {
    // len
    string pr = to_string(prime);
    int max_len = 0;
    int prsize = pr.size();
    for (int j = 0; j < prsize; ++j) {
        int len = 0; // length of prime chain
        for (int k = 0; k < 10; ++k) {
            string old = pr;
            char a = pr[j];
            replace(pr.begin(), pr.end(), a, char(k + '0'));
            if (stoi(pr) > 1 && !s[stoi(pr) - 2] && pr[0] - '0') {
                ++len;
            }
            pr = old;
        }
        if (len > max_len)
            max_len = len;
    }
    return max_len;
}

int main() {
    int N = 1000000;
    vector<bool> s = sieve(N);
    for (int i = 2; i < N; ++i) {
        if (s[i-2]) continue;
        int len = primeSet(i, s);
        if (len == 8) {
            cout << i << endl;
            return 0;
        }
    }
}

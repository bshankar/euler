#include <iostream>
#include <vector>
#include "../lib/euler.hpp"
using namespace std;
typedef unsigned long ul;

int main() {
    vector<bool> v = sieve(1000); // primes below 1000 ??
    ul k = 650;
    int seq = 0;
    while (1) {
        int dpd = 0;
        for (int i = 0; i < v.size(); ++i) {
            if (v[i]) continue;
            ul p = i+2;
            if (k % p == 0) ++dpd;
        }
        if (dpd == 4) 
            ++seq;
        else 
            seq = 0;
        
        if (seq == 4) {
            cout << k-3 << endl;
            break;
        }
        ++k;
    }
}

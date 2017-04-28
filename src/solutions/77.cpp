#include <iostream>
#include "../lib/euler.hpp"
#include <vector>
using namespace std;

int main() {
    int N = 100;
    vector<bool> s = sieve(N);
    vector<int> primes; // primes below N
    for (int i = 0; i < N; ++i) {
        if (!s[i])
            primes.push_back(i+2);
    }
    
    
    int pp[N][N] = {};
    for (int i = 0; i < N; ++i)
        pp[0][i] = 1;
        
    for (int i = 2; i < N; ++i) {
        for (int j = 0; j < primes.size(); ++j) {
            if (i < primes[j]) {
                pp[i][j] = pp[i][j-1];
                continue;
            }
            pp[i][j] = pp[i-primes[j]][j] + pp[i][j-1];
            if (pp[i][j] > 5000) {
                cout << i << " " << pp[i][j] << endl;
                return 0;
            }
        }
    }
}

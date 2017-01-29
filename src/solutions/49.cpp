#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "../lib/euler.h"
using namespace std;

int main() {
    int N = 10000;
    vector<bool> s = sieve(2*N);
    vector<int> primes; // all 4 digit primes
    vector<string> sPrimes; // sorted
    for (int i = 1001; i < N; ++i) {
        if (s[i]) continue;
        int pr = i+2;
        primes.push_back(pr);
    }
    
    for (int i = 0; i < primes.size(); ++i) {
        string prStr = to_string(primes[i]);
        sort(prStr.begin(), prStr.end());
        sPrimes.push_back(prStr);
    }
    
    for (int i = 0; i < primes.size(); ++i)
        for (int j = i+1; j < primes.size(); ++j)
            if (sPrimes[i] == sPrimes[j]) {
                int diff = primes[j] - primes[i];
                int prime3 = primes[j] + diff;
                string prime3Str = to_string(prime3);
                sort(prime3Str.begin(), prime3Str.end());
                if (!s[prime3 - 2] && prime3 < N && sPrimes[i] == prime3Str)
                    cout << primes[i] << " " << primes[j] << " "
                    << primes[j] + diff << endl;
            }
}

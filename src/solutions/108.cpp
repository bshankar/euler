#include "../lib/euler.h"
using namespace std;
typedef unsigned long ul;

// Guess a limit till we test
#define N 200000

int main() {
    // Little calculation shows no of solutions to
    // 1/x + 1/y = 1/n is equal to ceil(d(n^2)/2)
    // where d is no of divisors function
    int divisors[N+1] = {}; // number of divisors of n^2
    vector<int> primes = segmented_sieve((int) sqrt(N)+1);
    divisors[1] = 1;

    for (int n = 2; n < N; ++n) {
        for (auto i = 0; i < primes.size(); ++i) {
            if (n == primes[i]) {
                divisors[n] = 3;
                continue;
            }

            int n_ = n, pow = 0;
            while (n_ % primes[i] == 0) {
                n_ /= primes[i];
                pow++;                 
            }
            divisors[n] = divisors[n_]*(2*pow+1);
            if ((divisors[n]+1)/2 > 1000) {
                cout << n << endl;
                return 0;
            }
            // done computing
            if (divisors[n]) break;
        }
        if (!divisors[n]) 
            // its a prime
            divisors[n] = 3;
    }
}

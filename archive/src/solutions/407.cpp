#include "../lib/euler.hpp"
#include "vector_utils.hpp"
using namespace std;

int main() {
    const ul N = 10000000;
    vector<ul> primes = segmented_sieve(N);
    vector<ul> M(N + 1);

    for (auto prime: primes) {
        ul prime_pow = prime;
        while (prime_pow <= N) {
            M[prime_pow] = 1;
            prime_pow *= prime;
        }
    }

    for (auto n = 2; n <= N; ++n) {
        if (M[n])
            // already computed
            continue;

        for (auto i = 0; primes[i] < sqrt(n); ++i) {
            ul prime_pow = primes[i];
            while (n % prime_pow == 0 && prime_pow < sqrt(n)) {
                ul a = n/prime_pow;
                if (a + 1 < M[n])
                    // already have a better solution
                    break;

                if (a*(a+1) % n == 0)
                    M[n] = max(a + 1, M[n]);
                else if (a*(a-1) % n == 0)
                    M[n] = max(a, M[n]);
                prime_pow *= primes[i];
            }
        }
    }
    // include the solution for n = 1
    cout << sum(M) + 1 << endl;
}

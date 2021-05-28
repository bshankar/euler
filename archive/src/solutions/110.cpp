#include "../lib/euler.hpp"
using namespace std;
typedef unsigned long ul;

#define N 4000000

int main() {
    // Little calculation shows no of solutions to
    // 1/x + 1/y = 1/n is equal to ceil(d(n^2)/2)
    // where d is no of divisors function
    vector<int> primes = segmented_sieve(100);
    vector<int> pow(100); // power of each prime
    // start with 1260
    ul n = 1260, divisors = 225, next_prime = 11;
    pow[2] = pow[3] = 4;
    pow[5] = pow[7] = 2;

    while ((divisors+1)/2 <= N) {
        ul max_factor = 0,
           max_divisors = divisors;
        for (auto i = 0; primes[i] < next_prime; ++i) {

        }
    }
}

#include "../lib/euler.h"
using namespace std;

const ul N = 33554432;

int main(int argc, char *argv[]) {
    vector<ul> primes = segmented_sieve(N);
    for (auto i = 0; i < primes.size(); ++i)
        // primes now contains the squares of primes
        primes[i] *= primes[i];

    ul square_free = N*N;
    for (auto i = 0; i < primes.size(); ++i)
        square_free -= N*N/primes[i];

    cout << square_free << endl;
}

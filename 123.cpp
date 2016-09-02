#include "prime.h"
using namespace std;
const ul N = 300000; // guess
const ul LB = 10000000000;

int main() {
    vector<ul> primes = segmented_sieve(N);

    for (auto i = 1; i < primes.size(); i += 2)
        if (2 * i * primes[i - 1] > LB) {
            cout << i << endl;
            return 0;
        }
}

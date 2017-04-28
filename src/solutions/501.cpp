#include "../lib/euler.hpp"
#include "vector_utils.hpp"
#include <algorithm>
using namespace std;

const ul N = 1000000000000;
const ul n = N/6 + 1;

int main(int argc, char *argv[]) {
    vector<ul> primes = segmented_sieve(n);
    // factors   powers of each prime
    // ------------------------------
    // 8         7
    // 2 4       1 3
    // 4 2       3 1
    // 2 2 2     1 1 1

    // 7
    ul ans  = lower_bound(primes.begin(), primes.end(),
                          ceil(pow(N, 1.0/7))) + 1 - primes.begin();

    // 1 3
    ul index = 0;
    for (auto i = 0; i < primes.size()-1; ++i)
        if (primes[i]*pow(primes[i+1], 3) > N) {
            index = i - 1;
            break;
        }
    ans += index - 1 + combinations(index - 1, 2);

    // 3 1
    for (auto i = 0; i < primes.size()-1; ++i)
        if (pow(primes[i], 3)*primes[i+1] > N) {
            index = i - 1;
            break;
        }
    ans += index - 1 + combinations(index - 1, 2);

    // 2 2 2
    for (auto i = 0; i < primes.size()-2; ++i)
        if (primes[i]*primes[i+1]*primes[i+2] > N) {
            index = i - 1;
            break;
        }
    ans += combinations(index, 2) + combinations(index, 3);
    cout << ans << endl;
}

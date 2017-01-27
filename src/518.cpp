#include "prime.h"
#include <iostream>
#include <algorithm>
using namespace std;


int main(int argc, char *argv[]) {
    const ul N = 1000000;
    vector<ul> primes = segmented_sieve(N);
    ul ans = 0;

    #pragma omp parallel for reduction(+:ans)
    for (auto i = 0; i < primes.size(); ++i)
        for (auto j = i + 1; j < primes.size(); ++j) {
            ul a = primes[i] + 1,
               b = primes[j] + 1;
            if (b*b % a) continue;
            ul c = b*b/a;
            if (c >= N)
                break;
            if (binary_search(primes.begin(), primes.end(), c-1))
                ans += a + b + c - 3;
        }
    cout << ans << endl;
}

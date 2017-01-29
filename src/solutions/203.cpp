#include "../lib/euler.h"
#include <algorithm>
#include <set>
using namespace std;
typedef unsigned long ul;

#define N 51

int main(int argc, char *argv[]) {
    ul pascal[N+1][N+1] = {};
    set<ul> unique_binomials;
    // initial values of pascal triangle
    for (auto n = 1; n < N; ++n) {
        pascal[n][0] = 1;
        pascal[n][1] = n;
        unique_binomials.insert(n);
    }

    // compute the pascal triangle
    for (auto n = 1; n < N; ++n)
        for (auto k = 2; k <= n; ++k) {
            pascal[n][k] = pascal[n-1][k-1] + pascal[n-1][k];
            unique_binomials.insert(pascal[n][k]);
        }

    ul largest = *max_element(unique_binomials.begin(), 
                              unique_binomials.end());

    vector<ul> primes = segmented_sieve((ul) sqrt(sqrt(largest)));

    for (auto i = 0; i < primes.size(); ++i) {
        for (auto j = unique_binomials.end(); j != unique_binomials.begin();) {
            --j;
            ul p2 = primes[i]*primes[i];
            if ((*j % p2) == 0)
                // contains a prime square
                j = unique_binomials.erase(j);
            else if (p2 > *j)
                break;
        }
    }
    ul ans = 0;
    for (auto b: unique_binomials)
        ans += b;

    cout << ans << endl;
}

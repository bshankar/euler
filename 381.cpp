#include <iostream>
#include "prime.h"
using namespace std;

#define N 100
vector<long> vec(5);

long f(long n, vector<long>& vec) {
    // -1(wilson's theorem), 1, (n-1/2) 
    // (calculate last 2 using
    // extended euclids algorithm)
    long k = (n-1)/2, k_ = (n-2)*(n-3) % n;
    extended_euclid(k_, -n, vec);
    long ans = k + vec[0];
    k_ = k_*(n-4) % n;
    extended_euclid(k_, -n, vec);
    ans += vec[0];
    return ans % n;
}


int main() {
    vector<bool> s = sieve(N);
    long ans = 0;
    for (long i = 5; i < N; ++i) {
        if (s[i-2])
            continue;
        ans += f(i, vec);
    }
    cout << ans << endl;
    cout << f((long) 7, vec) << endl;
}

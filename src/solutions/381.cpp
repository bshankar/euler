#include <iostream>
#include "../lib/euler.h"
using namespace std;

#define N 100000000

long f(long n) {
    // -1(wilson's theorem), 1, (n-1/2) 
    long k = (n-1)/2, k_ = (n-2)*(n-3) % n;
    long ans = k + inverse(k_, n);
    return (ans + inverse(k_*(n-4), n)) % n;
}


int main() {
    vector<bool> s = sieve(N);
    long ans = 0;
    for (long i = 5; i < N; ++i) {
        if (s[i-2])
            continue;
        ans += f(i);
    }
    cout << ans << endl;
}

#include <iostream>
#include <vector>
#include <cmath>
#include "../lib/euler.h"
using namespace std;
typedef unsigned long ul;

#define N 100000001
vector<bool> s_ = sieve(N);

bool isPrimeGenerator(ul n, bool *vec) {
    if (s_[n-1] || s_[n/2])
        return false;

    for (ul i = 3; i < sqrt(n)+1; ++i) {
        if (vec[i])
            continue;
        if (n % i == 0 && s_[i + n/i - 2]) 
                return false;
    }
    return true;
}

int main() {
    ul ans = 1;
    bool *notPossible = new bool[N];
    //should be even and not divisible by a prime square
    for (ul i = 2; i < N; i += 2) {
        if (notPossible[i])
            continue;

        for(ul i2 = i*i; i2 < N; i2 += i*i)
            notPossible[i2] = true;

        if (isPrimeGenerator(i, notPossible))
            ans += i;
    }
    cout << ans << endl;
    delete[] notPossible;
}

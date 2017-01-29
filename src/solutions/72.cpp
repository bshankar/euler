#include <iostream>
#include <vector>
#include <numeric>
#include "../lib/euler.h"
using namespace std;
typedef unsigned long ul;

int main() {
    int N = 1000000;
    vector<bool> s = sieve(N);
    vector<ul> phiArray;
    phiArray.resize(N);
    
    // calculate all primes and powers of primes
    for (int i = 0; i <= N; ++i) {
        if (s[i]) continue;
        ul pr = i+2;
        ul pr_ = pr, pr__ = pr;
        phiArray[pr] = pr-1;
        while (pr_*pr <= N) {
            pr__ = pr_;
            pr_ *= pr;
            phiArray[pr_] = pr__*(pr - 1);
        }
    }
        
    for (int i = 2; i <= N; ++i) {
        if (phiArray[i]) continue;
        for (int j = 0; j < N; ++j) {
            if (s[j] || i % (j+2)) continue;
            int i_ = i;
            while (i_ % (j+2) == 0)
                i_ /= (j+2);
            phiArray[i] = phiArray[i_]*phiArray[i/i_];
            break;
        }
    }
    
    ul ans = 0;
    for (int i = 2; i <= N; ++i)
        ans += phiArray[i];
    
    cout << ans << endl;
}

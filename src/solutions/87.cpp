#include <iostream>
#include <vector>
#include "../lib/euler.hpp"
using namespace std;
typedef unsigned long ul;

int main() {
    ul N = 50000000;
    vector<bool> s = sieve(N);
    vector<bool> canb(N);
    
    for (ul i = 2; i < N; ++i) {
        ul ii = i*i;
        if (ii > N) break;
        if (s[i-2]) continue;
        for (ul j = 2; j < N; ++j) {
            ul jjj = ii + j*j*j;
            if (jjj > N) break;
            if (s[j-2]) continue;
            for (ul k = 2; j < N; ++k) {
                ul kkkk = jjj + k*k*k*k;
                if (kkkk > N) break;
                if (s[k-2]) continue;
                
                canb[kkkk] = true;
            }
        }
    }
    
    int ans = 0;
    for (int i = 0; i < N; ++i)
        if (canb[i])
            ++ans;
            
    cout << ans << endl;
}

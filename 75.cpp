#include <iostream>
#include "prime.h"
#include <cmath>
using namespace std;

int main() {
    int N = 1500000;
    int *pf = new int[N];
    for (int m = 1; m < sqrt(N/2); ++m) {
        for (int n = 1; n < m; ++n) {
            if ((m-n)&1 && gcd(m, n) == 1) {
                int peri = 2*m*(m+n);
                int peri_ = peri;
                while (peri_ <= N) {
                    ++pf[peri_];
                    peri_ += peri;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < N; ++i)
        if (pf[i] == 1)
            ++ans;
    
    cout << ans << endl;
}

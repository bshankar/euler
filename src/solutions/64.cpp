#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
using namespace std;

template <class T>
T sqrtPeriod(T n) {
    // Compute period of continued fraction expansion of sqrt(n)
    // Algorithm from wikipedia
    T m = 0, d = 1, a0 = (int) sqrt(n);
    T a = a0, period = 0;

    while (a != 2*a0) {
       m = d*a - m;
       d = (n - m*m)/d;
       a = (a0 + m)/d;
       ++period;
    } 
    return period;
}


int main(int argc, const char *argv[]) {
    int ans = 0;
    const int N = 10001;
    bool isSquare[N] = {};
    for (int i = 2; i < N; i++) {
        if (!isSquare[i] && sqrtPeriod(i)&1)
            ++ans;

        if (i*i < N)
            isSquare[i*i] = true;
    }

    cout << ans << endl;
}

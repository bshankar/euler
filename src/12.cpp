#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
using namespace std;

template <class T>
T cd(T n) {
    T d = 0;
    #pragma omp parallel for reduction(+: d)
    for (T i = 1; i < (T) sqrt(n) + 1; ++i) {
        if (n % i == 0)
            d += 2;
    }
    return d;
}

int main() {
    unsigned long n = 1, k = 1;
    while (cd(n) < 500) {
        ++k;
        n += k;
    }
    cout << n << endl;
}

#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
using namespace std;

template <class T>
T cd(T n) {
    T d = 0;
    for (T i = 1; i < sqrt(n); ++i) {
        if (n % i == 0)
            d += 2;
    }
    return d;
}

int main(int argc, char** argv) {
    unsigned long n = 1, k = 1;
    while (cd(n) < 500) {
        ++k;
        n += k;
    }
    cout << n << endl;
}

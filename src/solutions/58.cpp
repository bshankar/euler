#include <iostream>
#include <cmath>
#include "../lib/euler.h"
using namespace std;

int main() {
    vector<bool> v = sieve(1000000000);
    int inc = 2, sum = 1, k = 1;
    int mod = 0;
    double pr = 0, total = 1, pp = 1; // prime fraction
    while (pp >= 0.1 || total < 3) {
        k += inc;
        sum += k;
        if (!v[k-2]) ++pr;
        ++total;
        ++mod;
        if (mod == 4) {
            mod = 0;
            inc += 2;
            pp = pr/total;
        }
    }
    cout << sqrt(k) << endl;
}

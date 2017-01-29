#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
using namespace std;

#define N 100000000
bool isChecked[N] = {};

template <class T>
bool isReversible(T n) {
    if (n%10 == 0)
        // no leading zeroes
        return false;
    
    // create reversed number
    T n_ = n, nRev = 0;
    while (n_) {
        nRev *= 10;
        nRev += n_%10;
        n_ /= 10;
    }
 
    // mark nRev as checked
    isChecked[nRev] = true;

    // is it reversible?
    T r = n + nRev;
    T k = 0;
    while (r) {
        if (!((r%10) & 1)) {
            return false;
        }
        r /= 10;
        ++k;
    }
    return true;
}

int main(int argc, const char *argv[]) {
    int revCount = 0;
    for (int i = 0; i < N; i++)
       if (!isChecked[i] && isReversible(i)) 
           ++revCount;

    cout << 2*revCount << endl;
    return 0;
}

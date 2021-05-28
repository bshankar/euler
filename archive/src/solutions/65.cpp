#include <iostream>
#include <gmpxx.h>
using namespace std;

mpq_class eConv(int n) {
    // convergents of e-1
    if (n == 1) {
        mpq_class ans(1, 2);
        return ans;
    }
    mpq_class ans(1, (2 + eConv(n-1)));
    return ans;
}

int main() {
    mpq_class r = eConv(1);
    cout << r << endl;
}

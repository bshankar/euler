#include <iostream>
#include "prime.h"
using namespace std;

int main() {
    //  28433×2^7830457+1
    unsigned long b = 2, e = 7830457, m = 1000000000;
    unsigned long p = pow(b, e, m);
    cout << (p*28433 + 1) % m << endl;
}

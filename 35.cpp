#include <iostream>
#include <vector>
#include "prime.h"

typedef short s;
typedef unsigned short us;
typedef unsigned int ui;
typedef unsigned long ul;
using namespace std;

int rotate(int n) {
    int k = 1;
    while (k < n)
        k *= 10;
    k /= 10;
    int n_ = (n % k)*10 + n/k;
    return n_;
}

int main() {
    vector<bool> v = sieve(1000000);
    int cp = 0;
    for (int i = 0; i < 999998; i++) {
        if (v[i])
            continue;
        int prime = i+2;
        int rprime = rotate(prime);
        bool cp_ = true;
        int tcp = 1;
        while (rprime != prime) {
            if (v[rprime-2]) {
                cp_ = false;
                break;
            } else {
                v[rprime-2] = true;
                ++tcp;
            }
            rprime = rotate(rprime);
        }
        if (cp_) cp += tcp;
    }
    cout << cp << endl;
}


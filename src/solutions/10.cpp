#include <iostream>
#include "../lib/euler.h"
typedef unsigned long ul;
using namespace std;

int main() {
    ul N = 2000000;
    ul sum = 0;
    vector<bool> s = sieve(N);
    for (ul i = 0; i < N; ++i) {
        if (s[i]) continue;
        sum += i + 2;
    }
    cout << sum << endl;
}


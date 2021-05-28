#include <iostream>
#include <vector>
#include "../lib/euler.hpp"
using namespace std;

bool isRtp(int N, vector<bool>& v) {
    while (N > 10) {
        N /= 10;
        if (N < 2 || v[N - 2])
            return false;
    }
    return true;
}

bool isLtp(int N, vector<bool>& v) {
    int j = 1;
    while (N > 10*j) {
        j *= 10;
        int k = N % j;
        if (k < 2 || v[k - 2])
            return false;
    }
    return true;
}

int main() {
    int N = 1000000;
    int sum = 0;
    vector<bool> v = sieve(N);
    for (int i = N; i > 10; --i) {
        if (v[i-2]) continue;
        
        if (isLtp(i, v) && isRtp(i, v))
            sum += i;
    }
    cout << sum << endl;
}

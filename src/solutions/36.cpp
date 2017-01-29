#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <class T>
vector<T> vec(T n, T base) {
    T i = 1;
    vector<T> tVec;
    while (n > i) {
        i *= base;
    }
    i /= base;
    while (i) {
        tVec.push_back(n/i);
        n %= i;
        i /= base;
    }
    return tVec;
}

int main() {
    int sum = 0;
    for (int i = 1; i < 1000000; ++i) {
        vector<int> v10 = vec(i, 10), v10_;
        vector<int> v2 = vec(i, 2), v2_;
        v2_ = v2; v10_ = v10;
        reverse(v10_.begin(), v10_.end());
        reverse(v2_.begin(), v2_.end());
        
        if (v10 == v10_ && v2 == v2_) {
            sum += i;
            //cout << i << endl;
        }
    }
    cout << sum-2 << endl; // 2 is a false positive!
}

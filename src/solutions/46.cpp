#include <iostream>
#include <cmath>
#include <vector>
#include "../lib/euler.h"
using namespace std;

int main() {
    int N = 10000;
    vector<bool> v = sieve(N);
    vector<bool> gb, sqr;
    gb.resize(N);
    sqr.resize(N);
    
    for (int i = 0; i < 100; ++i)
        sqr[i*i] = true;
    
    gb[3] = gb[5] = gb[7] = true;
    
    for (int i = 9; i < N; i += 2) {
        if (!v[i-2]) {
            gb[i] = true;
            continue;
        }
        for (int j = 1; j < v.size(); ++j) {
            if (v[j]) continue;
            if (j+2 >= i) break;
                        
            int i_ = (i - j-2)/2;
            //cout << i << " " << j+2 <<" " << i_ << endl;
            if (sqr[i_]) {
                gb[i] = true;
                break;
            }
        }
    }
    
    for (int k = 3; k < gb.size(); k += 2) {
        if (!gb[k]) {
            cout << k << endl;
            break;
        }
    }
}

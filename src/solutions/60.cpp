#include <iostream>
#include <vector>
#include <cmath>
#include "../lib/euler.h"

typedef unsigned long ul; 
using namespace std;

bool isPair(ul i, ul j) {
    ul ij = pow(10, floor(log10(j))+1)*i + j;
    ul ji = pow(10, floor(log10(i))+1)*j + i;
    if (fermat(ij) && fermat(ji))
        return true;
    return false;
}

int main() {
    ul N = 20000; // guessed upper limit
    vector<bool> s = sieve(N);
    
    vector<vector<bool> > isp; // cache all pairs
    isp.resize(N, vector<bool>(N));
    
    for (int i = 2; i < N; ++i) {
        if (s[i-2]) continue;
        for (int j = i+1; j < N; ++j) {
            if (s[j-2]) continue;
            if (isPair(i, j))
                isp[i][j] = true;
                isp[j][i] = true;
        }
    }
    
    ul sum_ = 10000000;
    for (ul i = 2; i < N; ++i) {
        if (s[i-2]) continue;
        for (ul j = i+1; j < N; ++j) {
            if (s[j-2] || !isp[i][j])
                continue;
            for (ul k = j+1; k < N; ++k) {
                if (s[k-2] || !isp[i][k] || !isp[j][k])
                    continue;
                for (ul l = k+1; l < N; ++l) {
                    if (s[l-2] || !isp[i][l] || !isp[j][l] || 
                    !isp[k][l])
                        continue;
                    for (ul m = l+1; m < N; ++m) {
                        if (s[m-2] || !isp[i][m] || !isp[j][m] ||
                        !isp[k][m] || !isp[l][m])
                        continue;
                        
                        if (i+j+k+l+m < sum_) {
                            sum_ = i+j+k+l+m;
                            cout << i << " + " << j << " + " << k << " + " << l << " + " << m 
                            << " = " << sum_ << endl;
                        }
                    }
                }
            }
        }
    }
}

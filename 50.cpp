#include <iostream>
#include "prime.h"
using namespace std;
typedef unsigned int ui;

int main() {
    vector<bool> v = sieve(1000000);
    int start = 0;
    int maxLen = 0, maxPr = 0;
    
    for (ui i = 0; i < v.size()-2; ++i) {
        if (v[i]) continue;
        start = i+2;
        int len = 0, pr = start;
        for (ui j = i+1; j < v.size()-2; ++j) {
            if (v[j]) continue;
            pr += j+2;
            if (pr > 1000000) break;
            ++len;
            // if we get a prime with better maxPr
            // store it
            if (!v[pr-2] && len > maxLen) {
                maxLen = len;
                maxPr = pr;
            }
        }
    }
    cout << maxPr << endl;
}

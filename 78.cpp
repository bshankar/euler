#include <iostream>
#include <vector>

typedef short s;
typedef unsigned short us;
typedef unsigned int ui;
typedef unsigned long ul;
using namespace std;

int main() {
    int N = 60000;
    vector<int> p; // store previous partitions
    p.resize(N);
    
    vector<int> pn; // pentagonal numbers below 100k
    vector<int> fac;
    
    int k = 1;
    int pn_ = k*(3*k-1)/2;
    while (pn_ < 60000) {
        pn.push_back(pn_);
        
        if ((k-1) & 1) {
            fac.push_back(-1); 
            fac.push_back(-1);
        }
        else {
            fac.push_back(1); 
            fac.push_back(1);
        }
            
        k = -k;
        pn_ = k*(3*k-1)/2;
        pn.push_back(pn_);
        k = -k;
        ++k;
        pn_ = k*(3*k-1)/2;
    }
    
    while (true) {
        int ans = 0; // possible answer
        p[0] = 1;
        p[1] = 1;
        
        for (int i = 2; i < N; ++i) {
            int j = 0;
            while (i - pn[j] >= 0) {
                p[i] += fac[j]*p[i - pn[j]];
                ++j;
            }
            p[i] %= 1000000;
            if (!p[i]) {
                cout << i << endl;
                return 0;
            }
        }
    }
}


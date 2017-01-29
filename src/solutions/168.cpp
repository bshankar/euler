#include <iostream>
#include "../lib/euler.h"
#include <vector>
#include <string>
using namespace std;


int main() {
    int N = 100;
    vector<bool> s = sieve(N);
    int ans = 0;
    for (int i = 2; i < N; ++i) {
        if (s[i]) 
            continue;
        unsigned long t = 0, r = 1;
        string n;
        int p = i+2;
        bool started = false;
        while ((r != 1 || !started ) && t < p) {
            ++t;
            int x = 10*r;
            int d = x/p;
            r = x % p;
            n += d + '0';
            started = true;
        }
        if (t == p-1) {
            cout << t << endl;
            ans += stoi(n.substr(n.size()-5, 5));
        }
    }
    cout << ans % 100000 << endl;
}

#include <iostream>
#include <vector>
#include "../lib/euler.hpp"
using namespace std;

int main() {
    int max = 0, ans;
    vector<bool> s = sieve(1000);
    for (int i = 0; i < s.size(); ++i) {
        if (s[i])
            continue;
        int p_ =  period(i+2);
        if (p_ > max) {
            max = p_;
            ans = i+2;
        }
    }
    cout << ans << endl;
}
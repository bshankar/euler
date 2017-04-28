#include "../lib/euler.hpp"
#include <iostream>
using namespace std;

int main() {
    int N = 12000;
    int ans = 0;
    for (int num = 2; num < N/3 + 1; ++num) {
        int den = 2*num + 1;
        while (double(num)/den > double(1)/3) {
            if (gcd(num, den) == 1) {
                //cout << num << " " << den << endl;
                ++ans;
            }
            ++den;
        }
    }
    cout << ans << endl;
}

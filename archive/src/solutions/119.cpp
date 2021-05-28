#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

typedef short s;
typedef unsigned short us;
typedef unsigned int ui;
typedef unsigned long long ul;
using namespace std;

ul ds_(ul k) {
    ul sum = 0;
    ul k_ = k;
    while (k) {
        sum += k % 10;
        k /= 10;
    }
    return sum;
}

int main() {
    ul n = 0, ans = 0;
    ul max_ = 10000000000000; // limit found by trail and error
    ul ds = 2, p = 0, dsp = 1;
    while(n < 30) {
        while (dsp < max_) {
            dsp *= ds;
            ++p;
            if (ds_(dsp) == ds && dsp > 10) {
                if (dsp > ans)
                    ans = dsp;
                ++n;
            }
        }
        dsp = 1;
        ++ds;
        p = 1;
    }
    cout << ans << endl;
}

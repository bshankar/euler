#include <iostream>
#include <set>
#include <cmath>
using namespace std;
typedef unsigned long ul;

#define N 1000000000000

int main(int argc, const char *argv[]) {
    set<ul> sR;
    sR.insert(1);
    ul ans = 0;

    for (ul i = 2; i < sqrt(N); ++i) {
        ul k_ = i*i, k = i+1;
        while (k+k_ < N) {
            k += k_;
            sR.insert(k);
            k_ *= i;
        }
    }

    for (auto i = sR.begin(); i != sR.end(); ++i)
        ans += *i;
    cout << ans << endl;
}

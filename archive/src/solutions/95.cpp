#include <iostream>
#include <cmath>
using namespace std;
typedef unsigned long ul;

int sd(int N) {
    int sum = 0;
    for (int j = 2; j < sqrt(N)+1; ++j) {
        if (N % j == 0) {
            sum += j;
            sum += N/j;
        }
    }
    return sum + 1;
}

int main() {
    const int N = 1000000;
    bool chained[N] = {};
    int max_len = 0, ans;
    for (int i = 1; i < N; ++i) {
        int i_ = sd(i), len = 0;
        while (i != i_ && len < 100 && i_ < N) {
            i_ = sd(i_);
            ++len;
            if (i_ > N) {
                len = 0;
                break;
            }
        }
        if (len == 100)
            len = 0;
        if (len > max_len) {
            max_len = len;
            ans = i;
        }
    }
    cout << "Answer is " << ans << " with a chain of length " << max_len << endl;
}

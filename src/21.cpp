#include <iostream>
#include <cmath>
using namespace std;

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
    int ans = 0;
    for (int i = 1; i < 10000; ++i) {
        int j = sd(i);
        if (i > j && sd(j) == i)
            ans += i + j;
    }
    cout << ans << endl;
}
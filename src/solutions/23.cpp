#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int sumOfDivisors(int n) {
    int sum_ = 0;
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            sum_ += i;
            if (i != n/i)
                sum_ += n/i;
        }
    }
    return sum_ + 1;
}

int main() {
    const int N = 28123;
    vector<int> abundants;
    vector<bool> is_abundant_sum(N);
    long sum_ = 0;

    for (int i = 12; i < N; ++i)
        if (sumOfDivisors(i) > i)
            abundants.push_back(i);

    for (int i = 0; i < abundants.size(); ++i)
        for (int j = i; abundants[i] + abundants[j] < N; ++j)
            is_abundant_sum[abundants[i] + abundants[j]] = true;

    for (int i = 0; i < is_abundant_sum.size(); ++i)
        if (!is_abundant_sum[i])
            sum_ += i;

    cout << sum_ << endl;
}

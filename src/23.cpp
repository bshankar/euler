#include <iostream>
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
    bool isAbundant[N] = {};
    bool isSumOfAbundants[N] = {};

    for (int i = 12; i < N; ++i) {
        if (sumOfDivisors(i) > i)
            isAbundant[i] = true;
    }

    for (int i = 0; i < N; ++i) {
        for (int j = i; j < N; ++j) {
            if (i+j >= N) break;
            if (isAbundant[i] && isAbundant[j])
                isSumOfAbundants[i+j] = true;
        }
    }

    long sum_ = 0;    
    for (int i = 0; i < N; ++i)
        if (!isSumOfAbundants[i])
            sum_ += i;

    cout << sum_ << endl;
}

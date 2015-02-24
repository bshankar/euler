#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>

typedef short s;
typedef unsigned short us;
typedef unsigned int ui;
typedef unsigned long ul;
using namespace std;

int f(int n) {
    if (n == 0 or n == 1)
        return 1;
    return n*f(n-1);
}

int fs(int n) {
    int sum = 0;
    int divisor = 10;
    while (n) {
        int digit = n % 10;
        n /= 10;
        sum += f(digit);
    }
    return sum;
}

int main() {
    int ans = 0;
    for (int i = 3; i < 100000; ++i) {
        if (fs(i) == i)
            ans += i;
    }
    cout << ans << endl;
}

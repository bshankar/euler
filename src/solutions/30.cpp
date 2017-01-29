#include <iostream>
#include <cmath>

typedef short s;
typedef unsigned short us;
typedef unsigned int ui;
typedef unsigned long ul;
using namespace std;

ul ds_(ul k) {
    ul sum = 0;
    ul k_ = k;
    while (k) {
        sum += pow(k % 10, 5);
        k /= 10;
    }
    return sum;
}

int main() {
    ul ans = 0;
    for (ul i = 2; i < 200000; i++){
        if (ds_(i) == i)
            ans += i;
    }
    cout << ans << endl;
}


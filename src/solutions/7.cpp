#include <iostream>
#include <cmath>

typedef short s;
typedef unsigned short us;
typedef unsigned int ui;
typedef unsigned long ul;
using namespace std;

int main() {
    ui primes = 2;
    ul i = 5;
    while (primes < 10001) {
        bool c = false;
        for (ul j = 3; j <= sqrt(i); j += 2){
            if (i % j == 0) {
                c = true;
                break;
            }
        }
        if (!c) {
            ++primes;
        }
        i += 2;
    }
    cout << i-2 << endl;
}


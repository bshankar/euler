#include <iostream>

typedef short s;
typedef unsigned short us;
typedef unsigned int ui;
typedef unsigned long ul;
using namespace std;

long p(long n, long k) {
    if (n == 0)
        return 1;
    else if (n < 0 or k <= 0)
        return 0;
    
    return p(n-k, k) + p(n, k-1);
}

int main() {
    cout << p(100, 99) << endl;
}


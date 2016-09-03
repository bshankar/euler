#include <iostream>

typedef short s;
typedef unsigned short us;
typedef unsigned int ui;
typedef unsigned long ul;
using namespace std;

int main() {
    int ans = 0;
    for (int i = 0; i < 1000; i++) {
        if (!(i % 3) or !(i % 5))
            ans += i;
    }
    cout << ans << endl;
}

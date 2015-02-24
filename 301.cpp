#include <iostream>
using namespace std;
typedef unsigned long ul;

int main() {
    ul ans = 0;
    for (ul n = 1; n <= 1<<30; ++n)
        if (!(n^(2*n)^(3*n)))
            ++ans;

    cout << ans << endl;
}

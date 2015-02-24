#include <iostream>
using namespace std;

int main() {
    int inc = 2, sum = 1, k = 1;
    int mod = 0;
    while (k < 1001*1001) {
        k += inc;
        sum += k;
        ++mod;
        if (mod == 4) {
            mod = 0;
            inc += 2;
        }
    }
    cout << sum << endl;
}

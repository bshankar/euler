#include "prime.h"
using namespace std;
typedef unsigned char uc;
typedef unsigned long ul;

// start with 40561817703823564929
// and try to find other primitive sets that
// create numbers divisible by 11

uc pos[] = {1, 1, 2, 2, 3, 4, 4, 5, 5, 7};
uc neg[] = {0, 0, 3, 6, 6, 7, 8, 8, 9, 9};

int main() {
    ul ans = permutations(10, 10) / 16;
    ans *= ans;
    cout << ans << endl;
}

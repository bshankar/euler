#include <iostream>
using namespace std;

int main() {
    // na + 1 + na(-1)^n-1 + -1^n
    // if n is even
    // na + 1 - na + 1 = 2
    //
    // if n is odd
    // na + 1 + na - 1 = 2na
    //
    // this is maximzed at a(a-1)/2 when n is odd and
    // a(a-2)/2 when n is even
    //
    // simplifying
    // ans = a_max/2*(a_max/2-1)*(4/3*(a_max-1) + 2)

    cout << 500*499*1335 << endl;
}

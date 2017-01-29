#include <iostream>
#include "../lib/euler.h"
#include <vector>

using namespace std;
typedef unsigned long ul;

int main() {
    ul ans = 0; 
    for (ul n = 2; n < 10000000; n++) {
       ul n2 = n*n;
       if (fermat(n2+1) && fermat(n2+3) && fermat(n2+7) && 
           fermat(n2+9) && fermat(n2+13) && fermat(n2+27))
           cout << n << endl;
           //ans += n;
    }
    cout << ans << endl;
}

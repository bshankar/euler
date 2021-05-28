#include <cmath>
#include <iostream>
using namespace std;

/* 
 * 10^(k-1) <= n^k < 10^k
 * k-1 <= k*log(n) < k
 * k(log(n)-1) >= -1, k(log(n)-1) < 0
 * implies n < 10 and k >= -1/(log(n)-1) i.e k >= 1
*/

int main() {
    int ans = 0;
    for (int n = 2; n < 10; ++n) {
        int k = 1;
        while (k*log10(n) > k-1) {
            ++ans;
            ++k;
        }
    }
    // we skipped 1^1
    cout << ans + 1 << endl;
}

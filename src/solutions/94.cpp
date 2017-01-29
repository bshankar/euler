#include "../lib/euler.h"
using namespace std;
#define MAX 1000000000

int main() {
    // number of almost equilateral triangles
    // with integer height
    ul ans = 0;

    #pragma omp parallel for reduction(+:ans)
    for (ul k = 3; k <= MAX/3 + 2; k += 2) {
        // check k k k+1 for integer height
        // check k k k-1
        if (3*k + 1 <= MAX && is_square(3*k*k - 2*k - 1))
            ans += 3*k + 1;
        if (3*k - 1 <= MAX && is_square(3*k*k + 2*k - 1))
            ans += 3*k - 1;
    }
    cout << ans << endl;
}

#include "prime.h"
using namespace std;

#define N 10000000

int main() {
    ui m = 0;
    #pragma omp parallel for schedule(dynamic) reduction(+:m)
    for (ui n = 1; n <= N; ++n) {
        ui a_ = 1;
        for (ui a = n-1; a >= 1; --a)
            if (a*a % n == a) {
                a_ = a;
                break;
            }
        m += a_;
    }
    cout << m << endl;
}

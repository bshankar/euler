#include "../lib/euler.hpp"
#include <gmpxx.h>
using namespace std;
const int M = pow(14, 8);

int ack(int m, int n) {
    if (m == 0)
        return (n + 1);
    if (m == 1)
        return (n + 2);
    if (m == 2)
        return (2*n + 3);

    if (n == 0)
        return ack(m-1, 1);
    return ack(m-1, ack(m, n-1));
}

int main() {
    ul sum = 0;
    for (auto i = 0; i <= 6; ++i)
        sum += ack(i, i);
    cout << sum << endl;
}

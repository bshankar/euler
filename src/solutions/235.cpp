#include "approx.hpp"
using namespace std;
typedef double ld;

ld ag_sum(ld r) {
    return 6e11 + 1 / (r - 1) * (900 * (pow(r, 5000) - 1) - 3 * (5000 * pow(r, 5000) - (pow(r, 5000) - 1) / (r - 1)));
}

int main() {
    cout << setprecision(13);
    cout << bisect(ag_sum, 1.0029, 1.001, 1e-15, 1e-13, 1000000) << endl;
}

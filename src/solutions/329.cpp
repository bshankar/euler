#include "../lib/euler.h"
#include <gmpxx.h>
#include <algorithm>
typedef mpq_class fr;
using namespace std;

#define TARGET "PPPPNNPPPNPPNPN"
const vector<bool> nos = sieve(500);
fr probs[15][500]; // probability(index, start)

bool is_prime(int n) {
    if (n == 1) return false;
    return !nos[n-2];
}

fr get_prob(int n, int i) {
    if ((is_prime(n+1) && TARGET[i] == 'P') ||
        (!is_prime(n+1) && TARGET[i] == 'N'))
        return fr(2, 3);
    return fr(1, 3);
}

int main() {
    // initial values
    for (auto s = 0; s < 500; ++s)
        probs[0][s] = get_prob(s, 0);

    for (auto i = 1; i < 15; ++i)
        for (auto s = 0; s < 500; ++s) {
            if (s) { // go left
                fr jump_prob = (s-1) ? fr(1, 2) : 1;
                probs[i][s] += jump_prob*get_prob(s, i)*probs[i-1][s-1];
            }
            if (s < 499) { // go right
                fr jump_prob = (s+1 < 499) ? fr(1, 2) : 1;
                probs[i][s] += jump_prob*get_prob(s, i)*probs[i-1][s+1];
            }
        }

    fr ans = 0;
    for (auto s = 0; s < 500; ++s)
        ans += probs[15-1][s];
    cout << ans/500 << endl;
}

#include "../lib/euler.h"

string euler10() {
    ul N = 2000000;
    vector<int> p = segmented_sieve<int>(N);
    return to_string(accumulate(p.begin(), p.end(), (ul) 0));
}


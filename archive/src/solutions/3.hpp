#include "../lib/euler.hpp"

string euler3() {
    ul N = 600851475143;
    ul pf = 0;
    for (ul i = 3; i <= N; i += 2) {
        while (N % i == 0) {
            N /= i;
            pf = i;
        }
    }
    return to_string(pf);
}


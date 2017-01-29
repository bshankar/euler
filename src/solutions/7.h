#include "../lib/euler.h"


string euler7() {
    ui primes = 2;
    ul i = 5;
    while (primes < 10001) {
        bool c = false;
        for (ul j = 3; j <= sqrt(i); j += 2) {
            if (i % j == 0) {
                c = true;
                break;
            }
        }
        if (!c) {
            ++primes;
        }
        i += 2;
    }
    return to_string(i-2);
}


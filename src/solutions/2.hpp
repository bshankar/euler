#include "../lib/euler.hpp"
 
string euler2() {
    ui i = 1, j = 2, ans = 2; // add 2 beforehand
    while (j < 4000000) {
        i = i + j;
        j = i + j;
        if (i % 2 == 0)
            ans += i;
        if (j % 2 == 0)
            ans += j;
    }
    return to_string(ans);
}


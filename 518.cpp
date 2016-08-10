#include "prime.h"
#include <iostream>
using namespace std;

#define N 1000000

int main(int argc, char *argv[]) {
    vector<bool> s = sieve(N); 
    ul ans = 0;

    for (auto i = 0; i < N; ++i) {
        if (s[i]) continue;
        for (auto j = i+1; j < N; ++j) {
            if (s[j]) continue;

            double ratio = (double) (j+3)/(i+3);
            double last_prime = ratio*(j+3)-1;
            if (floor(last_prime) == ceil(last_prime) && last_prime < N && !s[last_prime-2])
                ans += i + j + 4 + last_prime;
        }
    }
        cout << ans << endl;
}

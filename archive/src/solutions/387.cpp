#include <iostream>
#include "../lib/euler.hpp"
using namespace std;
typedef unsigned long ul;

#define N 100000000000000
ul sum = 0;

template <class T>
void search(T n, T ds) {
    // search for strong right truncatable 
    // harshad numbers with n as seed 
    // (n is a harshad number)

    // If n is strong
    // then try to construct a prime srth
    
    if (n < N) {
        bool isStrong = false;
        if (miller_rabin(n/ds))
            isStrong = true;

        n *= 10;
        search(n, ds);
        for (int i = 1; i < 10; ++i) {
            T n_ = n + i;
            T ds_ = ds + i;

            if (isStrong && miller_rabin(n_) && n < N) 
                sum += n_;

            if (!(n_%ds_))
                // we found a new truncatable Harshad number
                search(n_, ds_);
        }
    }
}

int main(int argc, const char *argv[]) {
    for (__int128 i = 1; i < 10; ++i) 
        search(i, i);
    
    cout << sum << endl;
    return 0;
}

#include "prime.h"
#include <iostream>

#define INF 18446744073709551615

ul next_pow(ul n) {
    return 2*(n+1)-1;
}


int main(int argc, char *argv[]) {
    ul k = 500500,
       mod = 500500507;
    vector<bool> s = sieve(7400000); // intelligent guess
    ul n = 1, k_ = 0;
    vector<ui> primes;
    vector<ui> powers;

    for (ul i = 0; i < s.size(); ++i) {
        if (s[i])
            continue;
        primes.push_back(i+2);
        powers.push_back(1);
    }
    
    ul i = 0; // location of unipower prime
    ul min_pow_factor = INF;
    ul min_pow_factor_index = 0;
    while (k != k_) {

        while(powers[i] > 1)
            ++i;
        
        ul min_factor = primes[i],
        min_index = i;
        if (min_pow_factor == INF || min_pow_factor < primes[i]) {
            if (min_pow_factor != INF) {
                min_index = min_pow_factor_index;
                min_factor = min_pow_factor;
            }
            // update min_pow_factor
            powers[min_index] = next_pow(powers[min_index]);
            ul j = 0;
            min_pow_factor = INF;
            while(powers[j] > 1) {
                ul p = powers[j];
                ul fac = pow(primes[j], p - p/2);
                if (fac < min_pow_factor) {
                    min_pow_factor_index = j;
                    min_pow_factor = fac;
                }
                ++j;
            }
        } else
            powers[min_index] = next_pow(powers[min_index]);
        n = (n*min_factor) % mod;
        ++k_; 
    }
    cout << "Smallest number with 2^" << k << " divisors modulo " 
         << mod << " is "  << n << endl;
}

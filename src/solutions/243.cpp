#include "../lib/euler.hpp"
#include <gmpxx.h>
using namespace std;

int main(int argc, char *argv[]) {
    vector<int> primes = segmented_sieve(100); // guess
    ul totient, max_prime, n;
    bool pow[100] = {};

    // start from 12
    n = 12;
    pow[2] = 1; pow[3] = 1;
    max_prime = 3;
    totient = 4;
    
    mpq_class target(15499, 94744);

    while (target <= mpq_class(totient, (n-1))) {
        int min_prime = primes[0],
            min_totient = min_prime*totient;

        mpq_class min_res(min_totient, min_prime*n-1);

        for (auto i = 0; i < primes.size(); ++i) {
            int tmp_prime = primes[i],
                tmp_totient = totient*((pow[tmp_prime]) ? tmp_prime : tmp_prime-1);
            mpq_class res(tmp_totient, n*tmp_prime-1);

            if (res < target) {
                // we found minimum n!
                cout << n*tmp_prime << endl;
                return 0;
            }

            if (res < min_res) {
                // we haven't yet found minimum n
                // multiply n by best possible prime
                min_res = res;
                min_prime = tmp_prime;
                min_totient = tmp_totient;
            }
        }
        // update n and other variables
        n *= min_prime;
        pow[min_prime] = 1;
        totient = min_totient;
    }
    cout << n << endl;
}

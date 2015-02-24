#include <iostream>
#include <vector>
#include <time.h>
#include <cstdlib>
#include <cmath>

using namespace std;
typedef short s;
typedef unsigned short us;
typedef unsigned int ui;
typedef unsigned long ul;

template<class T>
T pow(T a, T b, T c) {
    // compute a^b mod c
    T ans = 1;
    while (b > 0) {
        if (b&1)
            ans = (ans*a) % c;
        b = b >> 1;
        a = (a*a) % c;
    }
    return ans;
}


template<class T>
bool fermat(T n, T k=10, T max=1000) {
    // fermat's test
    //a^p-1 = 1 mod p
    srand(time(NULL));
    for (T i = 0; i < k; i++) {
        T r = rand() % max + 2;
        if (r % n == 0) {
            --k;
            continue;
        }
        if (pow(r, n-1, n) != 1)
            return false;
    }
    return true;
}

template <class T>
bool miller_rabin(T n, T k = 5) {
    // The miller rabin test for primality
    if (n == 2 || n == 3)
        return true;

    if (!(n&1) || n == 1)
        return false;
    
    srand(time(NULL));

    // write n-1 as 2^s*d
    T s = 0, d = n-1;
    while (d % 2 == 0) {
        d /= 2;
        ++s;
    }
    
    // witness loop
    for (int i = 0; i < k; ++i) {
        T a = rand()%(n-4) + 2; 
        T x = pow(a, d, n);
        if (x == 1 || x == n-1)
            continue;
        bool b = false;
        for (int j = 0; j < s-1; ++j) {
            x = x*x % n;
            if (x == 1)
                return false;
            if (x == n-1) {
                b = true;
                break;
            }
        }
        if (!b)
            return false;
    }
    return true;
}

template<class T>
std::vector<bool> sieve(T N) {
    // sieve of eratostenes
    std::vector<bool> s(N);
    for (T i = 0; i < sqrt(N)+1; ++i) {
        if (s[i])
            continue;
        T prime = i + 2;
        for (T j = i + prime; j < N; j += prime) {
            s[j] = true;  // marked composite
        }
    }
    return s;
}


template<class T>
T gcd(T a, T b) {
    // calculate gcd using euclid's algorithm
    if (a == b)
        return a;
    while (a && a-1 && b && b-1) {
        if (a > b) 
            a = a % b;
        else
            b = b % a;
    }
    
    if (!a) return b;
    if (!b) return a;
    if (!(a-1) || !(b-1)) return 1;
}


template <class T>
T sumDigits(T n) {
    // find the sum of digits of n
    T ds = 0;
    while (n) {
        ds += n%10;
        n /= 10;
    }
    return ds;
}

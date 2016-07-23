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
        for (T j = prime*prime - 2; j < N; j += prime) {
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
void extended_euclid(T a, T b, vector<T>& v) {
    T s = 0, t = 1, r = b;
    T s_ = 1, t_ = 0, r_ = a;

    while (r != 0) {
        T q = r_/r;
        T r_tmp = r_, s_tmp = s_, t_tmp = t_;
        r_ = r; s_ = s; t_ = t;
        r = r_tmp - q*r; 
        s = s_tmp - q*s; 
        t = t_tmp - q*t;
    }
    v[0] = s_; v[1] = t_;  // bezout coefficients
    v[2] = r_;  // gcd
    v[3] = t; v[4] = s;  // 
}


template <class T>
T inverse(T a, T n) {
    // calculate the multiplicative inverse
    // in modular structures
    T t = 1, r = a, q;
    T t_ = 0, r_ = n;
    T t_tmp, r_tmp;

    while (r) {
        q = r_/r;
        r_tmp = r_; t_tmp = t_;
        t_ = t; r_ = r;
        t = t_tmp - q*t;
        r = r_tmp - q*r;
    }
    if (r_ > 1)
        // not invertible
        return 0;
    if (t_ < 0)
        t_ += n;
    return t_;
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


template <class T>
T permutations(T n, T k) {
    // permutations of n objects chosen k at a time
    T p = 1;
    for (T i = 0; i < k; ++i)
        p *= n-i;

    return p;
}


double combinations(double n, double k) {
    // combinations of n objects chosen k at a time
    k = min(k, n-k);
    double c = 1;
    for (double i = 1; i < k+1; ++i)
        c *= (n-i+1)/i;
    return c;
}


template <class T>
T combinations(T n, T k) {
    // combinations of n objects chosen k at a time
    return permutations(n, k)/permutations(k, k);
}


template <class T>
vector<T> all_divisors(T n) {
    // list of all divisors of n
    vector<T> divisors;
    for (T k = 1; k < sqrt(n)+1; ++k)
        if (n % k == 0) {
        divisors.push_back(k);
        divisors.push_back(n/k);
        }
    return divisors;
}

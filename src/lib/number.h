#ifndef NUMBER_H
#define NUMBER_H

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

// L1 cache size in bytes
#define L1_CACHE_SIZE 32678

template<class T>
T round(T a) {
  return floor(a + 0.5);
}

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
        r_ = r;
        s_ = s;
        t_ = t;
        r = r_tmp - q*r;
        s = s_tmp - q*s;
        t = t_tmp - q*t;
    }
    v[0] = s_;
    v[1] = t_;  // bezout coefficients
    v[2] = r_;  // gcd
    v[3] = t;
    v[4] = s;  //
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
        r_tmp = r_;
        t_tmp = t_;
        t_ = t;
        r_ = r;
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

template <class T>
T combinations(T n, T k) {
    // combinations of n objects chosen k at a time
    k = min(k, n-k);
    T num = 1, den = 1;
    for (T i = 1; i < k+1; ++i) {
        num *= (n-i+1);
        den *= i;
    }
    return num/den;
}

template <class T>
T V(T n, T k) {
  // Ways to put n objects in k bins
  return combinations(n + k - 1, k - 1);
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


template <class T>
T no_of_divisors(T n, const vector<T>& primes) {

    if (primes.back() < n/2) {
        cout << "n is too large to determine all divisors"
             << "from the given set of primes!" << endl;
        exit(1);
    }

    T div = 1;
    for (auto prime: primes) {
        if (prime > n/2)
            break;

        T n_ = n, pow = 0;
        while (n_ % prime == 0) {
            n_ /= prime;
            ++pow;
        }
        div *= 1 + pow;
    }
    return div;
}


template <class T>
vector<T> segmented_sieve(T limit,
                          T segment_size=L1_CACHE_SIZE) {
    T sqrt_ = sqrt(limit);
    T s = 2;
    T n = 3;

    // vector used for sieving
    vector<char> sieve(segment_size);

    // generate small primes <= sqrt
    vector<char> is_prime(sqrt_ + 1, 1);
    for (auto i = 2; i * i <= sqrt_; i++)
        if (is_prime[i])
            for (auto j = i * i; j <= sqrt_; j += i)
                is_prime[j] = 0;

    vector<T> primes, primes_;
    vector<T> next;

    if (limit >= 2)
        primes_.push_back(2);

    for (auto low = 0; low <= limit; low += segment_size) {
        fill(sieve.begin(), sieve.end(), 1);

        // current segment = interval [low, high]
        T high = min(low + segment_size - 1, limit);

        // store small primes needed to cross off multiples
        for (; s * s <= high; s++)
            if (is_prime[s]) {
                primes.push_back(s);
                next.push_back(s * s - low);
            }

        // sieve the current segment
        for (auto i = 1; i < primes.size(); i++) {
            T j = next[i];
            for (auto k = primes[i] * 2; j < segment_size; j += k)
                sieve[j] = 0;
            next[i] = j - segment_size;
        }

        for (; n <= high; n += 2)
            if (sieve[n - low])
                // n is a prime not stored in primes
                primes_.push_back(n);
    }
    return primes_;
}


bool is_square(ul n) {
    ul h = n & 0xF;  // h is the last hex "digit"
    if (h > 9)
        return 0;
    // Use lazy evaluation to jump out of the if statement as soon as possible
    if (h != 2 && h != 3 && h != 5 && h != 6 && h != 7 && h != 8) {
        ul t = (ul) floor( sqrt((double) n) + 0.5 );
        return t*t == n;
    }
    return 0;
}

template <class T>
vector<vector<T>> primitive_pythagorean_triples(
T max_perimeter) {
    // generate all primitve pythagorean triples that have
    // perimeter <= max_perimeter
    vector<T> t = {3, 4, 5};
    vector<vector<T>> ts;
    ts.push_back(t);
    T perimeter = t[0] + t[1] + t[2];
    for (auto i = 0; i < ts.size(); ++i) {
        t = ts[i];
        vector<T> t1 = {-t[0] + 2*t[1] + 2*t[2], -2*t[0] + t[1] + 2*t[2], -2*t[0] + 2*t[1] + 3*t[2]};
        vector<T> t2 = {t[0] + 2*t[1] + 2*t[2], 2*t[0] + t[1] + 2*t[2], 2*t[0] + 2*t[1] + 3*t[2]};
        vector<T> t3 = {t[0] - 2*t[1] + 2*t[2], 2*t[0] - t[1] + 2*t[2], 2*t[0] - 2*t[1] + 3*t[2]};

        if (t1[0] + t1[1] + t1[2] <= max_perimeter)
            ts.push_back(t1);
        if (t3[0] + t3[1] + t3[2] <= max_perimeter)
            ts.push_back(t3);
        if (t2[0] + t2[1] + t2[2] <= max_perimeter)
            ts.push_back(t2);
    }
    return ts;
}


template <class T>
T APSum(T a, T d, T max) {
  T n = (max - a)/d;
  return n*(2*a + (n-1)*d)/2;
}


template <class T>
T GPSum(T a, T r, T max) {
  T n = floor(log(max/a, r));
  return a(pow(r, n), - 1)/(r - 1);
}

#endif

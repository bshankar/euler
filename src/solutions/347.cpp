#include <iostream>
#include <map>
#include "../lib/euler.h"
using namespace std;
typedef unsigned long ul;

const ul N = 10000000;

template <class T>
T M(T p, T q, T max_, map<T, vector<T> >& powers) {
    // given two primes p, q with p < q
    // find a product p^r*q^s closest to 
    // max_ and less than max_.

    T best = 0;
    vector<T>& vP = powers[p];
    vector<T>& vQ = powers[q];

    int i = vP.size()-1, j = 0;
    while (i >= 0 && j < vQ.size()) {
        while (vP[i]*vQ[j] > max_ && i > 0)
            --i;
        T v = vP[i]*vQ[j];
        if (v <= max_ and v > best)
            best = v;

        // terminate if further powers of j are
        // impossible
        if (!i) 
            return best;

        ++j;
    }

    return best;
}


int main(int argc, const char *argv[]) {
    vector<bool> s = sieve(N);

    // store all possible powers of primes
    map<ul, vector<ul> > powers; 
    for (ul i = 2; i < N/2; ++i) {
        if (s[i-2]) continue;
        vector<ul> kVec;
        ul k = i;
        while (k < N) {
            kVec.push_back(k);
            k *= i;
        }
        powers[i] = kVec;
    }

    // sum all possible M's
    ul sum_ = 0;
    for (ul i = 2; i < N; ++i) {
        if (s[i-2]) continue;
        if (i*(i+1) > N) break;
        for (ul j = i+1; j < N; ++j) {
            if (s[j-2]) continue;
            if (i*j > N) break;
            sum_ += M(i, j, N, powers);
        }
    }
    cout << sum_ << endl;
}

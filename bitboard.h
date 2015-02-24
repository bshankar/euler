#include <iostream>
using namespace std;

template <class T>
int popcount(T x) {
    // optimized for sparse bitboards
    // count the number of 1s
    // in the bitboard n

    int count = 0;
    while (x) {
        ++count;
        x &= x - 1; // reset LS1B
    }
    return count;
}

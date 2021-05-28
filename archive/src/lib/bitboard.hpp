#ifndef BITBOARD_H
#define BITBOARD_H

template<class T>
int popcount(T x) {
    int count = 0;
    while (x) {
        ++count;
        x &= x - 1; // reset LS1B
    }
    return count;
}

#endif

#include <iostream>
#include "prime.h"
#include <cstdlib>
using namespace std;
typedef unsigned long ul;

template<class T>
T f(T n) {
    // last k non zero digits of n!

    T p = pow(10, 6);
    T part1 = pow((ul) 2, n/2-n/5+1, p);
    T part2 = 1;

    for (int i = 3; i < n; i += 2)
        if (i % 25 != 0)
            part2 = part2*i % p;
   
    return (part1*part2) % p;
}

int main(int argc, const char *argv[]) {
    cout << f((ul) atoi(argv[1])) << endl; 
    return 0;
}

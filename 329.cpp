#include <iostream>
#include "prime.h"
#include <gmpxx.h>
typedef mpq_class mpq;
using namespace std;

#define TARGET "PPPPNNPPPNPPNPN"
const vector<bool> nos = sieve(500);
mpq total_prob = 0;

bool is_prime(int n) {
    if (n == 0 || n == 1)
        return false;
    return !nos[n-2];
}

mpq get_prob(int n, char croak) {
    if ((is_prime(n) && croak == 'P') ||
        (!is_prime(n) && croak == 'N'))
        return mpq(2, 3);
    return mpq(1, 3);
}

void jump(int start, string croaks, mpq probability) {
    if (croaks == TARGET) {
        total_prob += probability;
        return;
    }

    // valid croaks so far
    // jump left and then right 
    char target = TARGET[croaks.size()];
    mpq jump_prob = (start-1 && start < 500) ? mpq(1, 2) : mpq(1);
    if (start-1)
        jump(start-1, croaks + target, 
                probability*jump_prob*get_prob(start-1, target));

    if (start < 500)
        jump(start+1, croaks + target, 
                probability*jump_prob*get_prob(start+1, target));
}


int main() {
    string croaks;
    mpq tp = 0;
    for (auto i = 1; i <= 500; ++i) {
        // start jumping from here
        jump(i, croaks + TARGET[0], get_prob(i, TARGET[0])); 
        tp += total_prob;
        total_prob = 0;
    }
    tp /= 500;
    tp.canonicalize();
    cout << tp << endl;
}

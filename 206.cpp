#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
typedef unsigned long ul;

#define MAX 19293949596979899

bool isMatching(ul n) {
    // check if n fits the pattern
    int k = 9;
    while (n && k > 0) {
        if (n % 10 != k)
            return false;
        n /= 100;
        --k;
    }
    if (!k)
        return true;
    return false;
}

int main(int argc, char *argv[]) {
    // the answer ends with 30 or 70
    ul m = (ul) sqrt(MAX)/10;

    while (1) {
        ul m_ = m*10 + 3;
        ul m__ = m*10 + 7;

        if (isMatching(m_*m_)) {
            cout << m_*10 << endl;
            break;
        }

        if (isMatching(m__*m__)) {
            cout << m__*10 << endl;
            break;
        }
        --m;
    }
}

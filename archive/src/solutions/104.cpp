#include <iostream>

using namespace std;
typedef unsigned long ul;


bool isPan(ul n) {
    // is 1-9 pandigital?
    int mask = 0;
    for (int i = 0; i < 9; ++i) {
        mask |= 1 << (n % 10);
        n /= 10;
    }

    return mask == 0b1111111110;
}

int main() {
    ul n = 1, n_ = 1, m = 1000000000, k = 2; // holds last 9 digits
    double nd = 1.0, nd_ = 1.0; // holds first 9 digits
    while (1) {
        ul tmp = n;
        n = (n + n_) % m;
        n_ = tmp;

        double tmpd = nd;
        nd = (nd + nd_);
        nd_ = tmpd;

        while (nd > 10 && nd_ > 10) {
            nd /= 10;
            nd_ /= 10;
        }

        ++k;

        if (isPan(n)) {
            double ndd = nd, m_ = m/10;
            while (ndd < m_)
                ndd *= 10;
            ul ndi = ndd;
            if (isPan(ndi)) {
                cout << k << endl;
                break;
            }
        }
    }
}

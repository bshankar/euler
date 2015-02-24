#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include "prime.h"

typedef short s;
typedef unsigned short us;
typedef unsigned int ui;
typedef unsigned long ul;
using namespace std;

int main() {
    string s = "1234567"; // nothing higher
    ul max = 0;
    while (next_permutation(s.begin(), s.end())) {
        stringstream ss(s);
        ul k;
        ss >> k;
        if (fermat(k))
            max = k;
    }
    cout << max << endl;
}


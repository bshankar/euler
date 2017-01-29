#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isBouncy(int n) {
    string nstr = to_string(n);
    string nstr_ = nstr;
    sort(nstr_.begin(), nstr_.end());
    string nstr__ = nstr_;
    reverse(nstr__.begin(), nstr__.end());
    if (nstr == nstr_ || nstr == nstr__)
        return false;
    return true;
}

int main() {
    int n = 1, bouncy = 0;
    while (bouncy*100 != n*99) {
        ++n;
        if (isBouncy(n))
            ++bouncy;
    }
    cout << n << endl;
}

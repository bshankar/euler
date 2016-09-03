#include "palindrome.h"
#include <vector>
#include <algorithm>
using namespace std;
typedef unsigned long ul;

const ul N = 100000000;
const ul M = 2000;

int main() {
    vector<ul> sos;
    ul s = 1, i = 2;
    while (s < M * N) {
        sos.push_back(s);
        s += i * i;
        ++i;
    }

    ul pal = 1;
    unsigned long ans = 0;
    string pal_str;
    while (pal < N) {
        if (!binary_search(sos.begin(), sos.end(), pal))
            for (auto i = upper_bound(sos.begin(), sos.end(), pal);
                    i != sos.end() && *(i + 1) - *i < pal; ++i) {
                if (binary_search(sos.begin(), i - 1, *i - pal)) {
                    ans += pal;
                    break;
                }
            }
        else
            ans += pal;

        // go to next palindrome
        pal_str = to_string(pal);
        next_palindrome(pal_str);
        pal = stoi(pal_str);
    }
    // exclude 1 from the answers
    cout << ans - 1 << endl;
}

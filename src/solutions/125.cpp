#include "palindrome.h"
#include <cmath>
#include <set>

using namespace std;
typedef unsigned long ul;
#define N 100000000

int main() {
    ul ans = 0, sqrtn = sqrt(N) + 1;
    set<ul> answers;

    for (auto a = 1; a < sqrtn; ++a)
        for (auto k = 1; k < sqrtn; ++k) {
            ul n = (k + 1)*a*a + k*(k + 1)*a + k*(k + 1)*(2*k + 1)/6;
            if (n > N)
                break;
            if (is_palindrome(n) && answers.find(n) == answers.end()) {
                ans += n;
                answers.insert(n);
            }
        }
    cout << ans << endl;
}

#include "../lib/euler.h"
#include "palindrome.h"
#include <map>
using namespace std;

int main(int argc, char *argv[]) {
    const ul N = 1000;
    vector<ul> cubes;
    map<string, us> count;

    for (auto i = 0; i < N; ++i)
        cubes.push_back(i*i*i);

    int found_palindromes = 0;
    string cp = "11"; // current palindrome
    ul icp = stoul(cp),
       ans = 0;

    while (found_palindromes < 5) {
        for (auto cube: cubes) {
            if (cube >= icp)
                break;
            if (is_square(stoul(cp) - cube)) {
                ++count[cp];

                if (count[cp] == 4) {
                    cout << "Found a palindrome " << cp << endl;
                    ans += icp;
                    ++found_palindromes;
                }
            }
        }
        cp = next_palindrome(cp);
        icp = stoul(cp);
    }
    cout << ans << endl;
}

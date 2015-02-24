#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

typedef short s;
typedef unsigned short us;
typedef unsigned int ui;
typedef unsigned long ul;
using namespace std;

int main() {
    ul sum = 0;
    string s = "0123456789";
    ui d[] = {0, 2, 3, 5, 7, 11, 13, 17};
    while (next_permutation(s.begin(), s.end())) {
        bool sat = true;
        if (s[0] == '0')
            continue;
        for (int i = 1; i < 8; ++i) {
            string s1 = s.substr(i, 3);
            if (stoi(s1) % d[i]) {
                sat = false;
                break;
            }
        }
        if (sat) {
            stringstream ss(s);
            ul s_;
            ss >> s_;
            sum += s_;
        }
    }
    cout << sum << endl;
}

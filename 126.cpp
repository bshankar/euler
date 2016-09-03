#include <iostream>
using namespace std;
#define N 1000

int main(int argc, char *argv[]) {
    int count[1000000] = {};

    for (auto a = 1; a < N; ++a) {
        for (auto b = 1; b <= a; ++b) {
            for (auto c = 1; c <= b; ++c) {
                auto n = 2 * (a * b + b * c + c * a);
                if (n >= 1000000)
                    break;
                ++count[n];
                if (n == 78)
                    cout << a << " " << b << " " << c << endl;
            }
        }
    }

    for (auto i = 0; i < 1000000; ++i)
        if (count[i] == 10) {
            cout << i << endl;
            break;
        }
    cout << count[46] << endl;
}

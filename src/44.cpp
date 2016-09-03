#include <iostream>
#include <cmath>
using namespace std;

template <class T>
bool isPentagonal(T k) {
    // 3n^2 - n - 2k = 0
    // (+1 +- sqrt(1 + 24k))/6
    double b24ac = sqrt(1 + 24*k);
    if (ceil(b24ac) == floor(b24ac) and 
       (1 + T(b24ac)) % 6 == 0)
        return true;
    return false;
}

int main() {
    // 3n^2 - n - 2k = 0
    //P(n+1) = 2(3n + 1) + P(n)
    const int N = 8000000;
    bool *pentagonal = new bool[N];
    pentagonal[1] = true;
    for (int i = 2; i < N; ++i)
        if (isPentagonal(i))
            pentagonal[i] = true;

    for (int i = 2; i < N; ++i) {
        if (!pentagonal[i])
            continue;
        for (int j = i+1; j < N; ++j) {
            if (!pentagonal[j])
                continue;

            if (pentagonal[j-i] and isPentagonal(i+j)) {
                cout << j-i << endl;
                delete[] pentagonal;
                return 0;
            }
        }
    }
}

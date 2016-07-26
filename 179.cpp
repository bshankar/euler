#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef unsigned int ui;

#define N 10000000

int main(int argc, char *argv[]) {
    vector<ui> divisors(N);
    vector<ui> tps(N); // powers of 2
    divisors[0] = 0;
    divisors[1] = 1;
    divisors[2] = divisors[3] = 2;
    divisors[4] = 3;

    tps[2] = 1; tps[4] = 2;

    ui ans = 1; // 2 and 3
    for (int i = 4; i < N-1; i += 2) {
        // calculate divisors of i + 1
        int k = i+1;
        for (int j = 3; j < sqrt(i+1) + 1; j += 2) {
            ui exponent = 0;
            while (k % j == 0) {
                ++exponent;
                k /= j;
            }
            if (exponent) {
                divisors[i+1] = divisors[(i+1)/j]*(exponent+1)/exponent; 
                break;
            }
        }
        // is ipo a prime?
        if (!divisors[i+1])
            divisors[i+1] = 2;

        // calculate divisors of i + 2
        ui tp = tps[(i+2)/2]+1;
        divisors[i+2] = divisors[(i+2)/2]*(tp + 1)/tp;
        tps[i+2] = tp;

        if (divisors[i] == divisors[i+1])
            ++ans;

        if (divisors[i+1] == divisors[i+2])
            ++ans;
    }
    cout << ans << endl;
}

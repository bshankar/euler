#include "prime.h"
using namespace std;

#define N 51 // len of the row
#define TT 5 // 2, 3, 4 tile types

int main(int argc, char *argv[]) {
    // tiling ways
    ul tw[N][TT] = {};

    // initial values
    tw[2][2] = 1;
    tw[3][2] = 2;
    tw[3][3] = 3;

        for (int len = 4; len < N; ++len) {
            for (int t = 2; t < TT; ++t) {
                tw[len][t] = len - t + 1 + tw[len][t-1];
                for (int s = 0; s < len - t; ++s)
                    if (len - s - t >= 2) 
                        tw[len][t] += tw[len - s - t][min(len - s - t, TT-1)];
            }
        }

    // include empty
    cout << tw[N-1][TT-1] + 1 << endl;
}

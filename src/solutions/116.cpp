#include "../lib/euler.hpp"
using namespace std;

#define N 51// len of the row
#define TT 5 // 2, 3, 4 tile types

int main(int argc, char *argv[]) {
    // tiling ways
    ul tw[N][TT] = {};

    // initial values
    tw[2][2] = tw[3][3] = tw[4][4] = 1;

    for (int t = 2; t < TT; ++t)
        for (int len = 3; len < N; ++len) {
            tw[len][t] = len - t + 1;
            for (int s = 0; s < len - t; ++s)
                if (len - s - t >= 2) 
                    tw[len][t] += tw[len - s - t][t];
        }

    cout << tw[N-1][2] + tw[N-1][3] + tw[N-1][4] << endl;
}

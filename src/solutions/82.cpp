#include <iostream>
#include <fstream>
using namespace std;
typedef unsigned long ul;
typedef unsigned int ui;

#define N 80
#define INF 4294967295
ul M[N][N], min_sums[N][N];

int main() {
    ifstream file("82.txt");
    for (auto i = 0; i < N; ++i)
        for (auto j = 0; j < N; ++j) {
            file >> M[i][j];
            min_sums[i][j] = INF;
        }

    // Initialize values
    for (auto i = 0; i < N; ++i)
        min_sums[i][N-1] = M[i][N-1];

    for (auto j = N-2; j >= 0; --j) {
        for (auto i = 0; i < N; ++i) {
            // go directly right
            min_sums[i][j] = min_sums[i][j+1];
            ul up = INF, down = INF;
            // go up right
            auto i_ = i-1,
                 col_sum = 0;
            while (i_ >= 0) {
                col_sum += M[i_][j];
                up = min(up, min_sums[i_][j+1] + col_sum);
                --i_;
            }
            // go down right
            i_ = i+1;
            col_sum = 0;
            while (i_ < N) {
                col_sum += M[i_][j];
                down = min(down, min_sums[i_][j+1] + col_sum);
                ++i_;
            }
            min_sums[i][j] = min(min(min_sums[i][j], up), down) + M[i][j];
        }
    }

    // find the minimum sum path
    ul ans = INF;    
    for (auto i = 0; i < N; ++i)
        if (min_sums[i][0] < ans)
            ans = min_sums[i][0];

    cout << ans << endl;
}

#include <iostream>
using namespace std;
typedef unsigned long ul;

#define N 50
#define MIN_BLOCK_SIZE 3

int main() {
    ul c[N+1][N+1] = {}; // count (n, max_block)
    c[MIN_BLOCK_SIZE][MIN_BLOCK_SIZE] = 1;

    // If n is the length of the row and 
    // b is the maximum size of a block
    // count(n, b) = count(n-b, b) + count(n, b-1)
    // count(n-b, b) has a non trivial implementation
    // as the location of the block is also considered
    for (int n = MIN_BLOCK_SIZE + 1; n <= N; ++n)
        for (int b = MIN_BLOCK_SIZE; b <= n; ++b) {
            c[n][b] = c[n][b-1] + n-b+1;

            for (auto start = 1; start <= n-b+1; ++start) {
                auto n_r = n - start - b; // right len

                if (n_r >= MIN_BLOCK_SIZE)
                    if (n_r < b)
                        c[n][b] += c[n_r][n_r];
                    else
                        c[n][b] += c[n_r][b];
            }
        }

    // include the empty row
    cout << c[N][N] + 1 << endl;
}

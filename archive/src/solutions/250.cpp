#include "../lib/euler.hpp"
using namespace std;

#define N 250
#define NN 250250
#define MOD 10000000000000000

int main(int argc, char *argv[]) {
    vector<ul> freq(N); // freq of each remainder

    for (ul i = 1; i <= NN; ++i)
        ++freq[pow(i, i, (ul) N)];

    // count the # of subsets % 10^16
    vector<vector<ul>> p(N+1, vector<ul>(NN+1));
    for (auto i = 1; i <= freq[1]; ++i)
        ++p[1][i];

    for (auto n = 2; n <= N; ++n) {
        int item = 1;
        for (auto r = 1; r < N; ++r)
            for (auto f = 0; f < freq[r]; ++f) {
                if (n >= r)
                    p[n][item] = p[n-r][item-1];
                p[n][item] = (p[n][item] + p[n][item-1]) % MOD;
                ++item;
            }
    }
    cout << (p[N][NN-freq[0]] + freq[0]) % MOD << endl;
}

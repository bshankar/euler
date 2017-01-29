#include <iostream>
#include <fstream>
using namespace std;
typedef unsigned long ul;
typedef unsigned int ui;

#define N 80
#define INF 4294967295
ul M[N][N], min_sums[N][N];

int main() {
    ifstream file("83.txt");
    for (auto i = 0; i < N; ++i)
        for (auto j = 0; j < N; ++j) {
            file >> M[i][j];
            min_sums[i][j] = INF;
        }
}

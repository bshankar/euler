#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef unsigned int ui;
#define N 100000

int main() {
    vector<ui> rad(N+1);
    rad[0] = 0; rad[1] = 1;
    for (auto i = 2; i <= N; ++i) {
        if (!rad[i]) {
            for (auto j = 2*i; j <= N; j += i) {
                if (!rad[j]) rad[j] = i;
                else rad[j] *= i;
            }
            rad[i] = i;
        }
    }
    // fill an empty array with nos
    vector<ui> indices(N+1);
    for (auto i = 0; i < N+1; ++i)
        indices[i] = i;

    sort(indices.begin(), indices.end(), 
            [&rad](ui i, ui j){return rad[i] < rad[j] || 
            (rad[i] == rad[j] && i < j);});

    cout << indices[10000] << endl;
}

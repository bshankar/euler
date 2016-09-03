#include "prime.h"
using namespace std;

#define N 100000000

bool can_tile(vector<int> ppt) {
    return  !(ppt[2] % int(abs(ppt[0] - ppt[1])));
}

int main(int argc, char *argv[]) {
    vector<vector<int>> ppts =  primitive_pythagorean_triples(N);
    int ans = 0;
    for (auto ppt: ppts) {
        if (can_tile(ppt)) {
            int perimeter = ppt[0] + ppt[1] + ppt[2];
            ans += N/perimeter;
        }
    }
    cout << ans << endl;
}

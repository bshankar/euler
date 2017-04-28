#include "../lib/euler.hpp"
using namespace std;

#define N 1000000000

int main(int argc, char *argv[]) {
    vector<vector<int> > ppts = primitive_pythagorean_triples(N);
    for (auto ppt: ppts)
        if (abs(2*min(ppt[0], ppt[1]) - max(ppt[0], ppt[1])) == 1)
            cout << ppt[0] << " " << ppt[1] << " " << ppt[2] << endl;
}

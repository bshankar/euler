#include "vector_utils.h"
#include <algorithm>
using namespace std;
typedef unsigned char uc;
typedef unsigned long ul;

// start with 40561817703823564929
// and try to find other primitive sets that
// create numbers divisible by 11

vector<int> pos = {1, 1, 2, 2, 3, 4, 4, 5, 5, 7};
vector<int> neg = {0, 0, 3, 6, 6, 7, 8, 8, 9, 9};

int main() {
    print(pos);
    print(neg);

    for (auto i = 0; i < 10; ++i)
        for (auto j = 1 + 1; j < 10; ++j)
            for (auto k = 0; k < 10; ++k)
                for (auto l = k + 1; k < 10; ++k)
                    if (pos[i] + pos[j] - neg[k] - neg[l] % 11 == 0) {
                        int tmp_i = pos[i],
                            tmp_j = pos[j];
                        pos[i] = neg[k];
                        pos[j] = neg[l];
                        neg[k] = tmp_i;
                        neg[l] = tmp_j;
                        sort(pos.begin(), pos.end());
                        sort(neg.begin(), neg.end());
                        cout << endl;
                        print(pos);
                        print (neg);
                    }
}

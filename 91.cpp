#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int ans = 0, N = 50;

    for (int x1 = 0; x1 <= N; ++x1) {
        for (int y1 = 0; y1 <= N; ++y1) {
            for (int x2 = 0; x2 <= N; ++x2) {
                for (int y2 = 0; y2 <= N; ++y2) {
                    if (x1 == x2 && y1 == y2)
                        // ensure 2 different points
                        continue;
                    int OA = x1*x1 + y1*y1,
                        OB = x2*x2 + y2*y2,
                        AB = (x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1);

                    if (OA && OB && AB && 
                       (OA + OB + AB == 2*max(max(OA, OB), AB)))
                        ++ans;
                }
            }
        }
    }
    // each triangle was counted twice
    // because of interchangeability of (x1, y1) and (x2, y2)
    cout << ans/2 << endl;
}

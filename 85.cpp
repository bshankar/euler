#include <iostream>
#include <cmath>
using namespace std;

template <class T>
T cR(T len, T br) {
    // count the number of rectangles 
    // inside a rectangle of len*br
    T count = 0;
    for (int l = 1; l < len+1; l++) 
        for (int b = 1; b < br+1; b++) 
            count += (len - l + 1)*(br - b + 1);

    return count;
}

int main() {
    int N = 2000000;
    int min_diff = N, ans_len, ans_br;

    for (int i = 1; i < 2000; i++) {
        for (int j = 1; j < i; j++) {
            if (cR(i, j) > N + min_diff)
                break;

            if (abs(cR(i, j) - N) < min_diff) {
                min_diff = abs(cR(i, j) - N);
                ans_len = i;
                ans_br = j;
            }
        }
    }
    cout << "A " << ans_len << "x" << ans_br << " rectangle of area " 
         << ans_len*ans_br << " has " << cR(ans_len, ans_br)
         << " rectangles." << endl;
}

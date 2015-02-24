#include <iostream>
using namespace std;
typedef unsigned long ul;

ul next(ul n) {
    ul sum = 0;
    while (n) {
        sum += (n % 10)*(n % 10);
        n /= 10;
    }
    return sum;
}

int main() {
    ul N = 10000000;
    bool *en = new bool[N];
    
    for (ul i = 2; i < N; ++i) {
        ul i_ = i;
        while (i_ != 1 && i_ != 89) {
            i_ = next(i_);
            if (i_ < i) {
                // precomputed
                if (en[i_]) i_ = 89;
                else i_ = 1;
                break;
            }
        }
            
        if (i_ == 89) en[i] = true;
    }
    
    ul ans = 0;
    
    for (ul i = 0; i < N; ++i)
        if (en[i]) ++ans;
    
    cout << ans << endl;
    delete[] en;
}

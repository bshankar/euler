#include <iostream>
#include <gmpxx.h>
using namespace std;

int main() {
    int N = 101;
    int greater = 0;
    mpz_class C[N][N] = {};
    
    for (int i = 0; i < N; ++i)
        C[i][0] = C[i][i] = 1;
        
    for (int n = 1; n < N; ++n) {
        for (int k = 1; k <= n; ++k) {
            C[n][k] = C[n-1][k-1] + C[n-1][k];
            
            if (C[n][k] > 1000000)
                ++greater;
        }
    }
    cout << greater << endl;
}

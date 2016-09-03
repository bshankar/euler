#include <iostream>

typedef short s;
typedef unsigned short us;
typedef unsigned int ui;
typedef unsigned long ul;
using namespace std;

int c(int n, int *k, int max) {
    if (n == 0)
        return 1;
    
    if (max < 0 || n < 0)
        return 0;
    
    return c(n-k[max], k, max) + 
            c(n, k, max-1);
}

int main() {
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 200};
    cout << c(200, coins, 7) << endl;
}


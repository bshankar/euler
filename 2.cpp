#include <iostream> 
 
typedef short s;
typedef unsigned short us;
typedef unsigned int ui;
typedef unsigned long ul;
using namespace std; 
 
int main() {
    ui i = 1, j = 2, ans = 2; // add 2 beforehand
    while (j < 4000000) {
        i = i + j;
        j = i + j;
        if (i % 2 == 0)
            ans += i;
        if (j % 2 == 0)
            ans += j;
    }
    cout << ans << endl;
}


#include <iostream> 

typedef short s;
typedef unsigned short us;
typedef unsigned int ui;
typedef unsigned long ul;
using namespace std; 

int main() {
    ul N = 600851475143;
    ul pf = 0;
    for (ul i = 3; i <= N; i += 2){
        while (N % i == 0) {
            N /= i;
            pf = i;
        }
    }
    cout << pf << endl;
}


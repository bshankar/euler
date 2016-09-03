#include <iostream>

typedef short s;
typedef unsigned short us;
typedef unsigned int ui;
typedef unsigned long ul;
using namespace std;

int main() {
    int sumOfSquares = 0;
    int squareOfSum = 0;
    
    for (int i = 1; i < 101; i++){
        sumOfSquares += i*i;
    }
    // use formula for squaresOfSum
    squareOfSum = 101*100/2;
    squareOfSum *= squareOfSum;
    cout << squareOfSum - sumOfSquares << endl;
}


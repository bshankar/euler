#include "../lib/euler.h"

string euler6() {
    // use formula for squaresOfSum
    int squareOfSum = 101*100/2;
    squareOfSum *= squareOfSum;
    int sumOfSquares = 100*101*201/6;
    return to_string(squareOfSum - sumOfSquares);
}


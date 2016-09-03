#include "prime.h"
#include <iomanip>
using namespace std;

// maximum length of non-bouncy number
#define N 100.0 
#define B 10.0 // number base

int main() {
    // After a long calculation
    cout << setprecision(15) 
         << combinations((N+B-1), B-1)*(N + 2*B)/B 
            - (B*N + 2) << endl;
}

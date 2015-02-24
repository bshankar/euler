#include <iostream>
#include <cmath>
using namespace std;

template <class T>
bool isHexagonal(T k) {
    // 2n^2 - n - k = 0
    // (+1 +- sqrt(1 + 8k))/(4)
    double b24ac = sqrt(1 + 8*k);
    if (ceil(b24ac) == floor(b24ac) and 
       (1 + T(b24ac)) % 4 == 0)
        return true;
    return false;
}

template <class T>
bool isPentagonal(T k) {
    // 3n^2 - n - 2k = 0
    // (+1 +- sqrt(1 + 24k))/6
    double b24ac = sqrt(1 + 24*k);
    if (ceil(b24ac) == floor(b24ac) and 
       (1 + T(b24ac)) % 6 == 0)
        return true;
    return false;
}

int main() {
    unsigned long tn = 1, k = 1;
    while (1) {
        k += 1;
        tn += k;
        if (isHexagonal(tn) && isPentagonal(tn) && tn > 40755) {
            cout << tn << endl;
            break;
        }
    }
}

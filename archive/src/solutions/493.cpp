#include <iostream>
#include <iomanip>
#include "../lib/euler.hpp"
#include <gmpxx.h>
using namespace std;

int main(int argc, const char *argv[]) {
    double numerator, denominator;
    denominator = combinations(70.0, 20.0);
    numerator = 0;

    // Using inclusion exclusion
    for (double n = 2; n <= 7; ++n) {
        double factor = n*combinations(7.0, n);
        double add = combinations(10*n, 20.0);
        for (double k = n-1; k >= 2; --k)
            add += pow((-1), (int) (n-k))*combinations(n, k)*combinations(10*k, 20.0);

        numerator += factor*add;
    }

    cout << fixed << setprecision(9) << numerator/denominator << endl;
    
    // Easier method: probability of each color existing 
    // in the chosen set of balls is 1 - C(60, 20)/C(70, 20)
    cout << "More precisely: ";
    mpq_class a = 60, b = 70, c = 20;
    a = 7*(1 - combinations(a, c)/combinations(b, c));
    a.canonicalize();
    cout << a << endl;
}

#include <iostream>
#include <limits>
using namespace std;
typedef unsigned long ul;

int main(int argc, const char *argv[]) {
    
    double pete[37] = {};
    double colin[37] = {};

    ul pete_total = 0, colin_total = 0;

    for (int i = 1; i < 5; ++i)
        for (int j = 1; j < 5; ++j)
            for (int k = 1; k < 5; ++k)
                for (int l = 1; l < 5; ++l)
                    for (int m = 1; m < 5; ++m)
                        for (int n = 1; n < 5; ++n)
                            for (int o = 1; o < 5; ++o)
                                for (int p = 1; p < 5; ++p)
                                    for (int q = 1; q < 5; ++q) {
                                        ++pete[i+j+k+l+m+n+o+p+q];
                                        ++pete_total;
                                    }

    for (int i = 1; i < 7; ++i)
        for (int j = 1; j < 7; ++j)
            for (int k = 1; k < 7; ++k)
                for (int l = 1; l < 7; ++l)
                    for (int m = 1; m < 7; ++m)
                        for (int n = 1; n < 7; ++n) {
                            ++colin[i+j+k+l+m+n];
                            ++colin_total;
                        }
    
    for (int i = 0; i < 37; ++i) {
        pete[i] /= pete_total;
        colin[i] /= colin_total;
    }

    double pete_wins = 0;

    for (int i = 0; i < 37; ++i)
        for (int j = 0; j < i; ++j)
            pete_wins += pete[i]*colin[j];

    cout.precision(numeric_limits<double>::digits10);
    cout << pete_wins << endl;
}

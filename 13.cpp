#include <iostream>
#include <fstream>
#include <gmpxx.h>

typedef short s;
typedef unsigned short us;
typedef unsigned int ui;
typedef unsigned long ul;
using namespace std;

int main() {
    ifstream file("13.txt");
    string s;
    mpz_class ans = 0;
    
    while (getline(file, s)) {
        mpz_class i(s.c_str());
        ans += i;
    }
    cout << ans << endl;
}


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>

typedef short s;
typedef unsigned short us;
typedef unsigned int ui;
typedef unsigned long ul;
using namespace std;

int main() {
    ifstream file("18.txt");
    string s, s1;
    int a[15] = {}, b[15] = {},
        c[15] = {}, i = 0;

    while (getline(file, s)) {
        i = 0;
        stringstream ss(s);
        while (ss >> a[i])
            ++i;
            
        // b ->  best sums so far
        // a ->  new row
        // c -> current best sum
        c[0] = a[0] + b[0];
        
        for (int i = 0; i < 15; i++) {
            if (b[i+1] == 0) {
                // end of this row
                c[i+1] = b[i] + a[i+1];
                break;
            }
            c[i+1] = max(b[i], b[i+1]) + a[i+1];
        }
        for (int i = 0; i < 15; i++) {
            b[i] = c[i];
        }
    }
    int max_ = 0;
    for (int i = 0; i < 15; i++) {
        if (max_ < b[i])
            max_ = b[i];
    }
    cout << max_ << endl;
}

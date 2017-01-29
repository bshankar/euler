#include <iostream>
#include <fstream>
#include <string>

typedef short s;
typedef unsigned short us;
typedef unsigned int ui;
typedef unsigned long ul;
using namespace std;

int main() {
    ifstream file("8.txt");
    string s, sFull;
    while (getline(file, s))
        sFull += s;
    
    ul maxProduct = 0;
    
    for (ui i = 0; i < 1000-13; ++i) {
        s = sFull.substr(i, 13);
        ul product = 1;
        for (auto j = s.begin(); j != s.end(); ++j) {
            product *= *j - '0';
        }
        if (product > maxProduct) {
            maxProduct = product;
            //cout << maxProduct << endl;
        }
    }
    cout << maxProduct << endl;
}


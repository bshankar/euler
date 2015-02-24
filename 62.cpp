#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    unsigned long k = 300;
    map<string, int> perms; // count perms of each cube
    map<string, unsigned long> baseCube;
    
    while (true) {
        unsigned long k3 = k*k*k;
        string p = to_string(k3);
        sort(p.begin(), p.end());
        ++perms[p];
        
        if (!baseCube[p])
            baseCube[p] = k3;
        
        if (perms[p] == 5) {
            cout << baseCube[p] << endl;
            break;
        }
        ++k;
    }
}


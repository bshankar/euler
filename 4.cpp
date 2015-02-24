#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

typedef short s;
typedef unsigned short us;
typedef unsigned int ui;
typedef unsigned long ul;
using namespace std;

int main() {
    int max = 0;
    
    for (int i = 100; i < 1000; ++i){
        for (int j = i; j < 1000; ++j){
            string ijstr = to_string(i*j);
            string ijstr_ = ijstr;
            reverse(ijstr.begin(), ijstr.end());
            if (ijstr == ijstr_) {
                stringstream ss(ijstr_);
                int a;
                ss >> a;
                if (a > max) {
                    max = a;
                }
            }
        }
    }
    cout << max << endl;
}

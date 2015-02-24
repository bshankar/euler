#include <iostream>

typedef short s;
typedef unsigned short us;
typedef unsigned int ui;
typedef unsigned long ul;
using namespace std;

int main() {
    string s;
    for (int i = 1; i < 1000000; i++){
        s += to_string(i);
    }
    
    ui product = 1;
    for (int i = 1; i < 1000001; i *= 10){
        product *= s[i-1] - '0';
    }
    cout << product << endl;
}


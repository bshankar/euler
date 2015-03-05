#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int roman_to_int(string n) {
    // convert roman numeral to integer
    if (!n.size())
        return 0;

    int nInt = 0;

    for (int i = 0; i < n.size(); ++i) {
        if (n[i] == 'M' || n[i] == 'D') {
            if (n[i] == 'M')
                nInt += 1000;
            else
                nInt += 500;
            if (i && n[i-1] == 'C') 
                nInt -= 200;
        }

        else if (n[i] == 'C' || n[i] == 'L') {
            if (n[i] == 'C')
                nInt += 100;
            else
                nInt += 50;
            if (i && n[i-1] == 'X')
                nInt -= 20;
        }

        else if (n[i] == 'X' || n[i] == 'V') {
            if (n[i] == 'X')
                nInt += 10;
            else
                nInt += 5;
            if (i && n[i-1] == 'I')
                nInt -= 2;
        }

        else 
            nInt += 1;
    }
    return nInt;
}


string int_to_roman(int n) {
    string nRom;

    for (int i = 0; i < n/1000; ++i)
        nRom += "M";
    n %= 1000;

    if (n >= 900) {
        nRom += "CM";
        n -= 900;
    }
    else if (n/100 == 4) {
        nRom += "CD";
        n -= 400;
    }
    else if (n >= 500) {
        nRom += "D";
        n -= 500;
    }
    for (int i = 0; i < n/100; ++i)
        nRom += "C";
    n %= 100;

    if (n >= 90) {
        nRom += "XC";
        n -= 90;
    }
    else if (n/10 == 4) {
        nRom += "XL";
        n -= 40;
    }
    else if (n >= 50) {
        nRom += "L";
        n -= 50;
    }
    for (int i = 0; i < n/10; ++i)
        nRom += "X";
    n %= 10;

    if (n == 9) {
        nRom += "IX";
        n -= 9;
    }
    else if (n == 4) {
        nRom += "IV";
        n -= 4;
    }
    else if (n >= 5) {
        nRom += "V";
        n -= 5;
    }
    for (int i = 0; i < n; ++i)
        nRom += "I";
        
    return nRom;
}


int main(int argc, const char *argv[]) {
    ifstream file("89.txt");
    string s;
    int ans = 0;
    while (file >> s) 
        ans += s.size() - int_to_roman(roman_to_int(s)).size();

    cout << ans << endl;
}

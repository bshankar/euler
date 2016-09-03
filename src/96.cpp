#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
typedef unsigned int ui;
using namespace std;

int sum_ = 0;

bool sameRow(int i, int j) {
    return i/9 == j/9;
}


bool sameCol(int i, int j) {
    return (i-j) % 9 == 0;
}


bool sameBox(int i, int j) {
    return i/27 == j/27 && i%9/3 == j%9/3;
}


void solve(string p) {
    int i = p.find("0");
    if (i == -1) {
        sum_ += atoi(p.substr(0, 3).c_str());
        return;
    }

    ui eliminated = 0;
    for (int j = 0; j < 81; ++j) 
        if (sameRow(i, j) || sameCol(i, j) || sameBox(i, j))
            eliminated |= (1 << (p[j]-'0'));

    for (int m = 1; m < 10; ++m)
        if (!((1 << m) & eliminated))
            solve(p.substr(0, i) + to_string(m) + p.substr(i+1));
}


int main(int argc, const char *argv[]) {
    ifstream file("96.txt");    

    string puzzle, part;
    while (file >> part) {
        if (part.size() != 9)
            continue;
        puzzle += part;
        if (puzzle.size() == 81) {
            solve(puzzle);
            puzzle.clear();
        }
    }
    cout << sum_ << endl;
    return 0;
}

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;
typedef unsigned char uchar;
typedef unsigned long ul;

#define CLUES 22
#define SIZE 16

struct state {
    uchar clues[CLUES][SIZE];
    uchar matches[CLUES];
    bool space[SIZE][10]; // search space 

    // The subspace we are
    // currently recursing in
    uchar begin;
    uchar end;
    uchar ans[SIZE];
};


bool checkAns(state *s) {
    // check if correct
    for (int i = 0; i < CLUES; ++i) {
        int m = 0;
        for (int j = 0; j < SIZE; ++j) 
            if (s->clues[i][j] == s->ans[j])
                ++m;

        if (m != s->matches[i])
            return false;
    }
    return true;
}


void search(state *s) {
    if (s->begin == SIZE) {
        checkAns(s);
        return;
    }

    for (int i = 0; i < 10; ++i) {
        if (!s->space[s->begin][i])
            continue;

        // choose and place
        // recurse on the smaller problem
        
    }
}


int main(int argc, const char *argv[]) {
    ifstream file("185.txt");
    state *s = new state;

    string str; int m;
    for (int i = 0; i < CLUES; ++i) {
        file >> str >> m;
        for (int j = 0; j < SIZE; ++j) {
            s->clues[i][j] = str[j] - '0';
            if (m)
                s->space[j][str[j]-'0'] = true;
        }
        s->matches[i] = m;
    }

    s->begin = 0;
    s->end = SIZE;

    delete s;
    return 0;
}

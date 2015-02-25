#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;
typedef unsigned char uchar;
typedef unsigned long ul;

#define CLUES 6
#define SIZE 5

struct state {
    uchar clues[CLUES][SIZE];
    uchar matches[CLUES];
    bool space[SIZE][9]; // search space 

    // clue with minimum non zero matches
    uchar min_ = 255;
    uchar minMatches = 100;

    uchar ans[SIZE] = {};
    uchar toBeFilled = SIZE; // still toBeFilled
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


void findMin(state *s) {
    s->min_ = 255;
    s->minMatches = 100;
    for (int i = 0; i < CLUES; ++i) {
        if (s->matches[i] == 1) {
            s->min_ = i;
            return;
        }

        if (s->matches[i] && s->matches[i] < s->minMatches) {
            s->min_ = i;
            s->minMatches = s->matches[i];
        }
    }
}


void printAns(state *s) {
    for (int i = 0; i < SIZE; ++i)
        if (s->ans[i] != 10)
            cout << (int) s->ans[i];
        else
            cout << 'X';
    cout << endl;
}


void search(state *s) {
    if (!s->toBeFilled) {
        if (checkAns(s)) {
            printAns(s);
            exit(0);
        }
        printAns(s);
        return;
    }

    do {
        findMin(s);
        // update the state
        int k = s->min_;
        for (int i = 0; i < SIZE; ++i) {
            uchar v = s->clues[k][i];
            if (s->space[i][v] && s->ans[i] == 10) {
                s->ans[i] = v;
                if (!(--s->matches[k]))
                    // mask the digits from this clue
                    for (int j = 0; j < SIZE; ++j) {
                        uchar d = s->clues[k][j];
                        s->space[j][d] = false;
                    }
                --s->toBeFilled;
                search(s);
                ++s->toBeFilled;
                if ((++s->matches[k]) == 1) {
                    // unmask digits from this clue except the first
                    // as it was eliminated
                    for (int j = 0; j < SIZE; ++j) {
                        if (i == j)
                            continue;
                        uchar d = s->clues[k][j];
                        s->space[j][d] = true;
                    }
                }
               s->ans[i] = 10;
            }
        }
    } while (s->min_ != 255);
}


int main(int argc, const char *argv[]) {
    ifstream file("185_test.txt");
    state *s = new state;

    string str; int m;
    for (int i = 0; i < CLUES; ++i) {
        file >> str >> m;
        for (int j = 0; j < SIZE; ++j) {
            s->clues[i][j] = str[j] - '0';
            s->space[j][str[j]-'0'] = true;
        }
        s->matches[i] = m;
    }

    for (int i = 0; i < CLUES; ++i)
        for (int j = 0; j < SIZE; ++j) 
            if (!s->matches[i]) {
                uchar d = s->clues[i][j];
                s->space[j][d] = false;
            }
   
    for (int i = 0; i < SIZE; ++i)
        s->ans[i] = 10;

    search(s);
    delete s;
}

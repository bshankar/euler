#include <iostream>
#include <fstream>
#include <random>
#include <string>
using namespace std;
typedef unsigned char uchar;
typedef uniform_int_distribution<unsigned long> uid;
typedef uniform_real_distribution<double> urd;

#define SIZE 16
#define CLUES 22
#define MAX_PRESSURE 16

auto const seed = random_device()();
minstd_rand rng(seed);
uid loc(0, SIZE-1);  // location of change
uid digit(0, 9);  // new random digit

struct rules {
    uchar clues[CLUES][SIZE] = {};
    uchar matches[CLUES] = {};
    uchar minEnergy = 255;
    uchar min_[SIZE];
};


int energy(const uchar* n, rules *r) {
    int wrong = 0;

    for (int i = 0; i < CLUES; ++i) {
        int m = 0;
        for (int j = 0; j < SIZE; ++j) 
            if (r->clues[i][j] == n[j])
                ++m;

        wrong += abs(r->matches[i] - m);
    }

    if (wrong < r->minEnergy) {
        r->minEnergy = wrong;
        for (int i = 0; i < SIZE; ++i)
            r->min_[i] = n[i] + '0';
        cout << r->min_ << " " << (int) r->minEnergy << endl;
    }

    if (!wrong)
        exit(0);

    return wrong;
}


void init(uchar* s1) {
    for (int i = 0; i < SIZE; ++i)
        s1[i] = digit(rng); 
}


void hillClimb(rules *r) {
    // a hill climbing algorithm
    // with random jumping to avoid
    // when stuck in a local minima
    
    uchar s1[SIZE]; init(s1);
    int e1 = energy(s1, r);
    int pressure = 0, e2;
    while (1) {

        for (int i = 0; i < SIZE; ++i) {
            // jump to a neighbour with lowest energy
            uchar old = s1[i];
            s1[i] = digit(rng); 
            int e3 = energy(s1, r);
            if (e3 <= e1) 
                e2 = e3;
            else 
                s1[i] = old;
        }
        
        if (e1 == e2) {
            if ((++pressure) == MAX_PRESSURE) {
                    pressure = 0;
                    s1[loc(rng)] = digit(rng);
                    e2 = energy(s1, r);
            } 
        } else
            pressure = 0;

        e1 = e2;
    }

}


int main(int argc, const char *argv[]) {
    ifstream file("185.txt");
    rules *r = new rules;

    string s; int m;
    for (int i = 0; i < CLUES; ++i) {
        file >> s >> m;
        for (int j = 0; j < SIZE; ++j)
            r->clues[i][j] = s[j] - '0';
        r->matches[i] = m;
    }

    hillClimb(r);
    delete r;
}

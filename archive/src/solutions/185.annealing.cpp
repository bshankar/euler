#include <iostream>
#include <fstream>
#include <random>
#include <string>
#include <cmath>
using namespace std;
typedef unsigned char uchar;
typedef uniform_int_distribution<unsigned long> uid;
typedef uniform_real_distribution<double> urd;

#define SIZE 16
#define CLUES 22

auto const seed = random_device()();
minstd_rand rng(seed);
uid index(0, SIZE-1);  // location of change
uid digit(0, 9);       // new random digit
urd rreal(0, 1);       // random real distribution

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


double P(int e1, int e2, double T) {
    if (e1 > e2)
        return 1.0;
    return exp((e1 - e2)/T);
}


void simulatedAnneal(rules *r, int k_max) {
    
    uchar s1[SIZE]; init(s1);
    int e1 = energy(s1, r);
    int e2;
    for (int k = 0; k < k_max; ++k) {
        double T = double(k)/k_max;
        int i = index(rng);
        uchar d = digit(rng);
        uchar old = s1[i];
        s1[i] = d;
        int e2 = energy(s1, r);
        
        if (P(e1, e2, T) > rreal(rng))
            e1 = e2;
        else 
            s1[i] = old;
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

    simulatedAnneal(r, 10000000);
    delete r;
}

#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <ctime>
#include <cmath>
using namespace std;
typedef unsigned long ul;
typedef uniform_int_distribution<ul> uid;

#define MAX 10000000
#define CLUES 22
#define GENES 16
#define CROSSOVER 3
#define MUTATIONS 1.0

auto const seed = random_device()();
default_random_engine rng(seed);
uid space(pow(10, GENES-1), pow(10, GENES)-1); // search space
uid organism(0, MAX-1); // randomly select an organism
uid loc(0, GENES-1);  // location of a mutation on genome
uid locc(0, GENES-CROSSOVER);  // location of a crossover
uid digit(0, 9);    // new random digit

double maxFitness = 0;
string clues[CLUES] = {};
int matches[CLUES] = {};
string g[MAX] = {}; // current generation
double f[MAX] = {};
int generations = 0;

double fitness(int o) {
    // nature measures the fitness of this individual
    double value = 0;

    for (int i = 0; i < CLUES; ++i) {
        int m = 0;
        for (int j = 0; j < GENES; ++j)
            if (clues[i][j] == g[o][j])
                ++m;

        if (m == matches[i])
            ++value;
        else if (m > matches[i])
            value -= 0.05;

    }

    if (value > maxFitness) {
        maxFitness = value;
        cout << g[o] << " " << value << endl;
    } 

    if (value >= 18)
        cout << g[o] << " " << value << endl;

    if (value == CLUES) { 
        cout << "Generations passed: " << generations << endl;
        exit(0); 
    }

    return value;
}


void crossover(int m, int f_) {
    // try a crossover
    int r = locc(rng);
    for (int i = 0; i < CROSSOVER; ++i) {
        string n1_ = g[m], n2_ = g[f_];
        int fit1_ = f[m], fit2_ = f[f_];
        string tmp = g[m].substr(0, r) + g[f_].substr(r, CROSSOVER) + g[m].substr(r+CROSSOVER);
        g[f_]  = g[f_].substr(0, r) + g[m].substr(r, CROSSOVER) + g[f_].substr(r+CROSSOVER);
        g[m] = tmp;

        f[f_] = fitness(f_);
        f[m] = fitness(m);
    }
}


void mutate(int i) {
    // try to apply a mutation
    int r = loc(rng); 
    int v = digit(rng);
    
    while (v == g[i][r])
        v = digit(rng);

    double fit_ = f[i];
    string n_ = g[i];
    g[i][r] = v + '0';
    f[i] = fitness(i);
    if (f[i] < fit_) {
        g[i] = n_;
        f[i] = fit_;
    }

}


void iterate() {
    while (1) {
        // mutations
        for (int m = 0; m < MUTATIONS*MAX; ++m) {
            int who = organism(rng);
            mutate(who);
        }

        // crossing over of highly fit individuals
        for (int i = 0; i < MAX/2 - 1; ++i) 
            crossover(i, MAX-i-1);
        ++generations;
    }
}


void initialize() {
    for (int i = 0; i < MAX; ++i) {
        g[i] = to_string(space(rng));
        f[i] = fitness(i);
    }
}


int main(int argc, const char *argv[]) {

    ifstream file("185.txt");
    string s; int m;
    for (int i = 0; i < CLUES; ++i) {
        file >> s >> m; 
        clues[i] = s;
        matches[i] = m;
    }

    initialize();
    iterate();
}

#ifndef SOLUTION_H
#define SOLUTION_H

// include the library
#include "../lib/euler.h"

#define N 1000
string (*solutions[N])();

// solved problems
#include "1.h"

void initSolutions() {
  solutions[0] = euler1;
}

#endif

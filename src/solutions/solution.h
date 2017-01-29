#ifndef SOLUTION_H
#define SOLUTION_H

// include the library
#include "../lib/euler.h"

#define PROBLEMS 1000
string (*solutions[PROBLEMS])();

// solved problems
#include "1.h"  
#include "2.h"
#include "3.h"
#include "4.h"
#include "5.h"
#include "6.h"
#include "7.h"
#include "8.h"
#include "9.h"
#include "10.h"

void initSolutions() {
  solutions[0] = euler1;
  solutions[1] = euler2;
  solutions[2] = euler3;
  solutions[3] = euler4;
  solutions[4] = euler5;
  solutions[5] = euler6;
  solutions[6] = euler7;
  solutions[7] = euler8;
  solutions[8] = euler9;
  solutions[9] = euler10;
}

#endif

#ifndef SOLUTION_H
#define SOLUTION_H

// include the library
#include "../lib/euler.hpp"

#define PROBLEMS 1000
string (*solutions[PROBLEMS])();

// solved problems
#include "1.hpp"  
#include "2.hpp"
#include "3.hpp"
#include "4.hpp"
#include "5.hpp"
#include "6.hpp"
#include "7.hpp"
#include "8.hpp"
#include "9.hpp"
#include "10.hpp"
#include "54.hpp"
#include "114.hpp"
#include "115.hpp"
#include "129.hpp"
#include "131.hpp"

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
  solutions[53] = euler54;
  solutions[113] = euler114;
  solutions[114] = euler115;
  solutions[128] = euler129;
  solutions[130] = euler131;
}

#endif

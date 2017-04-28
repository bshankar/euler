#include "../lib/euler.hpp"


string euler115() {
  int m = 50, n = 51;
  while (f(m, n) <= 1000000) 
    n *= 10;

  return to_string(n);
}

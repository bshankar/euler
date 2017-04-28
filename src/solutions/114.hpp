#include "../lib/euler.hpp"

MEMOIZATOR(f, long, int, int);


long _f(int m, int n) {

  long solns = 1;

  if (n > m) return solns;

  for (int start = 0; start <= m-n; start++) {
    for (int rowlen = n; rowlen <= m-start; rowlen++) {
      solns += f(m - start - rowlen-1, n);
    }
  }

  return solns;
}


string euler114() {
  return to_string(f(50, 3));
}

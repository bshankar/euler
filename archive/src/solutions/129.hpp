#include "../lib/euler.hpp"

string euler129() {
  ul n = 3;
  while (true) {
    if (n % 5 == 0) {
      n += 2;
      continue;
    }
    
    ul r = 0, R = 1;
    while (R % n) {
      ++r;
      R = (R + pow((ul) 10, r, n)) % n;
    }

    if (r > 1000)
      return to_string(n);
    n += 2;
  }
}

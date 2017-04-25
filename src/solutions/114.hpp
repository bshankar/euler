#include "../lib/euler.hpp"


ul f(int n, int m) {
  // filling a row of size n
  // with tiles of min length m
  if (n <= 0)
    return 0;
  if (n < m)
    return 1;
  if (n == m)
    return 2;

  ul ans = f(n, m + 1);
  for (int i = 0; i < n - m + 1; ++i) {
    ans += f(i-1, m);
    ans += f(n - m, m);
  }
  return ans;
}


string euler114() {
  return to_string(f(7, 3));
}

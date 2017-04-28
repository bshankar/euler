#include "../lib/euler.hpp"


int main() {
  mpz_class a(1);
  for (int i=0; i<1000; i++) 
    a *= 2;

  int ans = 0;
  for (char ch: a.get_str())
    ans += ch - '0';

  cout << "Euler 16: " << ans << endl;
}

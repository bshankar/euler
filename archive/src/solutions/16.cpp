#include "../lib/euler.hpp"


int main() {
  mpz_class base(2), result;
  mpz_pow_ui(result.get_mpz_t(), base.get_mpz_t(), 1000);

  int ans = 0;
  for (char ch: result.get_str())
    ans += ch - '0';

  cout << "Euler 16: " << ans << endl;
}

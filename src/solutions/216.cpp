#include "../lib/euler.hpp"


int main() {
  mpz_class ans = 0;
  for (mpz_class n = 2; n <= 50000000; ++n) {
    mpz_class n_ = 2*n*n - 1;
    if (mpz_probab_prime_p(n_.get_mpz_t(), 10)) {
      ans++;
    }
  }
  std::cout << ans << "\n";
}

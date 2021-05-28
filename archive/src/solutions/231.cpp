#include "../lib/euler.hpp"


ul count(ul n, ul p) {
  ul c = 0;
  while (n) {
    c += n/p;
    n /= p;
  }
  return c;
}


int main() {
  // n!/(k!*(n-k)!)
  ul n = 20000000, k = 15000000, ans = 0;
  auto primes = segmented_sieve(n + 1);
  
  for (ul i_ = 0; i_ < primes.size(); ++i_) {
    ul i = primes[i_];
    ul is = count(n, i);
    if (i <= k)
      is -= count(k, i);
    if (i <= (n - k))
      is -= count(n - k, i);

    ans += is*i;
  }
  std::cout << ans << "\n";
}

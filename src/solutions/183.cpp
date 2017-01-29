#include <iostream>
#include "../lib/euler.h"

using namespace std;

int main() {
  int N = 10000;
  int SD = 0;
  vector<int> primes = segmented_sieve(N);
  // erase 2 and 5
  primes.erase(primes.begin());
  primes.erase(primes.begin() + 1);

  for (int i = 5; i <= N; ++i) {
    int sol  = round(i/exp(1.0));
    sol /= gcd(sol, i);
    bool repeating = false;

    for (int j = 0; j < primes.size(); ++j) 
      if (sol % primes[j] == 0) {
        repeating = true;
        break;
      }

    if (repeating) SD += i;
    else SD -= i;
  }
  cout << SD << endl;
}

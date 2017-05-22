#include "../lib/euler.hpp"


int mppf(int n, int p) {
  // maximum prime power factor of n!
  int mppf_ = 0;
  while (n) {
    mppf_ += n/p;
    n /= p;
  }
  return pow(p, mppf_);
}


int main() {
  int N = 101;
  auto primes = segmented_sieve(N);
  vector<int> mppfv(N);

  for (int i = 2; i < N; ++i) {
    for (auto prime: primes) {
      if (prime > i)
        break;

      int mppf_ = mppf(i, prime);
      if (mppf_ > mppfv[i])
        mppfv[i] = mppf_;
    }
  }
  cout << mppfv[25] << "\n";
}

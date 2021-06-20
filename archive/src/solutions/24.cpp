#include <algorithm>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int factorial(int n) {
  int ans = 1;
  for (int i = 2; i <= n; ++i)
    ans *= i;
  return ans;
}

vector<int> range(int width) {
  auto items = vector<int>();
  for (int i = 0; i <= width; ++i)
    items.push_back(i);
  return items;
}

vector<int> nthPermutation(int n, int width) {
  auto res = vector<int>(width);
  auto items = range(width);
  unsigned int index = 0;
  unsigned int count = n;

  while (index < res.size()) {
    int fact = factorial(width - 1);
    int i = count / fact;
    if (count % fact == 0)
      --i;

    res[index] = items[i];
    count -= fact * i;
    --width;
    ++index;
    items.erase(items.begin() + i);
  }
  return res;
}

int main() {
  auto res = nthPermutation(1000000, 10);
  for (auto i = res.begin(); i != res.end(); ++i)
    cout << *i << " ";
  cout << endl;
}

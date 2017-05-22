#include "../lib/euler.hpp"


char mc(ul& n) {
  if (n % 3 == 0) {
    n = n/3;
    return 'D';
  } else if (n % 3 == 1) {
    n = (4*n + 2)/3;
    return 'U';
  }
  n = (2*n - 1)/3;
  return 'd';
}


int main() {

}

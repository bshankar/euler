#include "../lib/euler.h"

string euler1() {
  return to_string(APSum(0, 3, 1000) + APSum(0, 5, 1000) - APSum(0, 15, 1000));
}

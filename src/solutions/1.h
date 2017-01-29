#include "../lib/euler.h"

string euler1() {
  return to_string(APSum(0, 3, 999)
                   + APSum(0, 5, 999)
                   - APSum(0, 15, 999));
}

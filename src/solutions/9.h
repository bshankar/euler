#include "../lib/euler.h"

string euler9() {
    for (int i = 1; i < 1000; ++i) 
        for (int j = i; j < 1000; ++j) {
            int k2 = i*i + j*j;
            int k = int(sqrt(k2));
            if (k*k == k2 && i + j + k == 1000)
              return to_string(i*j*k);
        }
}

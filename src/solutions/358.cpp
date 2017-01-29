#include "../lib/euler.h"
using namespace std;

#define MAX 729927007
#define MIN 724637681

int main(int argc, char *argv[]) {
    vector<ul> p = segmented_sieve<ul>(MAX);    
    
    for (auto i = p.size()-1; p[i] > MIN; --i) {
        if (56789*p[i] % 100000 != 99999)
            continue;

        ul r = 1;
        ul sum = 0;
        do {
            ul x = 10*r;
            ul d = x/p[i];
            r = x % p[i];
            sum += d;
        } while (r != 1);

         cout << p[i] << endl;
         cout << "Sum of digits: " << sum << endl;
         break;
    }
}

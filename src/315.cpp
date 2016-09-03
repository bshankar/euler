#include "bitboard.h"
#include "prime.h"
#include <vector>
#include <cinttypes>
using namespace std;
typedef unsigned long ul;

// Encode each digit on the didital clock as
// top middle bottom left right left right
const vector<uint8_t> numbers = {0b1011111, 0b0000101, 
                                   0b1110110, 0b1110101, 
                                   0b0101101, 0b1111001,
                                   0b1111011, 0b1001101,
                                   0b1111111, 0b1111101}; 

class ClockNumber {
public:
    ClockNumber(string n) {
        if (n.size() > 8) {
            cout << "Clock allows only upto 8 digits" << endl;
            cout << n << " " << n.size() << endl;
            exit(1);
        }

        // save the value of n
        this->n = n;

        for (auto i = 0; i < n.size(); ++i) {
            number |= numbers[n[i]-'0'];
            if (i < n.size() - 1)
                number <<= 8;
        }
    }

    uint64_t digital_roots() {
        // perform digital roots procedure on current number 
        // while keeping account of difference in transitions
        // between sam and max
        while (n.size() - 1) {
            uint64_t n_ = 0;
            for (auto i = 0; i < n.size(); ++i)
                n_ += n[i] - '0';
            set(to_string(n_));
        }
        return diff;
    }

    void set(ClockNumber num) {
        // Difference between sam's and max's clock transitions
        diff += 2*popcount(number & num.number);
        number = num.number;
        n = num.n;
    }

    void reset() {
        number = diff = 0;
    }
private:
    /* data */
    uint64_t number = 0;
    string n;
    ul diff = 0;
};


int main(int argc, char *argv[]) {
    vector<bool> s = sieve(20000000);
    uint64_t diff = 0;
    for (auto i = 10000001; i < s.size(); i += 2) {
        if (s[i])
            continue;
         
        ClockNumber cn(to_string(i+2));
        diff += cn.digital_roots();
    }
    cout << diff << endl;
}

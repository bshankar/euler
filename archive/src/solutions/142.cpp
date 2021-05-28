#include "../lib/euler.hpp"
using namespace std;

int main(int argc, char *argv[]) {
    ul x = 3;
    while (1) {
        for (ul y = 2; y < x; ++y)
            for (ul z = 1; z < y; ++z)
                if (is_square(x + y) && is_square(x + z) && is_square(y + z) &&
                        is_square(x - y) && is_square(x - z) && is_square(y - z)) {
                    cout << x + y + z << endl;
                    return 0;
                }
        x++;
    }
}

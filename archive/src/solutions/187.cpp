#include "../lib/euler.hpp"
# define N 100000000

int main(int argc, char *argv[]) {
    vector<ul> p = segmented_sieve<ul>(N/2);
    ui count = 0; 
    for (auto i = 0; i < p.size(); ++i)
        for (auto j = i; j < p.size(); ++j)
            if (p[i]*p[j] < N) 
                ++count;
            else
                break;

    cout << count << endl;
}

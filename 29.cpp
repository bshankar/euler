#include <iostream>
#include <vector>
#include <set>

typedef short s;
typedef unsigned short us;
typedef unsigned int ui;
typedef unsigned long ul;
using namespace std;

int main() {
    
    int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 
    37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    set<vector<int> > ans;
    
    for (int i = 2; i < 101; i++) {
        for (int j = 2; j < 101; j++) {
            vector<int> pr;
            for (int k = 0; k < 25; k++) {
                int pow = 0;
                int i_ = i;
                while (i_ % primes[k] == 0) {
                    i_ /= primes[k];
                    ++pow;
                }
                if (pow) {
                    pr.push_back(primes[k]);
                    pr.push_back(pow*j);
                }
            }
            ans.insert(pr);
        }
    }
    cout << ans.size() << endl;
}


#include <iostream>
#include <string>
#include "itertools.h"
using namespace std;
typedef unsigned long ul;

// total number of combinations 18C9
#define COMB 48620
#define F10 3628800

int sum(string n) {
    int sum_ = 0;
    for (int i = 0; i < n.size(); ++i)
        sum_ += n[i] - '0';
    return sum_;
}


int main(int argc, const char *argv[]) {

    // store all numbers < 100 divisible by 11
    bool isDivByEleven[100] = {};
    for (int i = 11; i < 100; i += 11)
        isDivByEleven[i] = true;
    isDivByEleven[0] = true;

    string s = "00112233445566778899";
    vector<ul> sumCount(75); // count # of times each sum occurs

    itertools<string> it(s, 10);
    while (it.next_combination())
        ++sumCount[sum(it.get())];

    ul ans = 0;

    for (int i = 0; i < 75; ++i)
        for (int j = i+1; j < 75; ++j)
            if (isDivByEleven[j-i])
                ans += sumCount[i]*sumCount[j];

    cout << ans << endl;
}

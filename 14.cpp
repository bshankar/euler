#include <iostream>
using namespace std;

unsigned long c(unsigned long n) {
  
    unsigned long count = 1;
    while (n != 1) {
	if (n % 2 == 0)
	    n /= 2;
	else 
	    n = 3*n + 1;
	++count;
    }
    return count;
}

int main() {
    unsigned long maxCount = 0, ans = 0;
    for (unsigned long i = 1; i < 1000000; ++i) {
        unsigned long count = c(i);
	if (count > maxCount) {
	    maxCount = count;
	    ans = i;
	}
    }
    cout << ans << " " << maxCount << endl;
}
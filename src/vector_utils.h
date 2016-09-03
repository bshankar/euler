#include <iostream>
#include <vector>
using std::cout;
using std::endl;

template <class T>
void print(std::vector<T> v) {
    std::copy(v.begin(), v.end(),
              std::ostreambuf_iterator<T>(cout, " "));
    cout << endl;
}

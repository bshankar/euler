#include <iostream>
#include <vector>
using std::cout;
using std::endl;

template <class T>
void print(std::vector<T> v) {
    for (T element: v)
        cout << element << " ";
    cout << endl;
}

template <class T, class index_t>
void swap(std::vector<T>& v, index_t i, index_t j) {
    // swap the values at index i and j
    T tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}

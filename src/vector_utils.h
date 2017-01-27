#include <iostream>
#include <vector>
#include <numeric>
using std::cout;
using std::endl;
using std::vector;

template <class T>
void print(vector<T> v) {
    for (T element: v)
        cout << element << " ";
    cout << endl;
}

template <class T, class index_t>
void swap(vector<T>& v, index_t i, index_t j) {
    // swap the values at index i and j
    T tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}

template <class T>
T sum(const vector<T>& v) {
    // sum of elements in the vector
    return std::accumulate(v.begin(), v.end(), (T) 0);
}

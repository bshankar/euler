#ifndef ITERTOOLS_H
#define ITERTOOLS_H

#include <vector>
#include <algorithm>

template <class T>
class itertools {
    /* Inspired from python a simple library to generate
     * all permutations and combinations of a set. The set
     * may contain duplicates. All the combinations are sorted.
     */
public:
    itertools(T set, int size) {
        this->size = size;
        this->set = set;
        indices.resize(size);
        subset.resize(size);
        firstOutputted = false;

        for (int i = 0; i < size; ++i)
            indices[i] = i;

        putValues(size);
    }


    bool next_combination() {
        // generate the next combination of size
        // of the subset and put the combination
        // in the subset.

        if (!firstOutputted) {
            firstOutputted = true;
            return true;
        }
        
        int diff = 1;
        while (indices[size - diff] == set.size() - diff)
            ++diff;

        if (diff > size)
            return false;
 
        ++indices[size-diff];
        for (int j = size-diff+1; j < size; ++j)
            indices[j] = indices[j-1] + 1;

        putValues(diff);
        return true;       
    }


    bool next_permutation() {
        // generate the next permutation of size
        // of the subset and put the permutation
        // in the subset array.
        
         if (!firstOutputted) {
            firstOutputted = true;
            return true;
        }
        
        if (std::next_permutation(subset.begin(), subset.end()))
            return true;
        else if (next_combination())
            return true;
        return false;
    }


    void putValues(int diff) {
        // put values in the subset
        for (int k = size - diff; k < size; ++k)
            subset[k] = set[indices[k]];
    }


    T get() {
        return subset;
    }

private:
    int size;
    T set, subset;
    bool firstOutputted;
    std::vector<int> indices;
};

#endif

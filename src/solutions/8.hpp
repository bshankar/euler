#include "../lib/euler.hpp"

string euler8() {
    ifstream file("src/data/8.txt");
    string s, sFull;
    while (getline(file, s))
        sFull += s;
    
    ul maxProduct = 0;
    
    for (ui i = 0; i < 1000-13; ++i) {
        s = sFull.substr(i, 13);
        ul product = 1;
        for (auto j = s.begin(); j != s.end(); ++j) {
            product *= *j - '0';
        }
        if (product > maxProduct) 
            maxProduct = product;
    }
    return to_string(maxProduct);
}

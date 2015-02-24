#ifndef FRACTION_H
#define FRACTION_H

#include "prime.h"

template<class T>
class fraction {
public:
    fraction(T num, T den) {
        assert(den > 0);
        this->num = num;
        this->den = den;
    }
    
    fraction(T num) {
        this->num = num;
        this->den = 1;
    }
    
    T operator+() {
        
    }
    
    T operator-() {
        
    }
    
    T operator*() {
        
    }
    
    T operator/() {
        
    }
    
    T numerator() {
        return num;
    }
    
    T denominator() {
        return den;
    }
    
private:
    T num, den;
};

#endif

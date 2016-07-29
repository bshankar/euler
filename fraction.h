#ifndef FRACTION_H
#define FRACTION_H
#include "prime.h"

template<class T>
class Fraction {
public:
    Fraction(T num = 0, T den = 1) {
        if (den == 0) {
            cout << "denominator cannot be 0" << endl;
            exit(1);
        }
        this->num = num;
        this->den = den;
        simplify();        
    }

    Fraction<T> operator+(Fraction f) {
        return Fraction(num*f.den + f.num*den, den*f.den); 
    }
    
    Fraction<T> operator-(Fraction f) {
        return Fraction(num*f.den - f.num*den, den*f.den);
    }
    
    Fraction<T> operator*(Fraction f) {
        return Fraction(f.num*num, f.den*den); 
    }
    
    Fraction<T> operator/(Fraction f) {
        return Fraction(num*f.den, den*f.num); 
    }

    Fraction<T> operator+=(Fraction f) {
        this->num = num*f.den + f.num*den;
        this->den = den*f.den;
        return *this;
    }
    
    Fraction<T> operator-=(Fraction f) {
        num = num*f.den - f.num*den;
        den = den*f.den;
        return *this;
    }

    Fraction<T> operator*=(Fraction f) {
        num = num*f.num;
        den = den*f.den;
        return *this;
    }

    Fraction<T> operator/=(Fraction f) {
        num = num*f.den;
        den = den*f.num;
        return *this;
    }

    friend ostream &operator<<(ostream &output, 
                               const Fraction& f) {
        if (f.num)
            output << f.num << "/" << f.den;
        else
            output << f.num;
        return output; 
    }

    friend istream &operator>>(istream &input, Fraction f) {
         input >> f.num >> f.den;
         return input;            
    }

    void simplify() {
        T factor = gcd(num, den);
        num /= factor;
        den /= factor;
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

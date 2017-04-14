#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

template <typename T>
T bisect(T (*fun)(T), T left_guess,
         T right_guess, T error = 1e-12, T min_window = 1e-10, int max_iter = 1000) {
    // find a root of a fun by using bisection method
    T fl = fun(left_guess),
      fr = fun(right_guess);
    if (fl > 0 || fr < 0 || isnan(fl) || isnan(fr)) {
        cout << "F(left_limit) = " << fun(left_guess) << endl;
        cout << "F(right_limit) = " << fun(right_guess) << endl;
        cout << "Error: Function doesn't have a root in the given range." << endl;
        cout << "Try different limits" << endl;
        exit(1);
    }

    int iter = 0;
    while (abs(fun(left_guess)) > error && iter < max_iter
            && abs(abs(left_guess) - abs(right_guess)) > min_window) {
        T new_guess = (left_guess + right_guess) / 2;
        if (fun(new_guess) > 0)
            right_guess = new_guess;
        else
            left_guess = new_guess;
        ++iter;
    }

    if (iter == max_iter) {
        cout << "Max of " << iter << " iterations reached!" << endl;
        cout << "Error: " << fun(left_guess) << endl;
    }

    cout << "Solution converged in " << iter << " iterations." << endl;
    return left_guess;
}

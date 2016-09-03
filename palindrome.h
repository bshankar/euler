#include <iostream>
#include <string>

typedef unsigned int ui;
using std::string;

bool is_palindrome(string s) {
    ui left = 0,
       right = s.size() - 1;

    while (left < right) {
        if (s[left] != s[right])
            return false;
        ++left;
        --right;
    }
    return true;
}

void make_palindrome(string& s, bool go_right) {
    // make a palindrome by copying left/right contents
    // to the other half

    ui left = 0;
    ui right = s.size() - 1;

    while (left < right) {
        if (go_right == true)
            s[right] = s[left];
        else
            s[left] = s[right];
        ++left;
        --right;
    }
}

void increment(string& s, ui index) {
    // increment right half of a palindrome
    // by reverse addition

    if (index == s.size()) {
        s.append("1");
        return;
    }

    ++s[index];
    if (s[index] > '9') {
        s[index] = ((s[index] - '0') % 10) + '0';
        increment(s, index + 1);
    }
}

string next_palindrome(string& s) {
    string s1 = s;
    make_palindrome(s, true);

    if (s > s1)
        return s;

    increment(s, s.size() / 2);
    make_palindrome(s, false);
    return s;
}

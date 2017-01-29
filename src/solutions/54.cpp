#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
typedef unsigned int ui;

const string spl_cards[] = {"10", "J", "Q", "K", "A"};


ui high_card(string hands[][10], int game) {
    // cancel cards that are same in both players
    // determine the winner based on who has the
    // highest value card
}


ui n_kind(string hands[][10], int game) {
    // determine the winner based on duplicates
}


ui straight(string hands[][10], int game) {
    // check if all the numbers are consequtive
    vector<char> v;
    for (auto i = 0; i < 10; ++i)
        v.push_back(hands[game][i][0]);

    // sort each player's hand separately
    sort(v.begin(), v.begin()+5);
    sort(v.begin()+5, v.end());
    ui mask = 0b11;
    for (auto i = 0; i < 5; ++i) {
        if (v[i] + 1 != v[i+1]) 
            mask &= 0x01; 
        if (v[i+5] + 1 != v[i+6])
            mask &= 0x10;
    }
    return mask;
}


ui flush(string hands[][10], int game) {
    ui same_suit = 0;
    // check for same suit
    for (auto i = 0; i < 9; ++i)
        if (hands[game][i][1] == hands[game][i+1][1])
            same_suit |= (1 << i);

    if (same_suit & 0b1111100000 == 0b1111100000)
        return 0b10;
    else if (same_suit & 0b0000011111 == 0b0000011111)
        return 0b01;
    return 0;
}

ui straight_flush(string hands[][10], int game) {
    auto flush_value = flush(hands, game),
         straight_value = straight(hands, game);

    if (flush_value == 0b10 && straight_value == 0b10)
        return 0b10;
    else if (flush_value == 0b01 && straight_value == 0b10)
        return 0b01;
    return 0;
}

ui royal_flush(string hands[][10], int game) {
    ui mask = 0;
    for (auto i = 0; i < 10; ++i)
        for (auto card: spl_cards) {
            if (hands[game][i].find(card) != -1)
                mask |= (1 << i);
        }
    
    if ((mask & 0b1111100000) == 0b1111100000)
        return 0b10;
    else if ((mask & 0b0000011111) == 0b0000011111)
        return 0b01;
    return 0;
}


int main(int argc, char *argv[]) {
    ifstream file("54.txt"); 
    string hands[1000][10]; 
    for (auto i = 0; i < 1000; ++i)
        for (auto j = 0; j < 10; ++j) {
            string s;
            file >> s;
            hands[i][j] = s;
        }
}

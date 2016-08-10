#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
typedef unsigned int ui;

const string spl_cards[] = {"10", "J", "Q", "K", "A"};


ui high_card(string hands[][10], int game) {
}


bool is_straight(string hands[][10], int game, int player) {
    // check if all the numbers are consequtive
    vector<char> v;
    for (auto i = 0; i < 5; ++i) {
        auto index = (player-1) ? i+5 : i;
        v.push_back(hands[game][index][0]);
    }

    sort(v.begin(), v.end());
    for (auto i = 0; i < 4; ++i)
        if (v[i] != v[i+1]) 
            return false;
    return true;
}


ui is_flush(string hands[][10], int game) {
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

ui is_straight_flush(string hands[][10], int game) {
    auto flush_value = is_flush(hands, game);
    if (flush_value == 0b10 && is_straight(hands, game, 1))
        return 0b10;
    else if (flush_value == 0b01 && is_straight(hands, game, 2))
        return 0b01;
    return 0;
}

ui is_royal_flush(string hands[][10], int game) {
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

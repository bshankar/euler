#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
typedef unsigned int ui;

ui polygon_number(ui n, ui sides) {
    switch (sides) {
        case 3:
            return n*(n+1)/2;
        case 4:
            return n*n;
        case 5:
            return n*(3*n-1)/2;
        case 6:
            return n*(2*n-1);
        case 7:
            return n*(5*n-3)/2;
        case 8:
            return n*(3*n-2);
        default:
            return 0;
    }
}


void make_chain(const vector<vector<ui> >& pn, vector<ui>& chain, bool is_chosen[6]) {
    if (chain.size() == 6) {
        if (chain[0]/100 == chain[5]%100) {
            ui ans = 0;
            for (auto i: chain) {
                ans += i;
                cout << i << " ";
            }

            cout << endl;
            cout << ans << endl;
            exit(0);
        }
        return;
    }

    ui start = chain.empty() ? 0 : chain[chain.size()-1] % 100;
    for (auto i = 5; i >= 0; --i) {
        for (auto j = 0; j < pn[i].size(); ++j) {
            if (chain.empty() || (!is_chosen[i] && start > 9 && start == pn[i][j]/100)) {
                chain.push_back(pn[i][j]);
                is_chosen[i] = true;
                make_chain(pn, chain, is_chosen); 
                is_chosen[i] = false;
                chain.pop_back();
            }
        }
    }
}


int main() {

    vector<vector<ui>> polygon_numbers; 
    polygon_numbers.resize(6);

    for (auto j = 3; j < 9; ++j)
        for (auto i = 2; i < 1000; ++i) {
            ui pn = polygon_number(i, j);
            if (pn >= 1000 && pn < 10000)
                polygon_numbers[j-3].push_back(pn);
            else if (pn >= 10000) break;
        }

    vector<ui> chain(0);
    bool is_chosen[6] = {};
    make_chain(polygon_numbers, chain, is_chosen);
}

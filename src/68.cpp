#include <iostream>
#include <ctime>
using namespace std;

class fivGon {
public:
    void search(int k) {
        if (ansFound)
            return;
        if (k == 10) {
            // 012 324 546 768 981
            if (fgon[0] + fgon[1] + fgon[2] == fgon[3] + fgon[2] + fgon[4] &&
                fgon[0] + fgon[1] + fgon[2] == fgon[5] + fgon[4] + fgon[6] &&
                fgon[0] + fgon[1] + fgon[2] == fgon[7] + fgon[6] + fgon[8] &&
                fgon[0] + fgon[1] + fgon[2] == fgon[9] + fgon[8] + fgon[1]) {
                print_ans();
                ansFound = true;
            }
            return;
        }
        for (int i = 10; i >= 1; --i) {
            if (isUsed[i])
                continue;
            fgon[k] = i;
            if ((k != 1 && k&1 && fgon[0] > fgon[k]) ||
                 ((k == 1 || !k&1) && i == 10)) {
                fgon[k] = 0;
                continue;
            }
            isUsed[i] = true;
            search(k+1);
            fgon[k] = 0;
            isUsed[i] = false;
        }
    }
    
    void print_ans() {
        int gon[] = {0, 1, 2, 3, 2, 4, 5, 4, 6, 7, 6, 8, 9, 8, 1};
        for (int i = 0; i < 15; ++i)
            cout << fgon[gon[i]];
        cout << endl;
    }
private:
    int fgon[10] = {};
    bool isUsed[11] = {};
    bool ansFound = false;
};

int main() {
    fivGon fg;
    clock_t t0 = clock();
    fg.search(0);
    clock_t t1 = clock();
    cout << "time elapsed: " << float(t1-t0)/CLOCKS_PER_SEC << "s" << endl; 
}

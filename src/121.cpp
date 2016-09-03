#include <iostream>
#include <cmath>
using namespace std;

#define TURNS 15
double total_prob = 0;

void search(double prob, int blue_turns,
            int red_disks) {
    if (red_disks > TURNS) {
        if (blue_turns > red_disks - 1 - blue_turns)
            total_prob += prob;
        return;
    }
    // pick a blue disk
    search(prob/(1 + red_disks), blue_turns + 1,
           red_disks + 1);
    // pick a red disk
    search(prob*red_disks/(1 + red_disks), blue_turns,
           red_disks + 1);
}

int main() {
    search(1, 0, 1);
    cout << floor(1/total_prob) << endl;
}

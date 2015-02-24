#include <iostream>
#include <vector>
typedef unsigned int ui;
using namespace std;

class ap {
public:
    ap(int max_) {
        this->max_ = max_;
        path.resize(max_+1);
        cost.resize(max_+1);
        
        for (int i = 1; i <= max_; ++i)
            cost[i] = -1;
        
        search(1, 0);
        result = 0;
        for (int i = 1; i <= max_; ++i)
            result += cost[i];
        
        cout << result << endl;
    }
    
    void search(int power, int depth) {
        if (power > max_ || depth > cost[power]) 
            return;
        cost[power] = depth;
        path[depth] = power;
        for (int i = depth; i >= 0; i--)
            search(power + path[i], depth + 1);
    }
    
private:
    int max_, result;
    vector<ui> path;
    vector<ui> cost;
};

int main() {
    ap ap_(200);
    
}

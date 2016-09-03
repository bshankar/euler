#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dfs(int n, vector<int>& df) {
    int sum = 0;
    while (n) {
        sum += df[n%10];
        n /= 10;
    }
    return sum;
}

int main() {
    int N = 1000000;
    vector<int> df(10); // digit factorials
    vector<int> len(N); // lengths
    df[0] = 1;
    for (int i = 1; i < 10; ++i)
        df[i] = i*df[i-1];
    
    vector<int> chain;
    
    for (int i = 0; i < N; ++i) {
        int i_ = i;
        while (chain.empty() || find(chain.begin(), chain.end(), i_) == chain.end()) {
            chain.push_back(i_);
            i_ = dfs(i_, df);
        }
        len[i] = chain.size();
        chain.clear();
    }
    
    int ans = 0;
    for (int i = 0; i < N; ++i)
        if (len[i] == 60)
            ++ans;
    
    cout << ans << endl;
}

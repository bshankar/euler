#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;


template <class T>
class F {
public:
    F(T n, T r) {
        // initialize some values
        v.resize(n);
        perm.resize(n);
        v[0] = true;
        perm[0] = 1;
        v[n-1] = true;
        perm[n-1] = n;
        count1 = count2 = count3 = index = 0;
        this->r = r;
    }
    
    void bt(T d) {
        if (d == perm.size()-1) {
            bool nV = false;
            for (T i = 0; i < v.size(); ++i) {
                if (v[i] == false) {
                    nV = true;
                    break;
                }
            }
            
            if (!nV) {
                T l1 = perm.size() - 2;
                if (perm[l1] == l1+1)
                    ++count1;
                else if (perm[l1] == l1)
                    ++count2;
                else if (perm[l1] == l1-1)
                    ++count3;
            }
            return;
        }
        
        for (T i = perm[d-1]-r; i <= perm[d-1]+r; ++i) {
            if (i <= 0 || v[i-1] || i > perm.size())
                continue;
            
            if (d == perm.size()-2 && i+r < perm[perm.size()-1])
                continue;
            
            perm[d] = i;
            v[i-1] = true;
            bt(d+1);
            
            // reset values
            v[i-1] = false;
            perm[d] = 0;
        }
    }
    
    void print() {
        for (T i = 0; i < perm.size(); ++i)
            cout << perm[i] << " ";
        cout << endl;
    }
    
    T count1, count2, count3;
    
private:
    vector<bool> v; // placed or not
    vector<T> perm;
    T index, r;
};

int main(int argc, char** argv) {
    F<long> f_(atoi(argv[1]), 3);
    f_.bt(1);
    cout << f_.count1 << " " << f_.count2 << " "
         << f_.count3 << endl;
}

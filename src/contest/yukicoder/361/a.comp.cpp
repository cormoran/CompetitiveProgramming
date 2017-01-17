#include <bits/stdc++.h>
using namespace std;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define repeat(i, j, k) for(int i = (j); i < (int)(k); i++)
template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }

class Solver {
  public:
    int L, D;
    vector<int> grundy;

    int calc_grundy(int l) {
        if(grundy[l] >= 0) return grundy[l];

        set<int> reachable;
        repeat(L1, 1, l + 1) {
            repeat(L2, L1 + 1, l - L1 + 1) {    
                int L3 = l - L1 - L2;
                if(L3 <= L2 or L3 - L1 > D) continue;                    
                reachable.insert(calc_grundy(L1) ^ calc_grundy(L2) ^ calc_grundy(L3));
            }
        }
        if(reachable.size() == 0) return grundy[l] = 0;
        
        int mex = 0;
        for(int g : reachable) if(mex == g) mex++;        
        return grundy[l] = mex;
    }    
    
    
    bool solve() {
        cin >> L >> D;       
        grundy.resize(L + 1, -1);        
        cout << (calc_grundy(L) != 0 ? "kado" : "matsu") << endl;
        return 0;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    Solver s;
    s.solve();
    return 0;
}

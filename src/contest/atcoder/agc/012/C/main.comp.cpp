#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)

class Solver {
  public:
    bool solve() {
        ll N; cin >> N;
        N += 1;
        vector<int> pops;
        { // get pop pos
            ll NN = N;
            for(int i = 0; NN; i++) {
                if(NN & 1) pops.push_back(i);
                NN >>= 1;
            }
        }        

        
        vector<int> ans;
        int len = pops.back(); pops.pop_back();
        rep(i, len) ans.push_back(i + 1);

        int max_n = len;
        while(pops.size()) {
            ans.insert(ans.begin() + pops.back(), ++max_n);
            pops.pop_back();
        }
        rep(i, max_n) ans.push_back(i + 1);
        cout << ans.size() << endl;
        rep(i, ans.size()) cout << ans[i] << (i == ans.size() - 1 ? "\n" : " ");
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

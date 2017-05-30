#include <bits/stdc++.h>
using namespace std;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define rrep(i, j) for(int i=(j)-1; i >= 0; i--)
#define all(v) v.begin(),v.end()

class Solver {
  public:
    bool solve() {
        int N, M; cin >> N >> M;        
        vector<vector<int>> E(N);
        rep(i, M) {
            int a, b; cin >> a >> b;
            E[a].push_back(i);
            E[b].push_back(i);
        }
        
        vector<bool> need_to_buy(N);
        vector<int> used_by(M, -1);
        rep(n, N) {
            bool flg = false;
            for(int e : E[n]) {
                if(used_by[e] < 0) {
                    flg = true;
                    used_by[e] = n;
                }
            }
            need_to_buy[n] = flg;
        }

        string ans = "";
        rrep(n, N) {
            if(need_to_buy[n]) {            
                bool flg = false;
                for(int e : E[n]) flg |= used_by[e] == n;
                if(flg) {
                    for(int e : E[n]) used_by[e] = n;
                }
                ans.push_back(flg ? '1' : '0'); 
            } else {
                ans.push_back('0');
            }
            if(ans == "0") ans = "";
        }

        cout << ans << endl;
        
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

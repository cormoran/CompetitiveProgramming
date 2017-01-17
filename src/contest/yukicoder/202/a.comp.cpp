#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;
using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define repeat(i, j, k) for(int i = (j); i < (int)(k); i++)

class Solver {
  public:
    bool cross(pii a, pii b) {
        return pow(a.first - b.first, 2) + pow(a.second - b.second, 2) < 20 * 20;
    }
    
    bool solve() {
        int N; cin >> N;
        vector<int> X(N), Y(N);
        rep(i, N) cin >> X[i] >> Y[i];

        map<int, map<int, vector<pii>>> G;
        int ans = 0;
        rep(i, N) {
            int x = X[i], y = Y[i];
            int gx = x / 10, gy = y / 10;
            repeat(dgy, -2, 2 + 1) {
                if(G.count(gy + dgy)) {
                    repeat(dgx, -2, 2 + 1) {
                        if(G[gy + dgy].count(gx + dgx)) {
                            for(pii p : G[gy +  dgy][gx + dgx]) {
                                if(cross(p, make_pair(y, x))) goto FAIL;
                            }
                        }                        
                    }
                }
            }
            G[gy][gx].push_back(make_pair(y, x));
            ans++;
      FAIL:;            
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

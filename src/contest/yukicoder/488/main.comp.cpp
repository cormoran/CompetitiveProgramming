#include <bits/stdc++.h>
using namespace std;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
class Solver {
  public:
    bool solve() {
        int N, M; cin >> N >> M;
        vector<vector<int>> G(N, vector<int>(N));
        rep(i, M) {
            int a, b; cin >> a >> b;
            G[a][b] = 1;
            G[b][a] = 1;
        }
        int ans = 0;
        rep(i, N) rep(j, i) rep(k, j) rep(l, k) {
            if(G[i][j] + G[i][k] + G[i][l] != 2) continue;            
            if(G[j][i] + G[j][k] + G[j][l] != 2) continue;
            if(G[k][j] + G[k][i] + G[k][l] != 2) continue;
            if(G[l][j] + G[l][i] + G[l][k] != 2) continue;
            ans++;
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

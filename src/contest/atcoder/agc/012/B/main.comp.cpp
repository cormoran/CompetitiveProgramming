#include <bits/stdc++.h>
using namespace std;

#define rep(i, j) for(int i=0; i < (int)(j); i++)

template<class T> bool set_max(T &a, const T &b) { return a < b  ? a = b, true : false; }
template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }

const int MAX_D = 10;

class Solver {
  public:    
    bool solve() {
        int N, M; cin >> N >> M;
        vector<vector<int>> E(N);
        rep(i, M) {
            int a, b; cin >> a >> b;
            a--; b--;
            E[a].push_back(b);
            E[b].push_back(a);
        }
        
        int Q; cin >> Q;
        vector<int> V(Q), D(Q), C(Q);
        rep(i, Q) {
            cin >> V[i] >> D[i] >> C[i];
            V[i]--;
        }
        
        vector<vector<int>> dp(N, vector<int>(MAX_D + 1, -1));

        function<void(int, int, int)> paint = [&] (int node, int time, int dist) {
            if(dist < 0 or dp[node][dist] >= 0) return;
            dp[node][dist] = time;
            for(int nxt : E[node]) paint(nxt, time, dist - 1);
        };
        
        for(int q = Q - 1; q >= 0; q--) paint(V[q], q, D[q]);

        rep(i, N) {
            int time = -1;
            rep(t, MAX_D + 1) set_max(time, dp[i][t]);
            cout << (time >= 0 ? C[time] : 0) << endl;
        }
        
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

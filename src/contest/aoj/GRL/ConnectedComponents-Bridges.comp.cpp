#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
#define rep(i, j) for(int i=0; i < (int)(j); i++)

using EdgeList = vector<vector<int>>;

// 非連結を含む，グラフ E の橋を列挙
// O(N + M) N: 頂点数, M: 辺数
vector<pii> enumerate_bridges(const EdgeList &E) {
    int N = E.size();
    vector<int> ord(N, -1), low(N);
    int cnt = 0;
    vector<pii> bridges;
    function<void(int, int)> dfs = [&] (int now, int pre) {
        ord[now] = cnt++;
        low[now] = ord[now];
        for(int nxt : E[now]) {
            if(ord[nxt] < 0) {
                // not visited
                dfs(nxt, now);
                low[now] = min(low[now], low[nxt]);
                if(ord[now] < low[nxt]) {
                    bridges.emplace_back(min(now, nxt), max(now, nxt));
                }
            } else if(nxt != pre) {
                // visited
                low[now] = min(low[now], ord[nxt]);
            } 
        }
    };
    // 連結グラフならdfs(0)だけでOKなはず
    rep(i, N) if(ord[i] < 0) dfs(i, -1);
    return bridges;
}

#define all(v) v.begin(),v.end()

class Solver {
  public:
    bool solve() {
        int N, M; cin >> N >> M;
        EdgeList E(N);
        rep(i, M) {
            int a, b; cin >> a >> b;
            E[a].push_back(b);
            E[b].push_back(a);
        }
        auto ans = enumerate_bridges(E);
        sort(all(ans));
        for(pii p : ans) cout << p.first << " " << p.second << endl;
        
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

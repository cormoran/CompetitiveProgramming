#include <bits/stdc++.h>
using namespace std;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
using EdgeList = vector<vector<int>>;

// 非連結を含む，グラフ E の関節点（切断点）を列挙
// O(N + M) N: 頂点数, M: 辺数
vector<int> enumerate_articulations(const EdgeList &E) {
    int N = E.size();
    vector<int> ord(N, -1), low(N);
    int cnt = 0;
    vector<int> articulations;
    function<void(int, int)> dfs = [&] (int now, int pre) {
        ord[now] = cnt++;
        low[now] = ord[now];
        
        bool is_articulation = false;
        int dfs_children = 0;
        
        for(int nxt : E[now]) {
            if(ord[nxt] < 0) {
                // not visited
                dfs_children++;
                dfs(nxt, now);
                low[now] = min(low[now], low[nxt]);
                if(pre >= 0 and ord[now] <= low[nxt]) {
                    is_articulation = true;
                }
            } else if(nxt != pre) {
                // visited
                low[now] = min(low[now], ord[nxt]);
            } 
        }
        if(pre < 0 and dfs_children > 1) is_articulation = true;
        if(is_articulation) articulations.push_back(now);
    };
    // 連結グラフならdfs(0)だけでOKなはず
    rep(i, N) if(ord[i] < 0) dfs(i, -1);
    return articulations;
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
        auto ans = enumerate_articulations(E);
        sort(all(ans));
        for(int a : ans) cout << a << endl;
        
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

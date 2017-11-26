#include <bits/stdc++.h>
using namespace std;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define all(v) v.begin(),v.end()
template<class T> bool set_max(T &a, const T &b) { return a < b  ? a = b, true : false; }

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, K; cin >> N >> K;

    vector<vector<int>> E(N);
    rep(i, N - 1) {
        int u, v; cin >> u >> v;
        u--; v--;
        E[u].push_back(v);
        E[v].push_back(u);
    }
    int ans = 0;

    vector<int> sub_tree_size(N);
    function<int(int, int)> num_dfs = [&] (int now, int prev) {
        sub_tree_size[now] = 1;
        for(int nxt : E[now]) if(nxt != prev) sub_tree_size[now] += num_dfs(nxt, now);
        return sub_tree_size[now];
    };
    
    vector<int> dp(N);
    function<void(int, int)> dfs = [&] (int now, int prev) {
        vector<int> children = E[now];
        int num_large_child = 0;
        bool is_large_parent = (N - sub_tree_size[now]) >= K;
        for(int nxt : children) {
            if(nxt == prev) continue;
            dfs(nxt, now);
            num_large_child += sub_tree_size[nxt] >= K;
        }
        sort(all(children), [&] (int a, int b) {
                return dp[a] != dp[b] ? dp[a] > dp[b] : sub_tree_size[a] < sub_tree_size[b];                
            });
        if(children.size() >= 1) {
            // child a <- .. -> now
            int child_a = children[0];
            int val = dp[child_a] + num_large_child - (sub_tree_size[child_a] >= K);
            set_max(dp[now], val);
            set_max(ans, val + is_large_parent);
        }
        if(children.size() >= 2) {
            int child_a = children[0];
            int child_b = children[1];
            // child a <- .. - now - .. -> child b
            int offset = 0;
            offset -= sub_tree_size[child_a] >= K;
            offset -= sub_tree_size[child_b] >= K;
            offset += is_large_parent;
            set_max(ans, dp[child_a] + dp[child_b] + num_large_child + offset);
        }
        // only now (can't be answer due to u == v)
        set_max(dp[now], num_large_child);
    };

    num_dfs(0, -1);
    dfs(0, -1);

    cout << ans << endl;
    
    return 0;
}


#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define all(v) v.begin(),v.end()
template<class T> bool set_max(T &a, const T &b) { return a < b  ? a = b, true : false; }

struct Edge { ll from, to, cost; };
using EdgeList = vector<vector<Edge>>;

int main() {
    int N; cin >> N;
    EdgeList E(N);

    rep(i, N - 1) {
        int s, t; cin >> s >> t;
        s--; t--;
        E[s].emplace_back(Edge{s, t, 1});
        E[t].emplace_back(Edge{t, s, 1});
    }
    vector<ll> dp(N);
    function<ll(int, int)> dfs = [&] (int now, int prev) {
        dp[now] = 0;
        for(Edge &e : E[now]) {
            if(e.to == prev) continue;
            set_max(dp[now], dfs(e.to, now) + e.cost);
        }
        return dp[now];
    };
    vector<ll> ans(N);
    function<void(int, int, ll)> dfs2 = [&] (int now, int prev, ll v) {
        using T = pair<ll, int>;
        vector<T> values = {T(0, -1)}; // 番兵
        for(Edge &e : E[now]) {
            ll vv = e.to != prev ? dp[e.to] : v;
            values.emplace_back(vv + e.cost, e.to);
        }
        sort(all(values), greater<T>());
        ans[now] = values[0].first;
        for(Edge &e : E[now]) {
            if(e.to == prev) continue;
            ll vv = (values[0].second != e.to ? values[0] : values[1]).first;
            dfs2(e.to, now, vv);
        }        
    };
    dfs(0, -1);
    dfs2(0, -1, 0);
    for(auto a : ans) cout << (N - 1) * 2 - a << endl;
    return 0;
}


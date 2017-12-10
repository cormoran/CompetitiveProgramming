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
        int s, t, w; cin >> s >> t >> w;
        E[s].emplace_back(Edge{s, t, w});
        E[t].emplace_back(Edge{t, s, w});
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
    function<ll(int, int, ll)> dfs2 = [&] (int now, int prev, ll v) {
        ll res = 0;
        using T = pair<ll, int>;
        vector<T> values = {T(0, -1)}; // 番兵
        for(Edge &e : E[now]) {
            ll vv = e.to != prev ? dp[e.to] : v;
            values.emplace_back(vv + e.cost, e.to);
        }
        sort(all(values), greater<T>());
        set_max(res, values[0].first + values[1].first);
        for(Edge &e : E[now]) {
            if(e.to == prev) continue;
            ll vv = (values[0].second != e.to ? values[0] : values[1]).first;
            set_max(res, dfs2(e.to, now, vv));
        }
        return res;
    };
    dfs(0, -1);
    cout << dfs2(0, -1, 0) << endl;
    return 0;
}


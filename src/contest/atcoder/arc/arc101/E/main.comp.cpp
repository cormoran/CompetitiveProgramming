/**
   包除原理+DP

   ある辺を使わないことにすると，それより子の木に関しての組み合わせが完全に求められるのでDPできる
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define repeat(i, j, k) for(int i = (j); i < (int)(k); i++)
const ll MOD = 1e9+7;

class Solver {
  public:
    vector<ll> num_pair_;

    int calc_size(int now, int prev, const vector<vector<int>> &E) {
        static map<int, int> cache;
        if(cache.count(now)) return cache[now];
        int res = 1;
        for(int nxt : E[now]) if(nxt != prev) res += calc_size(nxt, now, E);
        cache[now] = res;
        return res;
    }
    vector<vector<ll>> dfs(int now, int prev, const vector<vector<int>> &E) {
        int tree_size = calc_size(now, prev, E);
        vector<vector<ll>> dp(tree_size + 1, vector<ll>(2));
        // dp[i][j] := now を含む連結成分のサイズが i
        //             j = 1 if それまでに奇数個の辺を取り除いた else 0
        dp[1][0] = 1;
        int max_i = 1;
        for(int nxt : E[now]) {
            if(nxt == prev) continue;
            vector<vector<ll>> tmp(tree_size + 1, vector<ll>(2));
            auto res = dfs(nxt, now, E);
            // merge

            int subtree_size = res.size() - 1;
            // int other_subtree_size = tree_size - 1 - subtree_size;

            // repeat(i, 1, other_subtree_size + 1 + 1) { // +1: +now, ]
            repeat(i, 1, max_i + 1) {
                rep(j, subtree_size + 1) {
                    // 辺 now <-> nxt を取り除かない
                    tmp[i + j][0] += dp[i][0] * res[j][0] % MOD + dp[i][1] * res[j][1] % MOD;
                    tmp[i + j][0] %= MOD;

                    tmp[i + j][1] += dp[i][1] * res[j][0] % MOD + dp[i][0] * res[j][1] % MOD;
                    tmp[i + j][1] %= MOD;

                    // 辺 now <-> nxt を取り除く
                    tmp[i][1] += dp[i][0] * res[j][0] % MOD * num_pair_[j] % MOD;
                    tmp[i][1] += dp[i][1] * res[j][1] % MOD * num_pair_[j] % MOD;
                    tmp[i][1] %= MOD;

                    tmp[i][0] += dp[i][1] * res[j][0] % MOD * num_pair_[j] % MOD;
                    tmp[i][0] += dp[i][0] * res[j][1] % MOD * num_pair_[j] % MOD;
                    tmp[i][0] %= MOD;
                }
            }
            swap(dp, tmp);
            max_i += subtree_size;
        }
        return dp;
    }

    bool solve() {
        int N; cin >> N;
        vector<vector<int>> E(N);
        rep(i, N - 1) {
            int x, y; cin >> x >> y;
            x--; y--;
            E[x].push_back(y);
            E[y].push_back(x);
        }

        num_pair_.resize(N + 1);
        num_pair_[2] = 1;
        for(int i = 4; i <= N; i += 2) num_pair_[i] = num_pair_[i - 2] * (i - 1) % MOD;

        auto res = dfs(0, -1, E);
        ll ans = 0;
        rep(i, res.size()) {
            ans += res[i][0] * num_pair_[i] % MOD;
            ans += (MOD - res[i][1] * num_pair_[i] % MOD) % MOD;
            ans %= MOD;
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

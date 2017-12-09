#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define repeat(i, j, k) for(int i = (j); i < (int)(k); i++)
#define all(v) v.begin(),v.end()
template<class T> bool set_max(T &a, const T &b) { return a < b  ? a = b, true : false; }

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, X; cin >> N >> X;
    vector<ll> T(N + 1); rep(i, N) cin >> T[i + 1];
    T[0] = 0;
    repeat(i, 1, N + 1) T[i] += X-1;
    vector<vector<ll>> dp(N + 1, vector<ll>(N + 1));
    auto f = [&] (int i) {
        static vector<int> memo(N + 1, -1);
        if(memo[i] >= 0) return memo[i];
        return memo[i] = lower_bound(all(T), T[i] - X) - begin(T);
    };
    rep(cnt, N) {
        repeat(i, 1, N + 1) {
            int j = f(i);
            if(j > 0) set_max(dp[cnt + 1][i], dp[cnt][j - 1] + min(X, T[i] - T[j - 1]));
            set_max(dp[cnt + 1][i], dp[cnt][j] + min(X, T[i] - T[j]));
        }
    }
    ll mx = 0;
    rep(i, N) {
        set_max(mx, dp[i+1][N]);
        cout << mx << endl;
    }
    return 0;
}

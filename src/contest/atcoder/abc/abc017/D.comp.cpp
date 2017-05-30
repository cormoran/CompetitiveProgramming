#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define repeat(i, j, k) for(int i = (j); i < (int)(k); i++)
#define all(v) v.begin(),v.end()
ll MOD = 1000000007LL;

int main() {
    int N, M; cin >> N >> M;
    vector<int> F(N);
    rep(i, N) {
        cin >> F[i];
        F[i]--;
    }
    vector<ll> dp(N + 1, 0), sum(N + 1, 0);
    vector<int> prev(M, -1);
    dp[0] = 1;
    sum[0] = 1;
    int pos = -1;
    rep(i, N) {        
        dp[i + 1] = sum[i];
        pos = max(pos, prev[F[i]]);
        if(pos >= 0) dp[i + 1] -= sum[pos];
        dp[i + 1] = (dp[i + 1] + MOD) % MOD;
        prev[F[i]] = i;
        sum[i + 1] = (sum[i] + dp[i + 1]) % MOD;
    }
    cout << dp[N] % MOD << endl;
    return 0;
}

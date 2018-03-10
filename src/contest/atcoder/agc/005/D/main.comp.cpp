#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;
using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define repeat(i, j, k) for(int i = (j); i < (int)(k); i++)
#define all(v) v.begin(),v.end()
#define debug(x) cerr << #x << " : " << x << endl

template<class T> bool set_min(T &a, const T &b) { return a > b  ? a = b, true : false; }
template<class T> bool set_max(T &a, const T &b) { return a < b  ? a = b, true : false; }
// vector
template<class T> istream&
operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }
template<class T> ostream&
operator << (ostream &os , const vector<T> &v) { for(const T &t : v) os << "\t" << t; return os << endl; }
// pair
template<class T, class U> ostream&
operator << (ostream &os , const pair<T, U> &v) { return os << "<" << v.first << ", " << v.second << ">"; }

const int INF = 1 << 30;
const ll INFL = 1LL << 60;
const ll MOD = 924844033;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, K; cin >> N >> K;

    // last := 0 if reject
    //         1 if ac left
    //         2 if ac right
    vector<vector<ll>> dp(N + 1, vector<ll>(3, 0));
    dp[0][2] = 1;
    rep(k, K * 2) {
        rep(i, N + 1) {
            rep(j, 2) {
                dp[i][0] = (dp[i][0] + dp[i][1 + j]) % MOD;
                dp[i][1 + j] = 0;
            }
            if(k - K < 0) swap(dp[i][0], dp[i][2]);
        }        
        
        for(int pos = k; pos < N; pos += K * 2) {
            bool last = pos + K >= N;
            vector<vector<ll>> dp_nxt(N + 1, vector<ll>(3, 0));
            rep(i, N + 1) {                
                rep(j, 3) dp_nxt[i][0] = (dp_nxt[i][0] + dp[i][j]) % MOD;
                if(i == N) continue;
                rep(j, 2) dp_nxt[i + 1][1] = (dp_nxt[i + 1][1] + dp[i][j]) % MOD;
                if(not last) rep(j, 3) dp_nxt[i + 1][2] = (dp_nxt[i + 1][2] + dp[i][j]) % MOD;
            }
            swap(dp, dp_nxt);
        }
    }
    vector<ll> num(N + 1, 0);
    rep(i, N + 1) rep(j, 3) num[i] += dp[i][j];    

    ll sum = 0;
    vector<ll> fact(N + 1);
    fact[0] = 1;
    rep(i, N) fact[i + 1] = (fact[i] * (i + 1)) % MOD;
    repeat(i, 1, N + 1) {
        if(i == 0) continue;
        sum += (i % 2 ? 1 : -1) * num[i] * fact[N - i];
        sum %= MOD;
    }

    ll ans = fact[N] - sum;
    while(ans < 0) ans += MOD;
    ans %= MOD;

    cout << ans << endl;
    
    return 0;
}

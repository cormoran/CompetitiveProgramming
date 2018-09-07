#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define repeat(i, j, k) for(int i = (j); i < (int)(k); i++)
template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }

const ll MOD = 998244353ll;

ll modpow(const ll n, ll r){
    if(r == 0) return 1;
    ll ret = modpow(n, r / 2);
    ret = (ret * ret) % MOD;
    if(r % 2 != 0) ret = ret * n;
    return ret % MOD;
}


vector<vector<ll>> combination_array(int n){
    vector<vector<ll>> nCk(n + 1, vector<ll>(n + 1));
    nCk[0][0] = 1;
    repeat(i, 1, n + 1) {
        nCk[i][0] = nCk[i-1][0];
        repeat(j, 1, i + 1) {
            nCk[i][j] = (nCk[i-1][j] + nCk[i-1][j-1]) % MOD;
        }
    }
    return nCk;
}


class Solver {
  public:
    bool solve() {
        int K, N; cin >> K >> N;
        auto nCk = combination_array(max(N, K) * 2);
        auto nHr = [&] (int n, int r) { return nCk[n + r - 1][r]; };

        repeat(i, 2, 2 * K + 1) {
            int num_group = 0; repeat(j, 1, i) num_group += j <= K and i - j <= K and j < i - j;

            ll ans = 0;
            if(i % 2 == 1) {
                repeat(j, 0, num_group + 1) {
                    if(N - j >= 0)
                        ans += (((nCk[num_group][j] * nHr(K - 2 * num_group + j, N - j)) % MOD) * modpow(2, j)) % MOD;
                    ans %= MOD;
                }
            } else {
                repeat(j, 0, num_group + 1) {
                    if(N - j >= 0)
                        ans += (((nCk[num_group][j] * nHr(K - 2 * num_group + j - 1, N - j)) % MOD) * modpow(2, j)) % MOD;
                    ans %= MOD;
                    if(N - j - 1 >= 0)
                        ans += (((nCk[num_group][j] * nHr(K - 2 * num_group + j - 1, N - j - 1)) % MOD) * modpow(2, j)) % MOD;
                    ans %= MOD;
                }
            }
            cout << ans % MOD << endl;
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

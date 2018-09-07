#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;
using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define repeat(i, j, k) for(int i = (j); i < (int)(k); i++)
#define debug(x) cerr << #x << " : " << x << endl

ll modpow(ll n, ll m, ll mod) {
    ll ret = 1;
    while(m > 0) {
        if(m & 1) ret = ret * n % mod;
        n = n * n % mod;
        m >>= 1;
    }
    return ret;
}

vector<vector<ll>> combination_array(int n, ll MOD) {
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

        ll N, M; cin >> N >> M;

        vector<vector<ll>> ways2(N + 1, vector<ll>(N + 1, 0));
        // ways2[i][j] := 1,..,i がすべて１杯以下 and
        //                1,...,i の少なくとも１つが乗っているラーメンがちょうど j 杯である
        //                ようなラーメンの組み合わせの総数
        rep(i, N + 1) ways2[i][0] = 1; // ０杯

        repeat(i, 1, N + 1) {
            repeat(j, 1, N + 1) {
                ways2[i][j] += ways2[i - 1][j];     // i を使わない
                ways2[i][j] += ways2[i - 1][j - 1]; // i だけが乗った新規ラーメンを生成
                ways2[i][j] += ways2[i - 1][j] * j; // i を既存のラーメンに乗っける
                ways2[i][j] %= M;
            }
        }

        vector<ll> ways(N + 1);
        // ways[i] := 1,...,i がすべて１杯以下 なラーメンの組み合わせの総数
        rep(i, N + 1) {
            vector<ll> p(N + 1); { // p[j] := (2^(N-i))^j
                ll base = modpow(2, N - i, M);
                p[0] = 1;
                rep(j, N) p[j + 1] = p[j] * base % M;
            }
            rep(j, N + 1) {
                ways[i] += ways2[i][j] * p[j] % M;
                ways[i] %= M;
            }
        }

        auto nCk = combination_array(N, M);
        vector<ll> pow22i(N + 1); { // pow22i[i] := 2^(2^i)
            pow22i[0] = 2;
            rep(i, N) pow22i[i + 1] = pow22i[i] * pow22i[i] % M;
        }

        ll ans = 0;
        rep(i, N + 1) {
            ll a = (i % 2 == 0 ? 1 : -1) * nCk[N][i] * ways[i] % M * pow22i[N - i] % M;
            while(a < 0) a += M;
            ans = (ans + a) % M;
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

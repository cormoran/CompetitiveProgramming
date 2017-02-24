#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)

template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }
template<class T> ostream& operator << (ostream &os , const vector<T> &v) { for(const T &t : v) os << "\t" << t; return os << endl; }

const int INF = 1 << 30;
const ll INFL = 1LL << 60;
const ll MOD = 1000000000 + 7;

ll nPk(int n, int k) {
    ll res = 1;
    while(k--) res = (res * n--) % MOD;
    return res;
}

class Solver {
  public:
    bool solve() {
        int N; cin >> N;
        vector<int> M(N); cin >> M;
        M.push_back(INF);
        vector<vector<ll>> dp(N + 1, vector<ll>(N + 1));        
        dp[N][0] = 1; // [i][j] 後ろから i まで使って，最後の区間幅がj

        for(int i = N; i > 0; i--) {            
            for(int k = 0; k <= N - i; k++) {
                int prev = INF + 1;
                for(int j = max(1, k); j <= i and M[i - j] < M[i - j + 1]; j++) {
                    cerr << "[" << i <<"][" << k << "] to [" << i-j << "][" << j << "]" << endl;                    
                    dp[i - j][j] = (dp[i - j][j] + dp[i][k] * nPk(j, k)) % MOD;
                }
            }
        }
        ll ans = 0;
        rep(i, N + 1) ans = (ans + dp[0][i]) % MOD;
        cout << ans << endl;

        rep(i, N + 1) {
            rep(j, N + 1) {
                cerr << dp[i][j] << " ";
            }
            cerr << endl;
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

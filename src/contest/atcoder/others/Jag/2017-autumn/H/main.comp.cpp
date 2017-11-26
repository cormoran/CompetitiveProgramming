#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
template<class T> istream&
operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }

const ll MOD = 1000000007LL;

typedef unsigned long long ull;
const ull HASH_BASE = 100000007;
function<ull(int, int)> build_rolling_hash(const string &s) {
    int n = s.size();
    vector<ull> hash(n + 1), pow_base(n + 1);
    pow_base[0] = 1;
    rep(i, n) {
        hash[i + 1] = hash[i] * HASH_BASE + s[i];
        pow_base[i + 1] = pow_base[i] * HASH_BASE;
    }
    return [=] (int l, int r) {
        return hash[r] - hash[l] * pow_base[r - l];
    };
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N; cin >> N;
    vector<string> S(N); cin >> S;
    string T; cin >> T;

    map<int, set<ull>> hash_s;
    rep(i, N) hash_s[S[i].size()].insert(build_rolling_hash(S[i])(0, S[i].size()));
    auto hash_t = build_rolling_hash(T);   

    vector<ll> dp(T.size() + 1);
    dp[0] = 1;
    rep(l, T.size()) {
        for(auto &p : hash_s) {
            int r = l + p.first;
            if(r > T.size()) continue;
            if(p.second.count(hash_t(l, r))) dp[r] = (dp[r] + dp[l]) % MOD;
        }
    }
    cout << dp.back() << endl;
    return 0;
}

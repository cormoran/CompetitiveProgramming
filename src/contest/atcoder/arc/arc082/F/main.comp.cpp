#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define all(v) v.begin(),v.end()
template<class T> bool set_min(T &a, const T &b) { return a > b  ? a = b, true : false; }
template<class T> bool set_max(T &a, const T &b) { return a < b  ? a = b, true : false; }
template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }

void solve() {
    ll X, K; cin >> X >> K;
    vector<ll> R(K + 1);
    R[0] = 0;
    rep(i, K) cin >> R[i + 1];

    auto clip = [&] (ll &a) {
        set_min(a, X);
        set_max(a, 0LL);
    };
    auto dir = [] (int k) { return k % 2 == 0 ? -1 : 1; };

    vector<ll> sum(K + 1);
    rep(k, K) sum[k + 1] = sum[k] + (k % 2 == 0 ? -1 : 1) * (R[k + 1] - R[k]);
    
    vector<ll> h(K + 1), l(K + 1); // 満杯状態でスタート
    vector<ll> ub(K + 1), lb(K + 1);
    // a <= ub[i] なら，R[i]までで上のパーツが満杯になる無駄な時間が生じない
    // a >  ub[i] なら，R[i]までのどこかで上のパーツが満杯になる
    //                  この時，a = X も必ず満杯になるのでR[i]以降では値がa = Xと一致しているはず
    h[0]  = X;  l[0] = 0;
    ub[0] = X; lb[0] = 0;
    rep(k, K) {
        ll d = (R[k + 1] - R[k]) * dir(k);
        
        h[k + 1] = h[k] + d;
        l[k + 1] = l[k] + d;
        if(dir(k) > 0) {
            ub[k + 1] = min(ub[k], ub[k] - (h[k] + d - X));
            lb[k + 1] = lb[k];
        } else {
            lb[k + 1] = max(lb[k], lb[k] + -(l[k] + d));
            ub[k + 1] = ub[k];
        }
        clip(h[k + 1]);  clip(l[k + 1]);
        clip(ub[k + 1]); clip(lb[k + 1]);
    }
    
    ll Q; cin >> Q;
    rep(q, Q) {
        ll t, a; cin >> t >> a;
        int k = upper_bound(all(R), t) - begin(R) - 1;
        assert(k >= 0);
        ll ans = 0;
        if(a >= ub[k])
            ans = h[k];
        else if(a <= lb[k])
            ans = l[k];
        else
            ans = a + sum[k];
        ans += (t - R[k]) * dir(k);
        clip(ans);
        cout << ans << endl;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}

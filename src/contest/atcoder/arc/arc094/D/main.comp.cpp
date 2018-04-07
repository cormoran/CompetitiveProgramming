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


ll solve(ll A, ll B) {
    auto foo_a = [&] (ll a) {
        return a >= A ? a + 1 : a;
    };
    auto foo_b = [&] (ll b) {
        return b >= B ? b + 1 : b;
    };
    auto check = [&] (ll m) {
        bool ok = true;
        ll AB = A * B;
        ok &= foo_a(1) * foo_b(m) < AB;
        ok &= foo_a(m) * foo_b(1) < AB;
        for(ll i = max(1ll, m / 2 - 100); i <= min(m / 2 + 100, m); i++) {
            ll a = foo_a(i);
            ll b = foo_b(m - i + 1);
            ok &= a * b < AB;
        }
        return ok;
    };
    
    ll l = 0, r = 2e9; // [l, r)
    
    while(l + 1 < r) {
        ll m = (l + r) / 2;
        (check(m) ? l : r) = m;
    }
    // debug(l);
    return l;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll Q; cin >> Q;

    rep(q, Q) {
        ll A, B; cin >> A >> B;
        ll ans = max(solve(A, B), solve(B, A));
        cout << ans << endl;
    }
    
    return 0;
}

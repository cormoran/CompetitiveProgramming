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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, K; cin >> N >> K;
    ll ans = 0;
    repeat(b, K + 1, N + 1) {
        ll up = (N - K) / b;
        ll low = (N - b + 1) / b;
        ll ans2 = 0;
        if(up != low) {
            ll l = K, r = b - 1;
            while(l + 1 < r) {
                ll m = (l + r) / 2;
                ll v = (N - m) / b;
                (v == up ? l : r) = m;
            }
            ans2 += (l - K + 1) * (up + 1);
            ans2 += (b - 1 - r + 1) * (low + 1);
        } else {
            ans2 += (b - K) * (up + 1);
        }
        // cerr << "B = " << b << " : " << ans2 << endl;
        ans += ans2 - (K == 0);
    }
    cout << ans << endl;
    return 0;
}

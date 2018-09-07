#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;
using ll = long long;
using pll = pair<ll, ll>;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define repeat(i, j, k) for(int i = (j); i < (int)(k); i++)
#define all(v) v.begin(),v.end()
#define debug(x) cerr << #x << " : " << x << endl

template<class T> bool set_min(T &a, const T &b) { return a > b  ? a = b, true : false; }
template<class T> bool set_max(T &a, const T &b) { return a < b  ? a = b, true : false; }
// vector
template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }
template<class T> ostream& operator << (ostream &os , const vector<T> &v) { for(const T &t : v) os << "\t" << t; return os << endl; }
// pair
template<class T, class U> ostream& operator << (ostream &os , const pair<T, U> &v) { return os << "<" << v.first << ", " << v.second << ">"; }

const int INF = 1 << 30;
const ll INFL = 1LL << 60;


class Solver {
  public:
    bool solve() {
        int N, Q; cin >> N >> Q;
        vector<ll> X(N); cin >> X;
        vector<ll> C(Q), D(Q);

        vector<ll> x_sum(N + 1);
        rep(i, N) x_sum[i + 1] = x_sum[i] + X[i];
        // sum of [l, r)
        auto calc_sum = [&] (int l, int r) {
            // if(l > r) {
            //     cerr << l << " , " << r << endl;
            //     assert(0);
            // }
            return x_sum[r] - x_sum[l];
        };

        rep(i, Q) {
            ll c, d; cin >> c >> d;
            int l = lower_bound(all(X), c - d) - begin(X);
            int r = upper_bound(all(X), c + d) - begin(X);
            int cl = upper_bound(all(X), c) - begin(X);
            int cr = lower_bound(all(X), c) - begin(X);
            // cerr << "Q[" << i << "]";
            // cerr << " | " << l << " - " << cl << " : " << calc_sum(cr, r) - (r - cr) * c;
            // cerr << " | " << cr << " - " << r << " : " << (cl - l) * c - calc_sum(l, cl);
            // cerr << " | ol " << N - (r - l) << endl;
            ll ans = 0;
            ans += calc_sum(cr, r) - (r - cr) * c;
            ans += (cl - l) * c - calc_sum(l, cl);
            ans += (N - (r - l)) * d;
            cout << ans << endl;
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

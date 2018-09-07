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
template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }
template<class T> ostream& operator << (ostream &os , const vector<T> &v) { for(const T &t : v) os << "\t" << t; return os << endl; }
// pair
template<class T, class U> ostream& operator << (ostream &os , const pair<T, U> &v) { return os << "<" << v.first << ", " << v.second << ">"; }

const int INF = 1 << 30;
const ll INFL = 1LL << 60;


class Solver {
  public:
    bool solve() {
        ll N, C; cin >> N >> C;

        vector<ll> X(N), V(N);
        rep(i, N) cin >> X[i] >> V[i];

        vector<ll> left(N + 1);
        vector<ll> right(N + 1);
        vector<ll> max_l(N + 1), max_r(N + 1);
        rep(i, N) {
            right[i + 1] = right[i] + V[i] - X[i] + (i > 0 ? X[i - 1] : 0);
            left[i + 1] = left[i] + V[N - i - 1] - (C - X[N - i - 1]) + (i > 0 ? C - X[N - i] : 0);
            max_l[i + 1] = max(max_l[i], left[i + 1]);
            max_r[i + 1] = max(max_r[i], right[i + 1]);
        }

        ll ans = max(max_l[N], max_r[N]);
        rep(i, N) {
            set_max(ans, max_l[N - i - 1] + right[i + 1] - X[i]);
            set_max(ans, max_r[N - i - 1] + left[i + 1] - (C - X[N - i - 1]));
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

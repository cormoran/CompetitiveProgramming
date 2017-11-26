#include <bits/stdc++.h>
using namespace std;


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
        ll X, Y, Z; cin >> X >> Y >> Z;
        ll N = X + Y + Z;
        vector<tuple<ll, ll, ll>> coin(N);
        rep(i, N) {
            auto &c = coin[i];
            cin >> get<0>(c) >> get<1>(c) >> get<2>(c);
        }
        sort(all(coin), [] (tuple<ll, ll, ll> &a, tuple<ll, ll, ll> &b) {
                return get<0>(a) - get<1>(a) < get<0>(b) - get<1>(b);
            });

        priority_queue<pll> que_l, que_r;

        vector<ll> sum_l(N), sum_r(N);

        rep(i, Y + Z) {
            if(i > 0) sum_l[i] = sum_l[i - 1];
            sum_l[i] += get<1>(coin[i]);      
            ll diff = get<2>(coin[i]) - get<1>(coin[i]);
            que_l.push(make_pair(diff, i));
            if(que_l.size() > Y) {
                pll now = que_l.top(); que_l.pop();
                sum_l[i] -= get<1>(coin[now.second]);
                sum_l[i] += get<2>(coin[now.second]);
            }
        }
        reverse(all(coin));
        rep(i, X + Z) {
            if(i > 0) sum_r[i] = sum_r[i - 1];
            sum_r[i] += get<0>(coin[i]);      
            ll diff = get<2>(coin[i]) - get<0>(coin[i]);
            que_r.push(make_pair(diff, i));
            if(que_r.size() > X) {
                pll now = que_r.top(); que_r.pop();
                sum_r[i] -= get<0>(coin[now.second]);
                sum_r[i] += get<2>(coin[now.second]);
            }
        }

        ll ans = -INF;
        repeat(k, Y - 1, Y + Z) {
            set_max(ans, sum_l[k] + sum_r[N - (k + 1) - 1]);
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

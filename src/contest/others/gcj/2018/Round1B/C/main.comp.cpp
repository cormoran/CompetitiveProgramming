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
        int T; cin >> T;
        rep(t, T) {
            int M; cin >> M;
            vector<pii> R(M);
            rep(i, M) {
                cin >> R[i].first >> R[i].second;
                R[i].first--;
                R[i].second--;
            }
            vector<ll> G(M); cin >> G;

            auto check = [&] (ll x) {
                vector<ll> GG = G;
                vector<int> fail_visited(M);
                function<bool(int, ll)> dfs = [&] (int now, ll need) {
                    if(fail_visited[now]) return false;
                    if(GG[now] >= need) {
                        GG[now] -= need;
                        return true;
                    }
                    ll left = GG[now];
                    GG[now] = 0;
                    fail_visited[now] = true;
                    bool res = dfs(R[now].first, need - left) and dfs(R[now].second, need - left);
                    if(res) fail_visited[now] = false;
                    return res;
                };
                ll a = GG[0];
                GG[0] = 0;
                return a >= x or dfs(0, x - a);
            };

            ll l = 0, r = accumulate(all(G), 0LL) + 100;
            while(l + 1 < r) {
                ll m = (l + r) / 2;
                (check(m) ? l : r) = m;
            }
            ll ans = l;
            cout << "Case #" << t + 1 << ": " << ans << endl;
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

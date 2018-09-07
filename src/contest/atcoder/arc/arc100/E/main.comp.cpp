#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define all(v) v.begin(),v.end()
template<class T> bool set_max(T &a, const T &b) { return a < b  ? a = b, true : false; }
// vector
template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }

class Solver {
  public:
    bool solve() {
        int N; cin >> N;
        vector<ll> A(1 << N); cin >> A;

        vector<pii> g(1 << N);
        rep(k, g.size()) g[k] = pii(k, -1);

        auto f = [&] (pii a, pii b) {
            vector<int> x = {a.first, a.second, b.first, b.second};
            sort(all(x)); x.erase(unique(all(x)), x.end());
            sort(all(x), [&] (int i, int j) { return i >= 0 and j >= 0 ? A[i] > A[j] : i > j; });
            return pii(x[0], x[1]);
        };
        // ref: http://d.hatena.ne.jp/todo314/20120614/1339695202
        rep(i, N) {
            rep(s, 1 << N) { // s is K
                if(s & (1 << i)) {
                    g[s] = f(g[s], g[s^(1 << i)]);
                }
            }
        }

        auto sum = [&] (pii p) { assert(p.first >= 0 and p.second >= 0); return A[p.first] + A[p.second]; };
        ll ans = sum(g[1]);
        rep(i, (1 << N) - 1) {
            set_max(ans, sum(g[i + 1]));
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

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define all(v) v.begin(),v.end()

template<class T> bool set_max(T &a, T b) { return a < b  ? a = b, true : false; }
template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }
class Solver {
  public:
    bool solve() {
        int G; cin >> G;
        rep(g, G) {
            int n, m, x; cin >> n >> m >> x;
            vector<ll> a(n), b(m); cin >> a >> b;
            rep(i, n - 1) a[i + 1] += a[i];
            rep(i, m - 1) b[i + 1] += b[i];
            int ans = 0;
            rep(i, n) {
                ll v = x - a[i];
                if(v >= 0) set_max(ans, i + 1);
                auto pos = upper_bound(all(b), v);
                if(pos == begin(b)) continue;
                pos--;
                if(*pos <= v) set_max<int>(ans, (i + 1) + (pos - begin(b)) + 1);
            }
            rep(i, m) {
                ll v = x - b[i];
                if(v >= 0) set_max(ans, i + 1);
                auto pos = upper_bound(all(a), v);
                if(pos == begin(a)) continue;
                pos--;
                if(*pos <= v) set_max<int>(ans, (i + 1) + (pos - begin(a)) + 1);
            }
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

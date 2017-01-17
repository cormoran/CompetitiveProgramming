#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define all(v) v.begin(),v.end()

template<class T> bool set_min(T &a, const T &b) { if(a > b) a = b; return a > b; }
template<class T> bool set_max(T &a, const T &b) { if(a < b) a = b; return a < b; }
// vector
template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }

class Solver {
  public:
    vector<pll> A;    
    ll calc(ll t) {
        ll mx = 0;
        ll mn = 1e18;
        for(pll &a : A) {
            set_max(mx, a.first + a.second * t);
            set_min(mn, a.first + a.second * t);
        }
        cerr << t << " " << mx - mn << endl;
        return mx - mn;
    }
    
    bool solve() {
        int N; cin >> N;
        A.resize(N);
        for(auto &a : A) cin >> a.first >> a.second;

        ll mx = 0;
        for(auto &a : A) set_max(mx, a.first);
        
        ll l = 1, r = mx;
        while(l + 1 < r) {
            ll a = (l + r) / 2;
            if(calc(a) > calc(a + 1)) l = a;
            else r = a;
        }
        if(r < l) swap(l, r);
        cout << max(1LL, calc(l) <= calc(r) ? l : r) << endl;
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

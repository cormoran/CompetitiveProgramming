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
        int H, W; cin >> H >> W;
        if(H < W) swap(H, W);
        if(H % 3 == 0 or W % 3 == 0) {
            cout << 0 << endl;
        } else {
            ll ans = 1LL << 60;            
            repeat(i, 1, W) {
                ll a = (ll)H * i;
                ll b = (ll)(W - i) * (H / 2);
                ll c = (ll)(W - i) * (H / 2 + H % 2);
                ll mn = min({a, b, c});
                ll mx = max({a, b, c});
                set_min(ans, mx - mn);
            }

            if(H > 3) {
                ll a = (ll)(H / 3) * W;
                ll b = (ll)(H / 3 + (H % 3 >= 2)) * W;
                ll c = (ll)(H / 3 + (H % 3 >= 1)) * W;
                ll mn = min({a, b, c});
                ll mx = max({a, b, c});
                set_min(ans, mx - mn);
            }
            
            swap(H, W);
            repeat(i, 1, W) {
                ll a = (ll)H * i;
                ll b = (ll)(W - i) * (H / 2);
                ll c = (ll)(W - i) * (H / 2 + H % 2);
                ll mn = min({a, b, c});
                ll mx = max({a, b, c});
                set_min(ans, mx - mn);
            }

            if(H > 3) {
                ll a = (ll)(H / 3) * W;
                ll b = (ll)(H / 3 + (H % 3 >= 2)) * W;
                ll c = (ll)(H / 3 + (H % 3 >= 1)) * W;
                ll mn = min({a, b, c});
                ll mx = max({a, b, c});
                set_min(ans, mx - mn);
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

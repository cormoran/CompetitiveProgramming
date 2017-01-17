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
        ll H, W, N; cin >> H >> W >> N;
        map<pii, int> rect;
        rep(i, N) {
            int x, y; cin >> y >> x;
            x--; y--;
            for(int dy = -2; dy <= 0; dy++) {
                for(int dx = -2; dx <= 0; dx++) {
                    int lx = x + dx;
                    int ly = y + dy;
                    int rx = lx + 2;
                    int ry = ly + 2;
                    if(0 <= lx and lx < W and 0 <= ly and ly < H) {
                        if(0 <= rx and rx < W and 0 <= ry and ry < H) {
                            rect[make_pair(ly, lx)] += 1;
                        }
                    }
                }
            }            
        }
        vector<ll> ans(10);
        ll zero = (H - 2) * (W - 2);
        for(auto p : rect) {
            ans[p.second] += 1;
            zero -= 1;
        }
        ans[0] = zero;
        for(auto a : ans) cout << a << endl;
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

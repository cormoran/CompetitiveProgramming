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
        int N, K; cin >> N >> K;
        vector<vector<ll>> G(1001, vector<ll>(1001, 0));
        vector<int> X(N), Y(N), HP(N);
        rep(i, N) {
            cin >> X[i] >> Y[i] >> HP[i];
            X[i] += 500;
            Y[i] += 500;
            assert(0 <= X[i] and X[i] <= 1000);
            assert(0 <= Y[i] and Y[i] <= 1000);
        }

        rep(i, K) {
            int ax, ay, w, h, d; cin >> ax >> ay >> w >> h >> d;            
            ax += 500;
            ay += 500;
            G[ay][ax] += d;
            int ex = ax + w + 1;
            int ey = ay + h + 1;
            if(ex <= 1000) G[ay][ex] -= d;
            if(ey <= 1000) G[ey][ax] -= d;
            if(ex <= 1000 and ey <= 1000) G[ey][ex] += d;
        }

        rep(y, 1001) rep(x, 1001 -1) G[y][x + 1] += G[y][x];
        rep(x, 1001) rep(y, 1001 - 1) G[y + 1][x] += G[y][x];

        ll ans = 0;
        rep(i, N) {
            ans += max(0LL, HP[i] - G[Y[i]][X[i]]);
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

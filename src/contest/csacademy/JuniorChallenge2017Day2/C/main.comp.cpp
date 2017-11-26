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
        int N, M; cin >> M >> N;
        vector<string> G(M); cin >> G;
        rep(i, M) rep(j, N) G[i][j] -= '0';
        vector<vector<int>> HG(M, vector<int>(N));
        vector<vector<int>> WG = HG, DG = HG;

        rep(y, M) {
            rep(x, N) {
                if(x > 0 and G[y][x]) WG[y][x] += WG[y][x - 1];
                WG[y][x] += G[y][x] == 1;                
            }
        }
        rep(x, N) {
            rep(y, M) {
                if(y > 0 and G[y][x]) HG[y][x] += HG[y - 1][x];
                HG[y][x] += G[y][x] == 1;
            }
        }
        for(int xx = N - 1; xx >= 0; xx--) {
            int x = xx;
            int y = 0;
            int prev = 0;
            while(x < N and y < M) {
                if(G[y][x]) DG[y][x] = prev + 1;
                prev = DG[y][x];
                x++; y++;
            }
        }
        repeat(yy, 1, M) {
            int x = 0;
            int y = yy;
            int prev = 0;
            while(x < N and y < M) {
                if(G[y][x]) DG[y][x] = prev + 1;
                prev = DG[y][x];
                x++; y++;
            }
        }
        // debug(HG);
        // debug(WG);
        // debug(DG);
        vector<int> squares;
        int ans = 0;
        rep(y, M) {
            rep(x, N) {
                repeat(l, 1, min(N, M) + 1) {
                    int ex = x + l - 1;
                    int ey = y + l - 1;
                    if(ex < N and ey < M) {
                        bool ok = HG[ey][x] >= l and HG[ey][ex] >= l and WG[y][ex] >= l and WG[ey][ex] >= l and DG[ey][ex] >= l;
                        ans += ok;
                        //if(ok) cerr << y << " " << x << " " << l << endl;
                    }
                }
            }
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

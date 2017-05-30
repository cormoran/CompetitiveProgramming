#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;
using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define repeat(i, j, k) for(int i = (j); i < (int)(k); i++)

template<class T> bool set_min(T &a, const T &b) { return a > b  ? a = b, true : false; }
template<class T> bool set_max(T &a, const T &b) { return a < b  ? a = b, true : false; }
template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }

const int INF = 1 << 30;
const ll INFL = 1LL << 60;


int dp2[101][101][2], dp3[101][101][101][3], dp4[101][101][101][101][4];

class Solver {
  public:
    map<vector<int>, vector<int>> memo;
    int rec(vector<int> gp, int left) {
        int P = gp.size();
        int ans = 0;
        if(P == 2 and dp2[gp[0]][gp[1]][left] >= 0) return dp2[gp[0]][gp[1]][left];
        if(P == 3 and dp3[gp[0]][gp[1]][gp[2]][left] >= 0) return dp3[gp[0]][gp[1]][gp[2]][left];
        if(P == 4 and dp4[gp[0]][gp[1]][gp[2]][gp[3]][left] >= 0) return dp4[gp[0]][gp[1]][gp[2]][gp[3]][left];
        rep(i, P) {
            if(gp[i] == 0) continue;
            gp[i]--;
            set_max(ans, rec(gp, (left + P - i) % P) + (left == 0));
            gp[i]++;
        }
        if(P == 2) return dp2[gp[0]][gp[1]][left] = ans;
        if(P == 3) return dp3[gp[0]][gp[1]][gp[2]][left] = ans;
        if(P == 4) return dp4[gp[0]][gp[1]][gp[2]][gp[3]][left] = ans;
        return ans;
    }
    
    bool solve() {
        int T; cin >> T;
        rep(t, T) {
            rep(i, 101) rep(j, 101) {
                rep(k, 2) dp2[i][j][k] = -INF;
                rep(k, 101) {
                    rep(l, 3) dp3[i][j][k][l] = -INF;
                    rep(l, 101) {
                        rep(m, 4) dp4[i][j][k][l][m] = -INF;
                    }
                }
            }                    
            int N, P; cin >> N >> P;
            vector<int> G(N); cin >> G;
            vector<int> gp(P);
            rep(i, N) {
                gp[G[i] % P]++;
            }
            cout << "Case #" << t + 1 << ": " << rec(gp, 0) << endl;
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

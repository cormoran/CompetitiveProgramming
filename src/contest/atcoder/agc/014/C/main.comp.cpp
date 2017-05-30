#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)

template<class T> bool set_min(T &a, const T &b) { return a > b  ? a = b, true : false; }
// vector
template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }
const int INF = 1 << 30;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

class Solver {
  public:
    bool solve() {
        int H, W, K; cin >> H >> W >> K;
        vector<string> G(H); cin >> G;

        int sx = -1, sy = -1;
        rep(i, H) rep(j, W) if(G[i][j] == 'S') {
            sy = i;
            sx = j;
            goto OK;
        }
  OK:
        assert(sx >= 0 and sy >= 0);
        
        auto eval = [&](pii p) {
            return min({p.first, H - p.first - 1, p.second, W - p.second - 1});
        };
        auto div = [&](int a) {
            return a / K + (a % K != 0);
        };
        auto calc_cost = [&] (pii pos, int c) -> int {
            return div(eval(pos)) + div(c) + (pos.first == sy and pos.second == sx);
        };

        vector<vector<int>> G2(H, vector<int>(W, INF));        
        queue<pii> que;
        que.push(make_pair(sy, sx));
        G2[sy][sx] = 0;
        int ans = INF;       
        while(que.size() > 0) {            
            pii now = que.front(); que.pop();
            int cost = G2[now.first][now.second];
            set_min(ans, calc_cost(now, cost));
            rep(i, 4) {
                int nx = now.second + dx[i], ny = now.first + dy[i];
                if(0 <= ny and ny < H and 0 <= nx and nx < W) {
                    if(G2[ny][nx] == INF and G[ny][nx] == '.') {                        
                        que.push(make_pair(ny, nx));
                        G2[ny][nx] = cost + 1;
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

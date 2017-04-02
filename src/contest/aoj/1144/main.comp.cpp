#include <bits/stdc++.h>
using namespace std;

#define rep(i, j) for(int i=0; i < (int)(j); i++)
template<class T> bool set_min(T &a, const T &b) { return a > b  ? a = b, true : false; }
template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }

const int INF = 1 << 30;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

enum block {
    EMPTY = 0,
    OBSTACLE,
    START,
    GOAL
};

class Solver {
  public:
    int H, W;
    tuple<int, int> go(int y, int x, vector<vector<int>> &G, int dir) {
        bool moved = false;
        while(true) {
            int ny = y + dy[dir], nx = x + dx[dir];
            if(ny < 0 or H <= ny or nx < 0 or W <= nx) return make_tuple(ny, nx);
            if(G[ny][nx] == GOAL) return make_tuple(ny, nx);
            if(G[ny][nx] == OBSTACLE) {
                if(not moved) return make_tuple(-1, -1); // (y, x)の隣が岩で動けない                
                G[ny][nx] = EMPTY;
                return make_tuple(y, x);
            }            
            y = ny;
            x = nx;
            moved = true;
        }
    }
    int dfs(int y, int x, vector<vector<int>> G, int depth) {
        if(depth > 10) return INF;
        int res = INF;
        rep(dir, 4) {
            int ny, nx;
            auto GG = G;
            tie(ny, nx) = go(y, x, GG, dir);
            if(ny < 0 or H <= ny or nx < 0 or W <= nx) continue;
            if(GG[ny][nx] == GOAL) return depth;
            set_min(res, dfs(ny, nx, GG, depth + 1));
        }
        return res;
    }
    
    bool solve() {
        cin >> W >> H;
        if(not W and not H) return false;
        vector<vector<int>> G(H, vector<int>(W));
        rep(i, H) cin >> G[i];

        int x, y;
        rep(yy, H) rep(xx, W) if(G[yy][xx] == START) {
            y = yy;
            x = xx;
            break;
        }

        int ans = dfs(y, x, G, 1);
        cout << (ans == INF ? -1 : ans) << endl;
        
        return true;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(true) {
        Solver s;
        if(not s.solve()) break;
    }
    return 0;
}

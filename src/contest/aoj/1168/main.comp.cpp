#include<iostream>
#include<vector>
#include<cassert>
#include<string>
#include<algorithm>
#include<queue>
#include<set>
using namespace std;

using pii = pair<int,int>;
#define rep(i, j) for(int i=0; i < (int)(j); i++)

// vector
template<class T> istream& operator >> (istream &is , vector<T> &v) {
    for(T &a : v) is >> a; return is;
}

using pdd = pair<double, double>;
#define mp(x, y) make_pair(x, y)
#define Y first
#define X second
const int INF = 1 << 30;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0};

// (x, y)のピースの安定性を判定し、(重心位置, 重さ), を返す
// 不安定なら 重さ = 0 で返す
pair<pdd, int> rec(vector<string> &G, int y, int x) {
    int W = G[0].size(), H = G.size();
    vector<pair<pdd, int>> grav;
    char c = G[y][x];
    set<pii> visited;
    
    queue<pii> q;
    q.push(mp(y, x));
    int xl = INF, xr = -INF;
    while(!q.empty()) {
        pii now = q.front(); q.pop();
        if(G[now.Y][now.X] != c) continue;
        G[now.Y][now.X] = '*';
        visited.insert(now);
        grav.push_back(mp(mp(now.Y + 0.5, now.X + 0.5), 1));

        char down = now.Y == H - 1 ? '*' : G[now.Y + 1][now.X];
        if(not visited.count(mp(now.Y + 1, now.X))
           and down != c and (down == '*' or isdigit(down))) {
            xl = min(xl, now.X);
            xr = max(xr, now.X + 1);
        }
        
        rep(i, 4) {
            int nx = now.X + dx[i];
            int ny = now.Y + dy[i];
            if(nx < 0 or W <= nx or ny < 0 or H <= ny) continue;
            if(G[ny][nx] == c) {
                q.push(mp(ny, nx));
            } else if(i == 0 and isdigit(G[ny][nx])) {
                // 上のピース
                auto ret = rec(G, ny, nx);
                if(ret.second == 0) return mp(mp(0.0, 0.0), 0);
                grav.push_back(ret);
            }
        }        
    }
    // 重心計算
    int sum = 0;
    double xg = 0, yg = 0;
    rep(i, grav.size()) {
        sum += grav[i].second;
        xg += grav[i].second * grav[i].first.X;
        yg += grav[i].second * grav[i].first.Y;
    }

    xg /= sum;
    yg /= sum;

    return ((xl < xg and xg < xr) ? mp(mp(yg, xg), sum) : mp(mp(0.0, 0.0), 0));
}

bool solve() {
    int W, H; cin >> W >> H;
    if(W == 0 and H == 0) return 0;
    vector<string> G(H); cin >> G;
    
    rep(i, W) if(isdigit(G[H - 1][i])) {
        cout << (rec(G, H - 1, i).second > 0 ? "STABLE" : "UNSTABLE") << endl;
        return 1;
    }

    assert(0);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
